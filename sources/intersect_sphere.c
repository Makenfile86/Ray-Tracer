/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:06:18 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/19 09:29:25 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "../libft/libft.h"

static double		get_discr_sphere(t_data *data, t_ray ray, int h)
{
	double		b;
	double		c;
	double		a;
	t_vector	dist;

	a = vectordot(ray.target, ray.target);
	dist = vector_minus(ray.start, data->sphere->xyz[h]);
	b = 2 * vectordot(ray.target, dist);
	c = (vectordot(dist, dist)) - data->sphere->radius[h] *
		data->sphere->radius[h];
	data->hit.a = a;
	data->hit.b = b;
	return (b * b - 4 * a * c);
}

t_vector			new_start_dir_sphere(t_data *data, t_ray *ray)
{
	t_vector	n;
	t_vector	scaled;

	scaled = vectorscale(data->hit.t, ray->target);
	ray->newstart = vectoradd(ray->start, scaled);
	n = vector_minus(ray->newstart, data->sphere->xyz[data->hit.obj_idx]);
	//data->hit.org_start = vector_copy(ray->newstart);
	//data->tmp_x = ray->newstart.x;
	//data->tmp_y = ray->newstart.y;
	//data->tmp_z = ray->newstart.z;
	return (n);
}

static t_ray		update_ray(t_data *data, t_ray ray)
{
	data->hit.t = 1000 ;
	ray.target = vector_minus(ray.target, ray.start);
	ray.target = normalized_vector(ray.target);
	return (ray);
}

int					intersectsphere(t_ray ray, t_data *data, int h)
{
	double		discr;
	double		sqrtdiscr;
	double		t[2];

	if (data->hit.find_shadow == 1)
		ray = update_ray(data, ray);
	
	discr = get_discr_sphere(data, ray, h);
	if (discr < 0)
		return (0);
	else
	{
		sqrtdiscr = sqrt(discr);
		t[0] = (-data->hit.b + sqrtdiscr) / (2 * data->hit.a);
		t[1] = (-data->hit.b - sqrtdiscr) / (2 * data->hit.a);
		if (t[0] > t[1])
			t[0] = t[1];
		if ((t[0] > 0.001f) && (t[0] < data->hit.t))
		{
			if (data->sphere->mater[h] == 3)
			{
				data->hit.refract = 1;
				if (t[0] < data->hit.refract_lent)
				data->hit.refract_lent = t[0];
				return (0);
			}
			else
			{
			data->hit.t = t[0];
			//ft_putendl("ei pitais olla");
			}
			return (1);
		}
		return (0);
	}
}