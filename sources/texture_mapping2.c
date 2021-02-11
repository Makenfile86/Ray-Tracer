/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:24:05 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:24:57 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb2				add_texture(t_vec2 uv, t_rgb2 color, t_hit hit)
{
	char *name;

	name = hit.obj_name;
	if ((ft_strcmp(name, "cone") == 0) || (ft_strcmp(name, "triangle") == 0))
		return (color);
	else
	{
		if ((ft_strcmp(hit.texture.name, "checker") == 0))
			return (checker_pattern(uv, color, hit.texture.color,
						pat_size(hit.texture.scale, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "vstripe") == 0))
			return (vstripe_pattern(uv, color, hit.texture.color,
						pat_size(hit.texture.scale, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "hstripe") == 0))
			return (hstripe_pattern(uv, color, hit.texture.color,
						pat_size(hit.texture.scale, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "gradient") == 0))
			return (gradient_pattern(uv, color, pat_size(hit.texture.scale,
						name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "split") == 0))
			return (split_pattern(uv, color, hit.texture.color,
						pat_size(hit.texture.scale, name, hit.radius)));
		else
			return (color);
	}
}
