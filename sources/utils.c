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
	t_vector	light_pos;

	light_pos.x = data->spot->x[i];
	light_pos.y = data->spot->y[i];
	light_pos.z = data->spot->z[i];
	return (light_pos);
}

char			*get_objpath(char *model)
{
	char		*tmp_path1;
	char		*tmp_path2;
	char		*tmp_path3;
	char		*filename;

	tmp_path1 = ft_strdup("./resources/");
	tmp_path2 = ft_strdup(".obj");
	tmp_path3 = ft_strjoin(tmp_path1, model);
	filename = ft_strjoin(tmp_path3, tmp_path2);
	free(tmp_path1);
	free(tmp_path2);
	free(tmp_path3);
	return (filename);
}
