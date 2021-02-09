/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:04:46 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/19 09:24:19 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double		get_discr_cone(t_data *data,
		t_ray ray, t_vector to_cone, int h)
{
	double			a;
	double			b;
	double			c;
	t_vector		axis;
	double			angle;

	angle = data->cone->angle[h];
	axis = data->cone->axis[h];
	a = vectordot(ray.target, ray.target) - (1 + angle * angle) *
		vectordot(ray.target, axis) * vectordot(ray.target, axis);
	b = 2.0 * (vectordot(ray.target, to_cone) - (1 + angle * angle) *
			vectordot(ray.target, axis) * vectordot(to_cone, axis));
	c = vectordot(to_cone, to_cone) - (1 + angle * angle) *
		vectordot(to_cone, axis) * vectordot(to_cone, axis);
	data->hit.a = a;
	data->hit.b = b;
	return (b * b - 4 * a * c);
}

t_vector			new_start_dir_cone(t_data *data, t_ray *ray)
{
	double			m;
	t_vector		n;
	double			angle;
	t_vector		axis;

	angle = data->cone->angle[data->hit.obj_idx];
	axis = data->cone->axis[data->hit.obj_idx];
	ray->newstart = vectoradd(ray->start,
			vectorscale(data->hit.t, ray->target));
	m = vectordot(ray->target, axis) * data->hit.t
		+ vectordot(vector_minus(ray->start,
					data->cone->start_xyz[data->hit.obj_idx]), axis);
	n = vectorscale((1 + angle * angle), vectorscale(m, axis));
	n = normalized_vector(vector_minus(vector_minus(ray->newstart,
					data->cone->start_xyz[data->hit.obj_idx]), n));
	if (vectordot(ray->target, n) > 0.0001)
		n = vectorscale(-1, n);
	return (n);
}

int					intersectcone(t_ray ray, t_data *data, int h)
{
	t_vector		to_cone;
	t_vector		pos;
	double			discr;
	double			t[2];

	pos = vector_copy(data->cone->start_xyz[h]);
	to_cone = vector_minus(ray.start, pos);
	discr = get_discr_cone(data, ray, to_cone, h);
	if (discr < 0)
		return (0);
	else
	{
		t[0] = (-data->hit.b + (sqrt(discr))) / (2 * data->hit.a);
		t[1] = (-data->hit.b - (sqrt(discr))) / (2 * data->hit.a);
		if (t[0] > t[1])
			t[0] = t[1];
		if ((t[0] > 0.001f) && (t[0] < data->hit.t))
		{
			data->hit.t = t[0];
			return (1);
		}
		return (0);
	}
}
