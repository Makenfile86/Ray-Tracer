/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:53:39 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:57:02 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				init_cylinder(t_data *data, int e)
{
	data->cylinder->end_xyz[e] = rotate_vector(data->cylinder->start_xyz[e],
			data->cylinder->end_xyz[e], data->cylinder->rot[e], 0);
	data->cylinder->axis[e] = vector_minus(data->cylinder->start_xyz[e],
			data->cylinder->end_xyz[e]);
	data->cylinder->axis[e] = normalized_vector(data->cylinder->axis[e]);
	data->cylinder->nbr += 1;
	data->cylinder->texture[e].txt_pattern =
		check_texture_pattern(data->cylinder->texture[e].name);
	if (data->cylinder->texture[e].txt_pattern != TRUE &&
			(validate_file(data->cylinder->texture[e].name,
			&data->cylinder->texture[e].path) == 1))
	{
		data->cylinder->texture[e].txt_ppm = parse_ppm(data->cylinder->
				texture[e].txt_ppm, data->cylinder->texture[e].path,
				&data->cylinder->texture[e].res);
		if (data->cylinder->texture[e].txt_ppm != NULL)
			data->cylinder->texture[e].txt_loaded = TRUE;
	}
	if (data->cylinder->texture[e].txt_loaded == TRUE ||
			data->cylinder->texture[e].txt_pattern == TRUE)
		data->scene->texture = TRUE;
}

void				copy_cylinder_data(t_data *data, char **parts, int e)
{
	data->cylinder->start_xyz[e].x = ft_atoi(parts[0]);
	data->cylinder->start_xyz[e].y = ft_atoi(parts[1]);
	data->cylinder->start_xyz[e].z = ft_atoi(parts[2]);
	data->cylinder->end_xyz[e].x = ft_atoi(parts[3]);
	data->cylinder->end_xyz[e].y = ft_atoi(parts[4]);
	data->cylinder->end_xyz[e].z = ft_atoi(parts[5]);
	data->cylinder->length[e] = ft_atoi(parts[6]);
	data->cylinder->radius[e] = ft_atoi(parts[7]);
	data->cylinder->rgb2[e].red = ft_atoi(parts[8]);
	data->cylinder->rgb2[e].green = ft_atoi(parts[9]);
	data->cylinder->rgb2[e].blue = ft_atoi(parts[10]);
	data->cylinder->rot[e].x = ft_atoi(parts[11]);
	data->cylinder->rot[e].y = ft_atoi(parts[12]);
	data->cylinder->rot[e].z = ft_atoi(parts[13]);
	data->cylinder->mater[e] = ft_atoi(parts[14]);
	{
		data->cylinder->texture[e].name = (char *)malloc(
				sizeof(char) * ft_strlen(parts[15]) + 1);
		ft_strcpy(data->cylinder->texture[e].name, parts[15]);
	}
	data->cylinder->texture[e].scale = ft_atoi(parts[16]);
	data->cylinder->texture[e].color.red = ft_atoi(parts[17]);
	data->cylinder->texture[e].color.green = ft_atoi(parts[18]);
	data->cylinder->texture[e].color.blue = ft_atoi(parts[19]);
}

void				copy_hit_cylinder(t_data *data, int i)
{
	data->hit.rot = data->cylinder->rot[i];
	data->hit.pos = data->cylinder->start_xyz[i];
	data->hit.axis = data->cylinder->axis[i];
	data->hit.radius = data->cylinder->radius[i];
	data->hit.texture.name = data->cylinder->texture[i].name;
	data->hit.texture.txt_loaded = data->cylinder->texture[i].txt_loaded;
	data->hit.texture.txt_pattern = data->cylinder->texture[i].txt_pattern;
	data->hit.texture.res.x = data->cylinder->texture[i].res.x;
	data->hit.texture.res.y = data->cylinder->texture[i].res.y;
	data->hit.texture.scale = data->cylinder->texture[i].scale;
	data->hit.texture.color.red = data->cylinder->texture[i].color.red;
	data->hit.texture.color.green = data->cylinder->texture[i].color.green;
	data->hit.texture.color.blue = data->cylinder->texture[i].color.blue;
	data->hit.color.red = data->cylinder->rgb2[i].red;
	data->hit.color.green = data->cylinder->rgb2[i].green;
	data->hit.color.blue = data->cylinder->rgb2[i].blue;
	data->hit.mater = data->cylinder->mater[i];
}
