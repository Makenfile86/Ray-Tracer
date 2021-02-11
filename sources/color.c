/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:06:18 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/19 09:29:25 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			search_intersection(t_data *data, t_ray ray)
{
	int				i;
	int				y;

	i = data->objnbr - 1;
	data->hit = set_hit_default(data->hit);
	while (i >= 0)
	{
		if (data->cylinder->nbr > i && intersectcylinder(ray, data, i) == 1)
			set_hit(data, "cylinder", i);
		if (data->sphere->nbr > i && intersectsphere(ray, data, i) == 1)
			set_hit(data, "sphere", i);
		if (data->plane->nbr > i && intersectplane(data, i, ray) == 1)
			set_hit(data, "plane", i);
		if (data->cone->nbr > i && intersectcone(ray, data, i) == 1)
			set_hit(data, "cone", i);
		y = (data->modelnbr - 1);
		while (y >= 0)
		{
			if ((int)data->obj[y].num_polygonals > i &&
					intersecttriangle(ray, data, y, i) == 1)
				set_hit(data, "triangle", y);
			y--;
		}
		i--;
	}
}

static t_ray		new_hit_dir(t_data *data, t_ray org_ray, t_vector *n)
{
	t_ray			ray;

	ray.newstart = vectornew(0, 0, 0);
	ray.start = vector_copy(org_ray.start);
	ray.target = vector_copy(org_ray.target);
	if (data->iter == data->org_iter && data->hit.was_refract != 1)
	{
		data->hit.org_start = vector_copy(ray.start);
		data->hit.org_target = vector_copy(ray.target);
		data->hit.org_normal = vector_copy(*n);
	}
	if (ft_strcmp(data->hit.obj_name, "cone") == 0)
		*n = new_start_dir_cone(data, &ray);
	else if (ft_strcmp(data->hit.obj_name, "sphere") == 0)
		*n = new_start_dir_sphere(data, &ray);
	else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
		*n = new_start_dir_plane(data, &ray);
	else if (ft_strcmp(data->hit.obj_name, "cylinder") == 0)
		*n = new_start_dir_cylinder(data, &ray);
	else if (ft_strcmp(data->hit.obj_name, "triangle") == 0)
		*n = new_start_dir_triangle(data, &ray);
	else
		data->hit.normal = *n;
	copy_hit(data, data->hit.obj_name);
	return (ray);
}

static t_rgb		search_light_and_shadow(t_data *data, t_ray ray,
		t_vector n, t_rgb rgb)
{
	int			i;

	ray.target = vector_copy(n);
	i = (data->spot->nbr - 1);
	while (i >= 0)
	{
		if (data->iter == data->org_iter && data->scene->shadows > 0)
			data->hit.in_shadow = shadow(data, ray.newstart, i);
		rgb = get_light(data, rgb, ray, i);
		i--;
	}
	return (rgb);
}

static int			manage_iter(int iter, int mater, int preobj_mater,
char *preobj_name)
{
	if (mater != 3 && mater != 4)
		iter--;
	if ((ft_strcmp(preobj_name, "plane") == 0) && mater == 4)
		iter--;
	if ((ft_strcmp(preobj_name, "empty") != 0) &&
			mater == 3 && preobj_mater != 4)
		iter = 0;
	return (iter);
}

void				get_color(t_data *data, int x, int y)
{
	t_vector		n;
	t_rgb			rgb;
	t_ray			ray;

	ray = init_pixel(data, x, y, &rgb);
	data->hit = init_hit(data->hit);
	while (data->iter > 0 && data->light_scale > 0.0f)
	{
		search_intersection(data, ray);
		if (data->hit.obj_idx == -1)
			break ;
		ray = new_hit_dir(data, ray, &n);
		if (n.x == 101010)
			break ;
		rgb = search_light_and_shadow(data, ray, n, rgb);
		data->iter = manage_iter(data->iter, data->hit.mater,
				data->hit.preobj_mater, data->hit.preobj_name);
		set_old_hit(data);
		ray = reflection_dir(ray, n, data);
		put_color(data, rgb, x, y);
	}
}
