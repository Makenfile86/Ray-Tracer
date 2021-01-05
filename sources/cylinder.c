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

#include "rtv1.h"

void		init_cylinder(t_data *data, int e)
{
	data->cylinder->end_xyz[e] = rotate_vector(data->cylinder->start_xyz[e],
			data->cylinder->end_xyz[e], data->cylinder->rot[e], 0);
	data->cylinder->axis[e] = vector_minus(data->cylinder->start_xyz[e],
			data->cylinder->end_xyz[e]);
	data->cylinder->axis[e] = normalized_vector(data->cylinder->axis[e]);
	data->cylinder->nbr += 1;
	if (data->cylinder->texture[e].type > 1)
	data->cylinder->texture[e].txt_ppm = copy_ppm(data, data->cylinder->texture[e].type);

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
		data->cylinder->texture[e].type = ft_atoi(str);
		else if (x == 15)
		data->cylinder->texture[e].size = ft_atoi(str);
		else if (x == 16)
		data->cylinder->texture[e].color.red = ft_atoi(str);
	else if (x == 17)
		data->cylinder->texture[e].color.green = ft_atoi(str);
	else
		data->cylinder->texture[e].color.blue = ft_atoi(str);

}
