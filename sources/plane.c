/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:25:37 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 13:02:11 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_plane(t_data *data, int e)
{
	
	

	if (data->plane->xyz[e].y == 0)
	data->plane->xyz[e].y = 0.0001;
	data->plane->normal[e] = rotate_vector(data->plane->xyz[e],
			data->plane->normal[e], data->plane->rot[e], 0);
	data->plane->normal[e] = vector_minus(data->plane->normal[e],
			data->plane->xyz[e]);
	data->plane->normal[e] = normalized_vector(data->plane->normal[e]);
	data->plane->nbr += 1;

		if ((ft_strcmp(data->plane->texture[e].name, "checker") == 0) || (ft_strcmp(data->plane->texture[e].name, "gradient") == 0) || (ft_strcmp(data->plane->texture[e].name, "hstripe") == 0) || (ft_strcmp(data->plane->texture[e].name, "vstripe") == 0) || (ft_strcmp(data->plane->texture[e].name, "hstripe") == 0))
data->plane->texture[e].txt_pattern = TRUE;
		if (data->plane->texture[e].txt_pattern != TRUE && (validate_file(data->plane->texture[e].name, &data->plane->texture[e].path) == 1))
		{

	data->plane->texture[e].txt_ppm = parse_ppm(data->plane->texture[e].txt_ppm, data->plane->texture[e].path, &data->plane->texture[e].res);
		if (data->plane->texture[e].txt_ppm != NULL)
		data->plane->texture[e].txt_loaded = TRUE;
	
		}
	if (data->plane->texture[e].txt_loaded == TRUE || data->plane->texture[e].txt_pattern == TRUE)
data->scene->texture = TRUE;

	
}

void			copy_plane_data(t_data *data, char **parts, int e)
{
		data->plane->xyz[e].x = ft_atoi(parts[0]);
		data->plane->xyz[e].y = ft_atoi(parts[1]);
		data->plane->xyz[e].z = ft_atoi(parts[2]);
		data->plane->normal[e].x = ft_atoi(parts[3]);
		data->plane->normal[e].y = ft_atoi(parts[4]);
		data->plane->normal[e].z = ft_atoi(parts[5]);
		data->plane->rgb2[e].red = ft_atoi(parts[6]);
		data->plane->rgb2[e].green = ft_atoi(parts[7]);
		data->plane->rgb2[e].blue = ft_atoi(parts[8]);
		data->plane->rot[e].x = ft_atoi(parts[9]);
		data->plane->rot[e].y = ft_atoi(parts[10]);
		data->plane->rot[e].z = ft_atoi(parts[11]);
		data->plane->mater[e] = ft_atoi(parts[12]);
	data->plane->texture[e].name = (char *)malloc(sizeof(char) * ft_strlen(parts[13]) + 1);
	ft_strcpy(data->plane->texture[e].name, parts[13]);
	data->plane->texture[e].scale = ft_atoi(parts[14]);
		data->plane->texture[e].color.red = ft_atoi(parts[15]);
		data->plane->texture[e].color.green = ft_atoi(parts[16]);
		data->plane->texture[e].color.blue = ft_atoi(parts[17]);

}



