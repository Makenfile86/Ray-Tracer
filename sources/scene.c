/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:37:25 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:38:32 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		copy_scene_data(t_data *data, char **parts)
{
	data->scene->background = ft_atoi(parts[0]);
	data->scene->lambert = ft_atoi(parts[1]);
	data->scene->light_scale = ft_atoi(parts[2]);
	data->scene->shadows = ft_atoi(parts[3]);
	data->scene->ref_iter = ft_atoi(parts[4]);
	data->org_iter = data->scene->ref_iter;
	data->scene->color_intensity = ft_atoi(parts[5]);
	data->scene->reflection = ft_atoi(parts[6]);
}
