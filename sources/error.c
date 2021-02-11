/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:21:21 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/19 09:31:13 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	memory_allocation_fail(void)
{
	ft_putendl("Memory allocation failed.");
	exit(1);
}

void	data_read_error(void)
{
	ft_putendl("data read error, wrong syntax.");
	exit(1);
}

void	wrong_scene_name(void)
{
	ft_putendl("wrong scene name.");
	exit(1);
}
