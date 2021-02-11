/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:37:25 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:38:32 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double		get_ior(double scale)
{
	double			ior;

	ior = (1 + (scale * 0.05));
	if (ior == 1)
		return (1.01);
	return (ior);
}

static double		fresnel_result(double etat, double etai,
double cosi, double cost)
{
	return ((((etat * cosi) - (etai * cost))
					/ ((etat * cosi) + (etai * cost)) *
					((etat * cosi) - (etai * cost))
					/ ((etat * cosi) + (etai * cost)) +
					((etai * cosi) - (etat * cost))
					/ ((etai * cosi) + (etat * cost)) *
					((etai * cosi) - (etat * cost))
					/ ((etai * cosi) + (etat * cost))) / 2);
}

static double		calc_fresnel(t_vector normal, t_vector target, double ior)
{
	double			etai;
	double			etat;
	double			cosi;
	double			cost;
	double			sint;

	etai = 1;
	etat = ior;
	cosi = ft_dclamp(-1, 1, (vectordot(target, normal)));
	if (cosi > 0)
		ft_dswap(&etai, &etat);
	sint = etai / etat * sqrtf(ft_dmax(0.0f, 1 - cosi * cosi));
	if (sint >= 1)
		return (1);
	else
	{
		cost = sqrtf(ft_dmax(0.f, 1 - sint * sint));
		cosi = ft_fabs(cosi);
		return (fresnel_result(etat, etai, cosi, cost));
	}
}

static t_vector		refract_dir(t_vector target, t_vector n, double ior)
{
	double			etai;
	double			etat;
	double			eta;
	double			cosi;
	double			k;

	etai = 1;
	etat = ior;
	cosi = ft_dclamp(-1, 1, vectordot(target, n));
	if (cosi < 0)
		cosi = cosi * -1;
	else
	{
		ft_dswap(&etai, &etat);
		reverse_vector(n);
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - cosi * cosi);
	if (k < 0)
		target = vectornew(0, 0, 0);
	else
		target = vectoradd(vectorscale(eta, target),
				vectorscale((eta * cosi - sqrtf(k)), n));
	return (normalized_vector(target));
}

t_ray				reflection_dir(t_ray ray, t_vector n, t_data *data)
{
	double			r_factor;

	data->hit.org_start = vector_copy(ray.start);
	data->hit.org_target = vector_copy(ray.target);
	ray.start = vector_copy(ray.newstart);
	data->hit.fresnel = calc_fresnel(n, ray.target,
			get_ior(data->hit.texture.scale));
	if (data->hit.refract == TRUE && data->hit.fresnel < 1)
	{
		ray.target = refract_dir(ray.target, n,
		get_ior(data->hit.texture.scale));
		data->hit.refract = FALSE;
		data->hit.was_refract = TRUE;
		data->hit.org_normal = normalized_vector(data->hit.org_normal);
	}
	else
	{
		r_factor = ft_fabs(data->scene->reflection - 9.5);
		ray.target = vector_minus(ray.target,
		vectorscale(r_factor * vectordot(ray.target, n), n));
		if (data->hit.was_refract == 1)
			data->hit.was_refract = FALSE;
	}
	data->hit.fresnel = 1 - data->hit.fresnel;
	return (ray);
}
