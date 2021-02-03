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

void		init_cylinder(t_data *data, int e)
{
	data->cylinder->end_xyz[e] = rotate_vector(data->cylinder->start_xyz[e],
			data->cylinder->end_xyz[e], data->cylinder->rot[e], 0);
	data->cylinder->axis[e] = vector_minus(data->cylinder->start_xyz[e],
			data->cylinder->end_xyz[e]);
	data->cylinder->axis[e] = normalized_vector(data->cylinder->axis[e]);
	data->cylinder->nbr += 1;
	


		if ((ft_strcmp(data->cylinder->texture[e].name, "checker") == 0) || (ft_strcmp(data->cylinder->texture[e].name, "gradient") == 0) ||
		(ft_strcmp(data->cylinder->texture[e].name, "hstripe") == 0) || (ft_strcmp(data->cylinder->texture[e].name, "vstripe") == 0) || (ft_strcmp(data->cylinder->texture[e].name, "hstripe") == 0))
data->cylinder->texture[e].txt_pattern = TRUE;
		if (data->cylinder->texture[e].txt_pattern != TRUE && (validate_file(data->cylinder->texture[e].name, &data->cylinder->texture[e].path) == 1))
		{

	data->cylinder->texture[e].txt_ppm = parse_ppm(data->cylinder->texture[e].txt_ppm, data->cylinder->texture[e].path, &data->cylinder->texture[e].res);
		if (data->cylinder->texture[e].txt_ppm != NULL)
		data->cylinder->texture[e].txt_loaded = TRUE;
	
		}
if (data->cylinder->texture[e].txt_loaded == TRUE || data->cylinder->texture[e].txt_pattern == TRUE)
data->scene->texture = TRUE;

}

static void		copy_cylinder_color(t_data *data, char *str, int x, int e)
{
	if (x == 7)
		data->cylinder->rgb2[e].red = ft_atoi(str);
	else if (x == 8)
		data->cylinder->rgb2[e].green = ft_atoi(str);
	else if (x == 9)
		data->cylinder->rgb2[e].blue = ft_atoi(str);
}

void		copy_cylinder_data(t_data *data, char *str, int x, int e)
{
	if (x == 0)
		data->cylinder->start_xyz[e].x = ft_atoi(str);
	else if (x == 1)
		data->cylinder->start_xyz[e].y = ft_atoi(str);
	else if (x == 2)
		data->cylinder->start_xyz[e].z = ft_atoi(str);
	else if (x == 3)
		data->cylinder->end_xyz[e].x = ft_atoi(str);
	else if (x == 4)
		data->cylinder->end_xyz[e].y = ft_atoi(str);
	else if (x == 5)
		data->cylinder->end_xyz[e].z = ft_atoi(str);
	else if (x == 6)
		data->cylinder->radius[e] = ft_atoi(str);
	else if (x == 7 || x == 8 || x == 9)
		copy_cylinder_color(data, str, x, e);
	else if (x == 10)
		data->cylinder->rot[e].x = ft_atoi(str);
	else if (x == 11)
		data->cylinder->rot[e].y = ft_atoi(str);
	else if (x == 12)
		data->cylinder->rot[e].z = ft_atoi(str);
	else if (x == 13)
		data->cylinder->mater[e] = ft_atoi(str);
	else if (x == 14)
	{
	data->cylinder->texture[e].name = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strcpy(data->cylinder->texture[e].name, str);
	}
		else if (x == 15)
		data->cylinder->texture[e].scale = ft_atoi(str);
		else if (x == 16)
		data->cylinder->texture[e].color.red = ft_atoi(str);
	else if (x == 17)
		data->cylinder->texture[e].color.green = ft_atoi(str);
	else
		data->cylinder->texture[e].color.blue = ft_atoi(str);

}
