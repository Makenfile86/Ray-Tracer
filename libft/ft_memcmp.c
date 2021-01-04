/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:44:17 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/30 07:42:56 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*str1;
	unsigned char			*str2;
	size_t					i;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	if (str1 == str2 || n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((str1[i]) - (str2[i]));
		i++;
	}
	return (0);
}
