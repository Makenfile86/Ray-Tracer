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

#include "rtv1.h"

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
	if (data->plane->texture[e].type > 1)
	copy_ppm(data, "plane", e, data->plane->texture[e].type);
	
}

void			copy_plane_data(t_data *data, char *str, int x, int e)
{
	if (x == 0)
		data->plane->xyz[e].x = ft_atoi(str);
	else if (x == 1)
		data->plane->xyz[e].y = ft_atoi(str);
	else if (x == 2)
		data->plane->xyz[e].z = ft_atoi(str);
	else if (x == 3)
		data->plane->normal[e].x = ft_atoi(str);
	else if (x == 4)
		data->plane->normal[e].y = ft_atoi(str);
	else if (x == 5)
		data->plane->normal[e].z = ft_atoi(str);
	else if (x == 6)
		data->plane->rgb2[e].red = ft_atoi(str);
	else if (x == 7)
		data->plane->rgb2[e].green = ft_atoi(str);
	else if (x == 8)
		data->plane->rgb2[e].blue = ft_atoi(str);
	else if (x == 9)
		data->plane->rot[e].x = ft_atoi(str);
	else if (x == 10)
		data->plane->rot[e].y = ft_atoi(str);
	else if (x == 11)
		data->plane->rot[e].z = ft_atoi(str);
	else if (x == 12)
		data->plane->mater[e] = atoi(str);
	else if (x == 13)
	data->plane->texture[e].type = ft_atoi(str);
	else if (x == 14)
	data->plane->texture[e].size = ft_atoi(str);
	else if (x == 15)
		data->plane->texture[e].color.red = ft_atoi(str);
	else if (x == 16)
		data->plane->texture[e].color.green = ft_atoi(str);
	else 
		data->plane->texture[e].color.blue = ft_atoi(str);
	
	//if (data->plane->mater[e] == 4)
	//ft_putendl("hooi hoi hoi ");
}


	//init_plane(data, e, str);

