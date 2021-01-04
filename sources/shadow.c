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

#include "rtv1.h"
#include "../libft/libft.h"

static int	search_shadow_intersection(t_data *data, t_ray ray, int i)
{
	while (i >= 0)
	{
		data->hit.find_shadow = 1;
		if (data->sphere->nbr > i && (intersectsphere(ray, data, i) == 1))
		{
			if (data->hit.t <= vector_length(vector_minus(
							ray.target, ray.start)) + 0.001f)
				return (1);
		}
		if (data->cone->nbr > i && (intersectcone(ray, data, i) == 1))
		{
			if (data->hit.t <= vector_length(vector_minus(
							ray.target, ray.start)) + 0.001f)
				return (1);
		}
		if (data->cylinder->nbr > i && (intersectcylinder(ray, data, i) == 1))
		{
			if (data->hit.t <= vector_length(vector_minus(
							ray.target, ray.start)) + 0.001f)
				return (1);
		}
		i--;
	}
	return (0);
}

int			shadow(t_data *data, t_vector newstart, int j)
{
	t_ray ray;

	ray.target = vectornew(data->spot->x[j], data->spot->y[j],
			data->spot->z[j]);
	ray.start = vector_copy(newstart);
	if (search_shadow_intersection(data, ray, data->objnbr - 1))
		return (1);
	else
		return (0);
}
