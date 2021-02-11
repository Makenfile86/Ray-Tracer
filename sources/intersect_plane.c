/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:30:26 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:33:59 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector				new_start_dir_plane(t_data *data, t_ray *ray)
{
	t_vector			scaled;
	t_vector			n;
	int					i;

	i = data->hit.obj_idx;
	scaled = vectorscale(data->hit.t, ray->target);
	ray->newstart = vectoradd(ray->start, scaled);
	if (vectordot(ray->target, data->plane->normal[i]) < 0)
		n = data->plane->normal[i];
	else
		n = vectorscale(-1, data->plane->normal[i]);
	data->hit.point = vector_copy(ray->newstart);
	data->hit.normal = data->plane->normal[i];
	return (n);
}

static int				get_disc_ring(t_data *data, t_ray ray, int h, double t)
{
	if (vector_length(vector_minus(vectoradd(ray.start,
						vectorscale(t, ray.target)), data->plane->xyz[h])) >
			(double)data->plane->radius[h])
		return (0);
	if (data->plane->ring[h] > 0.9)
	{
		if (vector_length(vector_minus(vectoradd(ray.start,
							vectorscale(t, ray.target)), data->plane->xyz[h]))
				< ((double)data->plane->radius[h] / (data->plane->radius[h]
						/ (data->plane->ring[h] * 4))))
			return (0);
	}
	return (1);
}

int						intersectplane(t_data *data, int h, t_ray ray)
{
	double				dot;
	double				t1;

	dot = vectordot(ray.target, data->plane->normal[h]);
	if (dot == 0)
		return (0);
	t1 = vectordot(vector_minus(data->plane->xyz[h], ray.start),
			data->plane->normal[h]) / dot;
	if (t1 < 0.001 || t1 > 9999999)
		return (0);
	if (data->plane->radius > 0)
		if (!(get_disc_ring(data, ray, h, t1)))
			return (0);
	if (t1 < data->hit.t)
	{
		data->hit.t = t1;
		return (1);
	}
	return (0);
}
