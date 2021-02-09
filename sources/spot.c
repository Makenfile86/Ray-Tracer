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

#include "rt.h"

void		copy_spot_data(t_data *data, char **parts, int e)
{
	data->spot->x[e] = ft_atoi(parts[0]);
	data->spot->y[e] = ft_atoi(parts[1]);
	data->spot->z[e] = ft_atoi(parts[2]);
	data->spot->power[e] = ft_atoi(parts[3]);
}
