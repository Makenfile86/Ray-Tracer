/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:53:39 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:57:02 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit			init_hit(t_hit hit)
{
	hit.fresnel = 1;
	hit.preobj_name = "empty";
	hit.obj_name = "empty";
	hit.preobj_mater = 1;
	hit.in_shadow = FALSE;
	hit.mater = 1;
	hit.refract = FALSE;
	hit.was_refract = FALSE;
	hit.texture.name = "empty";
	hit.texture.txt_loaded = FALSE;
	hit.texture.txt_pattern = FALSE;
	hit.texture.res.x = 0;
	hit.texture.res.y = 0;
	return (hit);
}

void			copy_hit(t_data *data, char *obj_name)
{
	int			i;

	i = data->hit.obj_idx;
	if (ft_strcmp(obj_name, "sphere") == 0)
		copy_hit_sphere(data, i);
	else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
		copy_hit_plane(data, i);
	else if (ft_strcmp(data->hit.obj_name, "cylinder") == 0)
		copy_hit_cylinder(data, i);
	else if (ft_strcmp(data->hit.obj_name, "cone") == 0)
		copy_hit_cone(data, i);
	else if (ft_strcmp(data->hit.obj_name, "triangle") == 0)
		copy_hit_model(data, i);
	if (data->hit.mater == 3)
		data->hit.refract = TRUE;
}

void			set_old_hit(t_data *data)
{
	data->hit.preobj_name = data->hit.obj_name;
	data->hit.preobj_idx = data->hit.obj_idx;
	data->hit.preobj_mater = data->hit.mater;
}

void			set_hit(t_data *data, char *name, int h)
{
	data->hit.obj_name = name;
	data->hit.obj_idx = h;
}

t_hit			set_hit_default(t_hit hit)
{
	hit.obj_idx = -1;
	hit.t = 1000.0;
	hit.find_shadow = FALSE;
	return (hit);
}
