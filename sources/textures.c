/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:24:05 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:24:57 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			pat_size(double scale, char *obj_name, int radius)
{
	double			size;

	if (radius < 1)
		radius = 1;
	if (ft_strcmp(obj_name, "sphere") == 0)
		size = (0.125 * radius / 5 * (scale / 2));
	else if (ft_strcmp(obj_name, "plane") == 0)
		size = 0.5;
	else
		size = (0.1 / radius * scale);
	return (size);
}

t_rgb2			cyl_checker_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size)
{
	double			u2;
	double			v2;

	pat_size = 1;
	u2 = floor(uv.u * 500);
	v2 = floor(uv.v * 50);
	if ((fmod((u2 + v2), 2)) == 0)
		return (obj_color);
	else
		return (texture_color);
}

t_rgb2			checker_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size)
{
	if (fmod(uv.u, pat_size * 2) < pat_size)
	{
		if (fmod(uv.v, pat_size * 2) < pat_size)
			return (obj_color);
		else
			return (texture_color);
	}
	else
	{
		if (fmod(uv.v, pat_size * 2) < pat_size)
			return (texture_color);
		else
			return (obj_color);
	}
}

t_rgb2			split_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size)
{
	pat_size = 0;
	uv.v /= 6.0;
	if (uv.v < 0.5)
		return (obj_color);
	else
		return (texture_color);
}

t_rgb2			hstripe_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size)
{
	if (fmod(uv.v, pat_size * 2) < pat_size)
		return (obj_color);
	else
		return (texture_color);
}
