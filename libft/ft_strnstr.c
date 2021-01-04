/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:51:01 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/30 08:18:05 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t pos;
	size_t i;

	if (!*to_find)
		return ((char*)s);
	pos = 0;
	while (s[pos] != '\0' && (size_t)pos < len)
	{
		if (s[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && s[pos + i] == to_find[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (to_find[i] == '\0')
				return ((char*)&s[pos]);
		}
		++pos;
	}
	return (0);
}
