/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:24:05 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:24:57 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb2			gradient_pattern(t_vec2 uv, t_rgb2 obj_color, double pat_size)
{
	obj_color.red += (min(ft_fabs(obj_color.red * uv.v * uv.v * pat_size * 0.8),
				255));
	obj_color.green += (min(ft_fabs(obj_color.green *
					uv.v * uv.v * pat_size * 0.8), 255));
	obj_color.blue += (min(ft_fabs(obj_color.blue *
					uv.v * uv.v * pat_size * 0.8), 255));
	return (obj_color);
}

t_rgb2			vstripe_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size)
{
	if (fmod(uv.u, pat_size * 2) < pat_size)
		return (obj_color);
	else
		return (texture_color);
}

t_rgb2			ppm_texture(int width, int height,
		unsigned char *ppm_image, t_vec2 uv)
{
	t_rgb2		color;
	double		x;
	double		y;
	int			i;

	x = uv.u * (width - 1);
	y = uv.v * (height - 1);
	x = round(x);
	y = round(y);
	i = y * (4 * height) + x * 4;
	color.red = ((int)ppm_image[i + 1]);
	color.green = ((int)ppm_image[i + 2]);
	color.blue = ((int)ppm_image[i + 3]);
	return (color);
}
