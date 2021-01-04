/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:07:41 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:52 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "../libft/libft.h"
#include "stdio.h"

void		copy_spot_data(t_data *data, char *str, int x, int e)
{
	if (x == 0)
		data->spot->x[e] = ft_atoi(str);
	else if (x == 1)
		data->spot->y[e] = ft_atoi(str);
	else if (x == 2)
		data->spot->z[e] = ft_atoi(str);
	else if (x == 3)
		data->spot->power[e] = ft_atoi(str);

}
