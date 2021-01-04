/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:12:57 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/31 10:22:37 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbs(unsigned int nb)
{
	size_t size;

	size = 0;
	while (nb >= 10)
	{
		nb = (nb / 10);
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(int n)
{
	char				*str1;
	unsigned int		size;
	unsigned int		i;
	unsigned int		nb;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	size = (unsigned int)ft_nbs(nb);
	if (!(str1 = (char *)malloc(sizeof(char) * size + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	i = 0;
	if (n < 0 && (str1[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		str1[i--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	str1[i] = (char)(nb % 10 + '0');
	str1[size] = '\0';
	return (str1);
}
