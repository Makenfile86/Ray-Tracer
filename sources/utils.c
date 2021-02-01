/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:24:05 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:24:57 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				keypressed(int keycode)
{
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	return (0);
}

int				min(int num1, int num2)
{
	return ((num1 > num2) ? num2 : num1);
}

t_vector		copy_lightpos(t_data *data, int i)
{
	t_vector light_pos;

	light_pos.x = data->spot->x[i];
	light_pos.y = data->spot->y[i];
	light_pos.z = data->spot->z[i];
	return (light_pos);
}

void			set_hit(t_data *data, char *name, int h)
{
		
	//if (data->hit.refract_lent < data->hit.t)
	//data->hit.refract = 1;
	data->hit.obj_name = name;
	data->hit.obj_idx = h;
	//if (ft_strcmp(data->hit.obj_name, "triangle") != 0)
	//data->hit.poly = -1;
	
	
}

void set_old_hit(t_data *data)
{
	
		data->hit.preobj_name = data->hit.obj_name;
		data->hit.preobj_idx = data->hit.obj_idx;
		data->hit.preobj_mater = data->hit.mater;

		//if (data->hit.preobj_mater == 3)
		//data->iter += 1;

	}
