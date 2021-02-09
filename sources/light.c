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
#include "math.h"
#include "stdio.h"

static double		get_lambert(t_data *data, t_vector target,
		t_vector newstart, t_vector dist)
{
	t_ray		lightray;
	double		lambert;
	double		lambert_scale;
	

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
	t_vector	dist;

	dist = (vector_minus(light_pos, newstart));
	return (dist);
}


static t_rgb		get_light_intensity(t_data *data)
{
	t_rgb		intensity;
	t_rgb2		color;
	int i;
	
	
	i = data->hit.obj_idx;
	if (data->hit.texture.txt_pattern == TRUE)
	color = add_texture(texture_mapping(data->hit, data->hit.obj_name), data->hit.color, data->hit);
	else if (data->hit.texture.txt_loaded == TRUE)
	{

		if (ft_strcmp(data->hit.obj_name, "sphere") == 0)
		color = ppm_texture(data->hit.texture.res.x, data->hit.texture.res.y, data->sphere->texture[i].txt_ppm, texture_mapping(data->hit, data->hit.obj_name));
		else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
		color = ppm_texture(data->hit.texture.res.x, data->hit.texture.res.y, data->plane->texture[i].txt_ppm, texture_mapping(data->hit, data->hit.obj_name));
		else 
		color = ppm_texture(data->hit.texture.res.x, data->hit.texture.res.y, data->cylinder->texture[i].txt_ppm, texture_mapping(data->hit, data->hit.obj_name));
	}
	else 
	color = data->hit.color;

	intensity.red = ((double)color.red / (fabs(data->scene->color_intensity - 9.5) * 25));
	intensity.green = ((double)color.green / (fabs(data->scene->color_intensity - 9.5) * 25));
	intensity.blue = ((double)color.blue / (fabs(data->scene->color_intensity - 9.5) * 25));

	return (intensity);
}

t_rgb				get_light(t_data *data, t_rgb rgb, t_ray ray, int i)
{
	t_material	material;
	t_vector	light_pos;
	t_rgb		intensity;
	double		shadow;
	int			h;
	

	h = data->hit.obj_idx;
	light_pos = copy_lightpos(data, i);
	intensity = get_light_intensity(data);
		if (vectordot(ray.target, get_dist(light_pos, ray.newstart)) <= 0.0f)
		{
			data->hit.in_shadow = TRUE;
			return (rgb);
		}
	data->hit.t = sqrt(vectordot(get_dist(light_pos, ray.newstart),
				get_dist(light_pos, ray.newstart)));
	if (data->hit.t <= 0.0f)
	{
		data->hit.in_shadow = TRUE;
		return (rgb);
	}
	
	material = get_material(data, data->hit, data->spot->power[i]);

	shadow = 1;
	if (data->hit.in_shadow == TRUE)
	shadow = 0.175;
	if (data->hit.in_shadow == TRUE && data->iter != data->org_iter)
	shadow = 0.005;

		rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red * data->hit.fresnel * shadow;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green * data->hit.fresnel * shadow;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue * data->hit.fresnel * shadow;
	return (rgb);
}
