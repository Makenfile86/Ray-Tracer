/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:50:31 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/03 12:43:25 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str1;
	size_t		i;
	size_t		len;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	len = i;
	if (!(str1 = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
