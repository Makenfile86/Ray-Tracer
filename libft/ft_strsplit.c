/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:41:58 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/28 10:36:12 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nofw(const char *str, char c)
{
	size_t	word;

	word = 0;
	if (*str != c && str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

static	int		ft_len(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str1;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s || (!(str1 = (char **)malloc(sizeof(char *) * (ft_nofw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(str1[j] = (char *)malloc(sizeof(char) + (ft_len(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				str1[j][i++] = (char)*s++;
			str1[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	str1[j] = NULL;
	return (str1);
}
