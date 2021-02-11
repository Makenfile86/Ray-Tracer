/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:09:10 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:45:35 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double		get_lambert(t_data *data, t_vector target,
		t_vector newstart, t_vector dist)
{
	t_ray			lightray;
	double			lambert;
	double			lambert_scale;

	lambert_scale = (data->scene->lambert / 1.8);
	if (lambert_scale < 1)
		lambert_scale = 1;
	lightray.start = newstart;
	lightray.target = vectorscale((lambert_scale / (data->hit.t)), dist);
	lambert = vectordot(lightray.target, target) * data->light_scale;
	data->light_scale *= 0.9;
	return (lambert);
}

static t_vector		get_dist(t_vector light_pos, t_vector newstart)
{
	t_vector		dist;

	dist = (vector_minus(light_pos, newstart));
	return (dist);
}

static t_rgb		color_intensity(int scene_col_intensity, t_rgb2 color)
{
	t_rgb			intensity;

	intensity.red = ((double)color.red /
	(fabs(scene_col_intensity - 9.5) * 25));
	intensity.green = ((double)color.green /
	(fabs(scene_col_intensity - 9.5) * 25));
	intensity.blue = ((double)color.blue /
	(fabs(scene_col_intensity - 9.5) * 25));
	return (intensity);
}

static t_rgb		get_light_intensity(t_data *data)
{
	t_rgb2			color;
	int				i;

	i = data->hit.obj_idx;
	if (data->hit.texture.txt_pattern == TRUE)
		color = add_texture(texture_mapping(data->hit, data->hit.obj_name),
				data->hit.color, data->hit);
	else if (data->hit.texture.txt_loaded == TRUE)
	{
		if (ft_strcmp(data->hit.obj_name, "sphere") == 0)
			color = ppm_texture(data->hit.texture.res.x,
					data->hit.texture.res.y, data->sphere->texture[i].txt_ppm,
					texture_mapping(data->hit, data->hit.obj_name));
		else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
			color = ppm_texture(data->hit.texture.res.x,
					data->hit.texture.res.y, data->plane->texture[i].txt_ppm,
					texture_mapping(data->hit, data->hit.obj_name));
		else
			color = ppm_texture(data->hit.texture.res.x,
					data->hit.texture.res.y, data->cylinder->texture[i].txt_ppm,
					texture_mapping(data->hit, data->hit.obj_name));
	}
	else
		color = data->hit.color;
	return (color_intensity(data->scene->color_intensity, color));
}

static double		shadow_scale(int in_shadow, int iter, int org_iter)
{
	double			shadow;

	shadow = 1;
	if (in_shadow == TRUE)
		shadow = 0.175;
	if (in_shadow == TRUE && iter != org_iter)
		shadow = 0.005;
	return (shadow);
}

int					check_if_in_shadow(t_ray ray, double *dist,
		int *in_shadow, t_vector light_pos)
{
	if (vectordot(ray.target, get_dist(light_pos, ray.newstart)) <= 0.0f)
	{
		*in_shadow = TRUE;
		return (1);
	}
	*dist = sqrt(vectordot(get_dist(light_pos, ray.newstart),
				get_dist(light_pos, ray.newstart)));
	if (*dist <= 0.0f)
	{
		*in_shadow = TRUE;
		return (1);
	}
	return (0);
}

t_rgb				get_light(t_data *data, t_rgb rgb, t_ray ray, int i)
{
	t_material		material;
	t_vector		light_pos;
	t_rgb			intensity;
	double			shadow;
	int				h;

	h = data->hit.obj_idx;
	light_pos = copy_lightpos(data, i);
	intensity = get_light_intensity(data);
	if (check_if_in_shadow(ray, &data->hit.t, &data->hit.in_shadow, light_pos))
		return (rgb);
	material = get_material(data, data->hit, data->spot->power[i]);
	shadow = shadow_scale(data->hit.in_shadow, data->iter, data->org_iter);
	rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart)) *
		intensity.red * material.diffuse_red * data->hit.fresnel * shadow;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart)) *
		intensity.green * material.diffuse_green * data->hit.fresnel * shadow;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart)) *
		intensity.blue * material.diffuse_blue * data->hit.fresnel * shadow;
	return (rgb);
}
