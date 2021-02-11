/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:27:54 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:30:48 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_material		add_material(double value)
{
	t_material			material;

	material.diffuse_red = value;
	material.diffuse_green = value;
	material.diffuse_blue = value;
	return (material);
}

t_material				mirror(t_hit hit, int scale, int light_power)
{
	if ((ft_strcmp(hit.preobj_name, "plane") == 0))
		return (add_material((double)light_power / 1800));
	return (add_material((double)light_power / (1800 / scale)));
}

t_material				get_material(t_data *data, t_hit hit, int light_power)
{
	t_material			material;

	material = add_material((double)light_power / 200);
	if (hit.mater == 4)
		material = mirror(hit, hit.texture.scale, light_power);
	if ((ft_strcmp(hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter &&
			hit.preobj_mater < 3 && hit.was_refract != 1)
		material = add_material((double)light_power / 1800);
	if ((ft_strcmp(hit.preobj_name, "plane") == 0) &&
			(ft_strcmp(hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter && data->hit.preobj_mater != 4)
		material = add_material((double)light_power / 1800);
	if (hit.mater == 3)
		add_material((double)light_power / 1800);
	if ((ft_strcmp(hit.preobj_name, "plane") == 0) &&
			data->iter != data->org_iter &&
			hit.preobj_mater < 3 && hit.was_refract != 1)
		material = add_material(0);
	return (material);
}
