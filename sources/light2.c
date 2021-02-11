/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:09:10 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:45:35 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
