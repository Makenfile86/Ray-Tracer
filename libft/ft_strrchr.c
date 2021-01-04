/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:10:34 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/29 15:57:38 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*len;

	len = (0);
	while (*s)
	{
		if (*s == c)
			len = (char*)s;
		++s;
	}
	if (len)
		return (len);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
