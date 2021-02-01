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


void init_sphere(t_data *data, int e)
{
		

		ft_putendl("mmoikka");
		data->sphere->nbr += 1;
if ((ft_strcmp(data->sphere->texture[e].name, "checker") == 0) || (ft_strcmp(data->sphere->texture[e].name, "gradient") == 0) || (ft_strcmp(data->sphere->texture[e].name, "hstripe") == 0) || (ft_strcmp(data->sphere->texture[e].name, "vstripe") == 0) || (ft_strcmp(data->sphere->texture[e].name, "hstripe") == 0))
data->sphere->texture[e].txt_pattern = TRUE;

		if (data->sphere->texture[e].txt_pattern != TRUE && (validate_file(data->sphere->texture[e].name, &data->sphere->texture[e].path) == 1))
		{

	data->sphere->texture[e].txt_ppm = parse_ppm(data->sphere->texture[e].txt_ppm, data->sphere->texture[e].path, &data->sphere->texture[e].res);
		if (data->sphere->texture[e].txt_ppm != NULL)
		data->sphere->texture[e].txt_loaded = TRUE;
	
		}
	//free(data->sphere->texture[e].path);
if (data->sphere->texture[e].txt_loaded == TRUE || data->sphere->texture[e].txt_pattern == TRUE)
data->scene->texture = TRUE;

	ft_putendl("hoikka");

}
/*
void init_sphere(t_data *data, int e)
{
		data->sphere->nbr += 1;
		if (data->sphere->texture[e].type > 1)
	data->sphere->texture[e].txt_ppm = copy_ppm(data, data->sphere->texture[e].type);
		printf("\n%s\n", data->sphere->texture[0].txt_ppm);
	data->sphere->uv[e].u = 0;
	data->sphere->uv[e].v = 0;
	
}
*/
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
	{
		//ft_putendl(str);
		//ft_putchar('\n');
		data->sphere->mater[e] = ft_atoi(str);
		//ft_putendl("hoi");
		//ft_putnbr(data->sphere->mater[e]);
		//ft_putendl("\nloppu");
	}
	else if (x == 11)
	{
		ft_putendl("horhor");
	data->sphere->texture[e].name = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strcpy(data->sphere->texture[e].name, str);
	}
	else if (x == 12)
	data->sphere->texture[e].size = ft_atoi(str);
	else if (x == 13)
		data->sphere->texture[e].color.red = ft_atoi(str);
	else if (x == 14)
		data->sphere->texture[e].color.green = ft_atoi(str);
	else 
		data->sphere->texture[e].color.blue = ft_atoi(str);
}
