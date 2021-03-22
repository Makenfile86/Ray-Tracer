/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:27:54 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:30:48 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_cone(t_data *data, int e)
{
	data->cone->axis[e] = vec_rot_zyx(vectornew(0, 1, 0), data->cone->rot[e]);
	data->cone->angle[e] = tan(dtr(data->cone->angle[e]));
	data->cone->nbr += 1;
}

void		copy_cone_data(t_data *data, char **parts, int e)
{
	data->cone->start_xyz[e].x = ft_atoi(parts[0]);
	data->cone->start_xyz[e].y = ft_atoi(parts[1]);
	data->cone->start_xyz[e].z = ft_atoi(parts[2]);
	data->cone->angle[e] = ft_atoi(parts[3]);
	data->cone->rgb2[e].red = ft_atoi(parts[4]);
	data->cone->rgb2[e].green = ft_atoi(parts[5]);
	data->cone->rgb2[e].blue = ft_atoi(parts[6]);
	data->cone->rot[e].x = ft_atoi(parts[7]);
	data->cone->rot[e].y = ft_atoi(parts[8]);
	data->cone->rot[e].z = ft_atoi(parts[9]);
	data->cone->mater[e] = ft_atoi(parts[10]);
}

void		copy_hit_cone(t_data *data, int i)
{
	data->hit.mater = data->cone->mater[i];
	data->hit.color.red = data->cone->rgb2[i].red;
	data->hit.color.green = data->cone->rgb2[i].green;
	data->hit.color.blue = data->cone->rgb2[i].blue;
	data->hit.texture.scale = 1;
	data->hit.texture.txt_loaded = FALSE;
	data->hit.texture.txt_pattern = FALSE;
}
