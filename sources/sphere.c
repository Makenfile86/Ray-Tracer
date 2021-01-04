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

#include "rtv1.h"
#include "../libft/libft.h"

void init_sphere(t_data *data, int e)
{
		data->sphere->nbr += 1;
		if (data->sphere->texture[e].type > 1)
		copy_ppm(data, "sphere", e, data->sphere->texture[e].type);
}

void		copy_sphere_data(t_data *data, char *str, int x, int e)
{
	if (x == 0)
		data->sphere->xyz[e].x = ft_atoi(str);
	else if (x == 1)
		data->sphere->xyz[e].y = ft_atoi(str);
	else if (x == 2)
		data->sphere->xyz[e].z = ft_atoi(str);
	else if (x == 3)
		data->sphere->radius[e] = ft_atoi(str);
	else if (x == 4)
		data->sphere->rgb2[e].red = ft_atoi(str);
	else if (x == 5)
		data->sphere->rgb2[e].green = ft_atoi(str);
	else if (x == 6)
		data->sphere->rgb2[e].blue = ft_atoi(str);
	else if (x == 7)
		data->sphere->rot_x[e] = ft_atoi(str);
	else if (x == 8)
		data->sphere->rot_y[e] = ft_atoi(str);
	else if (x == 9)
		data->sphere->rot_z[e] = ft_atoi(str);
	else if (x == 10)
		data->sphere->mater[e] = ft_atoi(str);
	else if (x == 11)
	data->sphere->texture[e].type = ft_atoi(str);
	else if (x == 12)
	data->sphere->texture[e].size = ft_atoi(str);
	else if (x == 13)
		data->sphere->texture[e].color.red = ft_atoi(str);
	else if (x == 14)
		data->sphere->texture[e].color.green = ft_atoi(str);
	else 
		data->sphere->texture[e].color.blue = ft_atoi(str);
}
