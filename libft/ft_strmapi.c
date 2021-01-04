/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:21:25 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/03 12:27:08 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str1;
	unsigned int		i;
	size_t				len;

	if (s && f)
	{
		i = 0;
		len = ft_strlen((char *)s);
		if (!(str1 = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		while (s[i] != '\0')
		{
			str1[i] = f(i, s[i]);
			i++;
		}
		str1[i] = '\0';
		return (str1);
	}
	return (0);
}
