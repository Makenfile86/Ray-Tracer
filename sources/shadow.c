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


static int	search_shadow_intersection(t_data *data, t_ray ray, int i)
{
	int y;
	while (i >= 0)
	{
		data->hit.find_shadow = 1;
		y = (data->modelnbr - 1);
		if (data->sphere->nbr > i && (intersectsphere(ray, data, i) == 1))
		{
			if (data->hit.t <= vector_length(vector_minus(
							ray.target, ray.start)) + 0.001f && data->sphere->mater[i] != 3)
				return (1);
		}
		if (data->cone->nbr > i && (intersectcone(ray, data, i) == 1))
		{
			if (data->hit.t <= vector_length(vector_minus(
							ray.target, ray.start)) + 0.001f && data->cone->mater[i] != 3)
				return (1);
		}
		if (data->cylinder->nbr > i && (intersectcylinder(ray, data, i) == 1))
		{
			if (data->hit.t <= vector_length(vector_minus(
							ray.target, ray.start)) + 0.001f && data->cylinder->mater[i] != 3)
				return (1);
		}
	//	if (data->plane->nbr > i && (intersectcylinder(data, i, ray) == 1))
		//{
			//if (data->hit.t <= vector_length(vector_minus(
						//	ray.target, ray.start)) + 0.001f && data->plane->mater[i] != 3)
				//return (1);
		//}
		while (y >= 0)
		{
		if ((int)data->obj[y].num_polygonals > i && intersecttriangle(ray, data, y, i) == 1)
		{
			if (data->hit.t <= vector_length(vector_minus(
						ray.target, ray.start)) + 0.001f)
				return (1);
		}	
			y--;
		}
		i--;
	}
	data->hit.find_shadow = 0;
	return (0);
}

int			shadow(t_data *data, t_vector newstart, int j)
{
	t_ray ray;
	//ft_putchar('\n');
//ft_putnbr(data->objnbr);
//ft_putchar('\n');
	ray.target = vectornew(data->spot->x[j], data->spot->y[j],
			data->spot->z[j]);
	ray.start = vector_copy(newstart);
	if (search_shadow_intersection(data, ray, data->objnbr - 1))
		return (1);
	else
		return (0);
}
