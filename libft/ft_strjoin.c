/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:46:24 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/25 14:04:47 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	s3 = NULL;
	if (s1 && s2)
	{
		s3 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
					+ ft_strlen((char *)s2) + 1));
		if (!s3)
			return (NULL);
		ft_strcpy(s3, (char *)s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}
