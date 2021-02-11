/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:31:45 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:37:14 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray			shadow_ray(double *t, t_hit hit, t_ray ray, char *obj_name)
{
	t_vector temp;

	if ((ft_strcmp(obj_name, "model") == 0))
	{
		*t = 1000;
		temp = vectorscale(0.00001, hit.normal);
		ray.start = vectoradd(hit.point, temp);
		ray.target = vector_minus(ray.target, ray.start);
		ray.target = normalized_vector(ray.target);
		return (ray);
	}
	*t = 1000;
	ray.target = vector_minus(ray.target, ray.start);
	ray.target = normalized_vector(ray.target);
	return (ray);
}

static int		hit_dist(double t, t_ray ray, int mater)
{
	if (t <= vector_length(vector_minus(
					ray.target, ray.start)) + 0.001f && mater != 3)
		return (1);
	return (0);
}

static int		triangle_shadow(t_data *data, int i, t_ray ray)
{
	int y;

	y = (data->modelnbr - 1);
	while (y >= 0)
	{
		if ((int)data->obj[y].num_polygonals > i && intersecttriangle(
					shadow_ray(&data->hit.t, data->hit, ray, "model"),
					data, y, i) == 1)
		{
			if (hit_dist(data->hit.t, ray, 1))
				return (1);
		}
		y--;
	}
	return (0);
}

static int		search_shadow_intersection(t_data *data, t_ray ray, int i)
{
	while (i >= 0)
	{
		if (data->sphere->nbr > i && (intersectsphere(shadow_ray(
			&data->hit.t, data->hit, ray, "sphere"), data, i)))
		{
			if (hit_dist(data->hit.t, ray, data->sphere->mater[i]))
				return (1);
		}
		if (data->cone->nbr > i && (intersectcone(shadow_ray(
			&data->hit.t, data->hit, ray, "cone"), data, i)))
		{
			if (hit_dist(data->hit.t, ray, data->cone->mater[i]))
				return (1);
		}
		if (data->cylinder->nbr > i && (intersectcylinder(shadow_ray(
			&data->hit.t, data->hit, ray, "cylinder"), data, i)))
		{
			if (hit_dist(data->hit.t, ray, data->cylinder->mater[i]))
				return (1);
		}
		if ((triangle_shadow(data, i, ray) == 1))
			return (1);
		i--;
	}
	return (0);
}

int				shadow(t_data *data, t_vector newstart, int j)
{
	t_ray	ray;

	ray.target = vectornew(data->spot->x[j], data->spot->y[j],
			data->spot->z[j]);
	ray.start = vector_copy(newstart);
	data->hit.find_shadow = TRUE;
	if (search_shadow_intersection(data, ray, data->objnbr - 1))
		return (1);
	else
		return (0);
}
