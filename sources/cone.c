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

#include "rtv1.h"
#include "../libft/libft.h"

void		init_cone(t_data *data, int e)
{
	data->cone->axis[e] = vec_rot_zyx(vectornew(0, 1, 0), data->cone->rot[e]);
	data->cone->angle[e] = tan(DTR(data->cone->angle[e]));
	data->cone->uv[e].v = 0;
	data->cone->uv[e].u = 0;
	data->cone->nbr += 1;

}

void		copy_cone_data(t_data *data, char *str, int x, int e)
{
	if (x == 0)
		data->cone->start_xyz[e].x = ft_atoi(str);
	else if (x == 1)
		data->cone->start_xyz[e].y = ft_atoi(str);
	else if (x == 2)
		data->cone->start_xyz[e].z = ft_atoi(str);
	else if (x == 3)
		data->cone->angle[e] = ft_atoi(str);
	else if (x == 4)
		data->cone->rgb2[e].red = ft_atoi(str);
	else if (x == 5)
		data->cone->rgb2[e].green = ft_atoi(str);
	else if (x == 6)
		data->cone->rgb2[e].blue = ft_atoi(str);
	else if (x == 7)
		data->cone->rot[e].x = ft_atoi(str);
	else if (x == 8)
		data->cone->rot[e].y = ft_atoi(str);
	else if (x == 9)
		data->cone->rot[e].z = ft_atoi(str);
	else
		data->cone->mater[e] = ft_atoi(str);


}
