/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:20:28 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/03 12:16:48 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*str1;
	size_t		i;
	size_t		len;

	if (s && f)
	{
		i = 0;
		len = ft_strlen((char *)s);
		if (!(str1 = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		while (s[i] != '\0')
		{
			str1[i] = f(s[i]);
			i++;
		}
		str1[i] = '\0';
		return (str1);
	}
	return (0);
}
