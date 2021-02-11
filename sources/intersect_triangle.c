/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:06:18 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/19 09:29:25 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector				new_start_dir_triangle(t_data *data, t_ray *ray)
{
	t_vector			n;
	t_vector			temp;

	temp = vectorscale(0.00001, data->hit.normal);
	ray->newstart = vectoradd(data->hit.point, temp);
	if (vectordot(ray->target, data->hit.normal) < 0)
		n = data->hit.normal;
	else
		n = vectorscale(-1, data->hit.normal);
	return (n);
}

static int				in_out_test(t_vector normal, t_vector *te,
		t_vector point, t_vector *ve)
{
	t_vector			abc[3];

	abc[0] = vectorsub(point, ve[0]);
	abc[1] = vectorsub(point, ve[1]);
	abc[2] = vectorsub(point, ve[2]);
	if (vectordot(normal, cross_vector(te[0], abc[0])) >= 0 &&
			vectordot(normal, cross_vector(te[1], abc[1])) >= 0 &&
			vectordot(normal, cross_vector(te[2], abc[2])) >= 0)
		return (1);
	return (0);
}

int						intersecttriangle(t_ray ray, t_data *data, int y, int h)
{
	double				t;
	double				discr;

	discr = vectordot(data->obj[y].polygonals[h].normal, ray.target);
	if (ft_fabs(discr) < 0.00001)
		return (0);
	t = vectordot(vectorsub(data->obj[y].polygonals[h].ve[0], ray.start),
			data->obj[y].polygonals[h].normal) / discr;
	if (t < 0.00001 || t > 1000)
		return (0);
	if (in_out_test(data->obj[y].polygonals[h].normal,
	data->obj[y].polygonals[h].te, vectoradd(ray.start,
	vectorscale(t, ray.target)), data->obj[y].polygonals[h].ve))
	{
		if (t < data->hit.t)
		{
			data->hit.t = t;
			data->hit.normal = data->obj[y].polygonals[h].normal;
			if (data->hit.find_shadow == FALSE)
				data->hit.point = vectoradd(ray.start, vectorscale(t,
							ray.target));
			return (1);
		}
	}
	return (0);
}
