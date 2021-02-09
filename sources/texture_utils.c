/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:24:05 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:24:57 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			check_texture_pattern(char *name)
{
	if ((ft_strcmp(name, "checker") == 0) || (ft_strcmp(name, "split") == 0)
			|| (ft_strcmp(name, "gradient") == 0) || (ft_strcmp(name,
					"hstripe") == 0)
			|| (ft_strcmp(name, "vstripe") == 0) ||
			(ft_strcmp(name, "hstripe") == 0))
		return (TRUE);
	return (FALSE);
}
