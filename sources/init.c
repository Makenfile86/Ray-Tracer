/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:51:22 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:50:31 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			init_parsed_data(t_data *data, char *type, int e)
{
	if (ft_strcmp(type, "object") == 0)
		data->objnbr++;
	if (ft_strcmp(data->obj_name, "SPHERE") == 0)
	init_sphere(data, e);
	if (ft_strcmp(data->obj_name, "SPOT") == 0)
	data->spot->nbr += 1;
	if (ft_strcmp(data->obj_name, "CYLINDER") == 0)
	init_cylinder(data, e);
	else if (ft_strcmp(data->obj_name, "PLANE") == 0)
	init_plane(data, e);
	else if (ft_strcmp(data->obj_name, "CONE") == 0)
	init_cone(data, e);
		else if (ft_strcmp(data->obj_name, "CAMERA") == 0)
	init_camera(data);
	else if (ft_strcmp(data->obj_name, "SCENE") == 0)
	init_scene(data);
}

t_ray			init_pixel(t_data *data, int x, int y, t_rgb *rgb)
{
	t_ray		ray;
	t_vector	v[2];
	t_vector	target;

	rgb->red = 0;
	rgb->green = 0;
	rgb->blue = 0;
	target = init_target(x, y);
	ray.start = vector_copy(data->camera->xyz);
	ray.target = vector_copy(data->camera->direction);
	v[0] = vectorscale(target.x, data->camera->right);
	v[1] = vectorscale(target.y, data->camera->up);
	ray.target = vectoradd(ray.target, v[0]);
	ray.target = vectoradd(ray.target, v[1]);
	ray.target = vec_rot_z(ray.target, data->camera->rot.z);
	ray.target = normalized_vector(ray.target);
	data->light_scale = 1;
	data->hit.fresnel = 1;
	data->iter = data->org_iter;
	data->hit.preobj_name = "empty";
	data->hit.obj_name = "empty";
	data->hit.preobj_mater = 1;
	data->hit.mater = 1;
	data->hit.refract = 0;
	data->hit.refract_lent = 1200;
	return (ray);
}

void			init_data(t_data *data)
{
	data->bits_per_pixel = '\0';
	data->objnbr = 0;
	data->sphere->nbr = 0;
	data->spot->nbr = 0;
	data->cone->nbr = 0;
	data->cylinder->nbr = 0;
	data->plane->nbr = 0;
	data->hit.find_shadow = 0;
	data->hit.preobj_name = "empty";
	data->hit.obj_name = NULL;
	data->mat = 2;
}

void			init_mlx(t_data *data)
{
	if (data->exposure == 0)
	{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "name");
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	}
	if (data->exposure == 1)
	{
		mlx_destroy_image(data->mlx, data->image);
		data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		ft_memset(data->data_addr, 0, ft_strlen(data->data_addr));
	}
	data->size_line = 1000;
	data->endian = 0;
	data->bits_per_pixel /= 8;
	
	data->data_addr = mlx_get_data_addr(
		data->image,
		&(data->bits_per_pixel),
		&(data->size_line),
		&(data->endian));
}

t_vector		init_target(int x, int y)
{
	t_vector	target;
	double		cam_width;
	double		cam_height;

	target.x = 2.0 * x / (WIDTH - 1) - 1.0;
	target.y = -2.0 * y / (HEIGHT - 1) + 1;
	target.z = -1;
	cam_height = tan((FOV * M_PI / 180.0) / 2);
	cam_width = cam_height * (WIDTH / HEIGHT);
	target.x = (target.x * cam_width);
	target.y = (target.y * cam_height);
	return (target);
}
