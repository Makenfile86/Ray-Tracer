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

#include "rt.h"

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
	else if (ft_strcmp(data->obj_name, "MODEL") == 0)
		init_model(data, e);
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
	data->light_scale = (double)((data->scene->light_scale) * 0.2);
	data->iter = data->org_iter;
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
	data->hit.find_shadow = FALSE;
	data->hit.preobj_name = "empty";
	data->hit.obj_name = NULL;
}

void			init_mlx(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "name");
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
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
