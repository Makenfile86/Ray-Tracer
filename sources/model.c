/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:51:22 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:50:31 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_model(t_data *data, int e)
{
	data->obj[e].num_geometry = 0;
	data->obj[e].geometry = NULL;
	data->obj[e].num_coordinates = 0;
	data->obj[e].coordinates = NULL;
	data->obj[e].num_normals = 0;
	data->obj[e].normals = NULL;
	data->obj[e].num_polygonals = 0;
	data->obj[e].polygonals = NULL;
	data->modelnbr += 1;
	data->obj[e] = init_obj(&data->obj[e], &data->objnbr);
}

void			copy_model_data(t_data *data, char **parts, int e)
{
	data->obj[e].model.name = (char *)malloc(sizeof(char) *
	ft_strlen(parts[0]) + 1);
	ft_strcpy(data->obj[e].model.name, parts[0]);
	data->obj[e].model.xyz.x = ft_atoi(parts[1]);
	data->obj[e].model.xyz.y = ft_atoi(parts[2]);
	data->obj[e].model.xyz.z = ft_atoi(parts[3]);
	data->obj[e].model.rgb2.red = ft_atoi(parts[4]);
	data->obj[e].model.rgb2.green = ft_atoi(parts[5]);
	data->obj[e].model.rgb2.blue = ft_atoi(parts[6]);
	data->obj[e].model.rot.x = ft_atoi(parts[7]);
	data->obj[e].model.rot.y = ft_atoi(parts[8]);
	data->obj[e].model.rot.z = ft_atoi(parts[9]);
	data->obj[e].model.mater = ft_atoi(parts[10]);
	data->obj[e].model.scale = ft_atoi(parts[11]);
}

void			copy_hit_model(t_data *data, int i)
{
	data->hit.mater = data->obj[i].model.mater;
	data->hit.texture.txt_loaded = FALSE;
	data->hit.color.red = data->obj[i].model.rgb2.red;
	data->hit.color.green = data->obj[i].model.rgb2.green;
	data->hit.color.blue = data->obj[i].model.rgb2.blue;
}
