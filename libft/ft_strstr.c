/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:14:03 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/30 08:08:52 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	char		*haystack;
	size_t		to_find_len;

	haystack = (char *)s;
	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
	{
		return (haystack);
	}
	while (*haystack)
	{
		if (*haystack == *to_find)
		{
			if (ft_strncmp(to_find, haystack, to_find_len) == 0)
			{
				return (haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
