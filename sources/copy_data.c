/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:53:39 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:57:02 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		copy_data(t_data *data, char **parts, int e)
{
	if (ft_strcmp(data->obj_name, "SPHERE") == 0)
		copy_sphere_data(data, parts, e);
	else if (ft_strcmp(data->obj_name, "CYLINDER") == 0)
		copy_cylinder_data(data, parts, e);
	else if (ft_strcmp(data->obj_name, "CONE") == 0)
		copy_cone_data(data, parts, e);
	else if (ft_strcmp(data->obj_name, "PLANE") == 0)
		copy_plane_data(data, parts, e);
	else if (ft_strcmp(data->obj_name, "SPOT") == 0)
		copy_spot_data(data, parts, e);
	else if (ft_strcmp(data->obj_name, "CAMERA") == 0)
		copy_camera_data(data, parts);
	else if (ft_strcmp(data->obj_name, "SCENE") == 0)
		copy_scene_data(data, parts);
	else if (ft_strcmp(data->obj_name, "MODEL") == 0)
	{
		copy_model_data(data, parts, e);
	}
}
