/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:37:51 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:51:34 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				init_camera(t_data *data)
{
	t_vector		camera_pos;
	t_vector		target;
	t_vector		cam_direction;
	t_vector		cam_up;
	t_vector		cam_right;

	camera_pos = vector_copy(data->camera->xyz);
	target = vector_copy(data->camera->target);
	target = rotate_vector(camera_pos, target, data->camera->rot, 1);
	cam_direction = vector_minus(target, camera_pos);
	cam_direction = normalized_vector(cam_direction);
	cam_up = vectornew(0, -1, 0);
	cam_right = cross_vector(cam_up, cam_direction);
	cam_right = normalized_vector(cam_right);
	cam_up = cross_vector(cam_right, cam_direction);
	data->camera->direction = vector_copy(cam_direction);
	data->camera->up = vector_copy(cam_up);
	data->camera->right = vector_copy(cam_right);
}

void				copy_camera_data(t_data *data, char **parts)
{
	data->camera->xyz.x = ft_atoi(parts[0]);
	data->camera->xyz.y = ft_atoi(parts[1]);
	data->camera->xyz.z = ft_atoi(parts[2]);
	data->camera->target.x = ft_atoi(parts[3]);
	data->camera->target.y = ft_atoi(parts[4]);
	data->camera->target.z = ft_atoi(parts[5]);
	data->camera->rot.x = ft_atoi(parts[6]);
	data->camera->rot.y = ft_atoi(parts[7]);
	data->camera->rot.z = ft_atoi(parts[8]);
}
