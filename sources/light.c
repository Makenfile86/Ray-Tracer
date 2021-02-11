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

double			get_lambert(t_data *data, t_vector target,
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

t_vector		get_dist(t_vector light_pos, t_vector newstart)
{
	t_vector		dist;

	dist = (vector_minus(light_pos, newstart));
	return (dist);
}

t_rgb			color_intensity(int scene_col_intensity, t_rgb2 color)
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

t_rgb			get_light_intensity(t_data *data)
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

double			shadow_scale(int in_shadow, int iter, int org_iter)
{
	double			shadow;

	shadow = 1;
	if (in_shadow == TRUE)
		shadow = 0.175;
	if (in_shadow == TRUE && iter != org_iter)
		shadow = 0.005;
	return (shadow);
}
