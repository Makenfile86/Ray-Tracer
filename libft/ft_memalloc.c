/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:15:57 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/30 08:32:44 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*memd;
	size_t		i;

	i = 0;
	memd = (void *)malloc(size * sizeof(size_t));
	if (!memd)
		return (NULL);
	ft_bzero(memd, size);
	return (memd);
}
