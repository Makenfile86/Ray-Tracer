/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:19:33 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/30 07:39:34 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			*str;
	unsigned char			c1;
	size_t					i;

	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (0);
}
