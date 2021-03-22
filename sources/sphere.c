/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:37:25 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:38:32 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_sphere(t_data *data, int e)
{
	data->sphere->nbr += 1;
	data->sphere->texture[e].txt_pattern =
		check_texture_pattern(data->sphere->texture[e].name);
	if (data->sphere->texture[e].txt_pattern != TRUE && (validate_file(data->
					sphere->texture[e].name, &data->sphere->texture[e].path)
				== 1))
	{
		data->sphere->texture[e].txt_ppm = parse_ppm(
				data->sphere->texture[e].txt_ppm
				, data->sphere->texture[e].path, &data->sphere->texture[e].res);
		if (data->sphere->texture[e].txt_ppm != NULL)
			data->sphere->texture[e].txt_loaded = TRUE;
	}
	if (data->sphere->texture[e].txt_loaded == TRUE ||
			data->sphere->texture[e].txt_pattern == TRUE)
		data->scene->texture = TRUE;
}

void		copy_sphere_data(t_data *data, char **parts, int e)
{
	data->sphere->xyz[e].x = ft_atoi(parts[0]);
	data->sphere->xyz[e].y = ft_atoi(parts[1]);
	data->sphere->xyz[e].z = ft_atoi(parts[2]);
	data->sphere->radius[e] = ft_atoi(parts[3]);
	data->sphere->rgb2[e].red = ft_atoi(parts[4]);
	data->sphere->rgb2[e].green = ft_atoi(parts[5]);
	data->sphere->rgb2[e].blue = ft_atoi(parts[6]);
	data->sphere->rot[e].x = ft_atoi(parts[7]);
	data->sphere->rot[e].y = ft_atoi(parts[8]);
	data->sphere->rot[e].z = ft_atoi(parts[9]);
	data->sphere->mater[e] = ft_atoi(parts[10]);
	data->sphere->texture[e].name = (char *)malloc(
			sizeof(char) * ft_strlen(parts[11]) + 1);
	ft_strcpy(data->sphere->texture[e].name, parts[11]);
	data->sphere->texture[e].scale = ft_atoi(parts[12]);
	if (parts[13])
		data->sphere->texture[e].color.red = ft_atoi(parts[13]);
	if (parts[14])
		data->sphere->texture[e].color.green = ft_atoi(parts[14]);
	if (parts[15])
		data->sphere->texture[e].color.blue = ft_atoi(parts[15]);
}

void		copy_hit_sphere(t_data *data, int i)
{
	data->hit.texture.name = data->sphere->texture[i].name;
	data->hit.texture.txt_loaded = data->sphere->texture[i].txt_loaded;
	data->hit.texture.txt_pattern = data->sphere->texture[i].txt_pattern;
	data->hit.texture.res.x = data->sphere->texture[i].res.x;
	data->hit.texture.res.y = data->sphere->texture[i].res.y;
	data->hit.texture.scale = data->sphere->texture[i].scale;
	data->hit.texture.color.red = data->sphere->texture[i].color.red;
	data->hit.texture.color.green = data->sphere->texture[i].color.green;
	data->hit.texture.color.blue = data->sphere->texture[i].color.blue;
	data->hit.color.red = data->sphere->rgb2[i].red;
	data->hit.color.green = data->sphere->rgb2[i].green;
	data->hit.color.blue = data->sphere->rgb2[i].blue;
	data->hit.mater = data->sphere->mater[i];
	data->hit.radius = data->sphere->radius[i];
	data->hit.rot = data->sphere->rot[i];
	data->hit.pos = data->sphere->xyz[i];
}
