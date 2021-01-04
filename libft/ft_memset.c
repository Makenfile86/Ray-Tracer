/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:59:37 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/03 13:50:25 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*ptr;
	unsigned int		i;

	i = 0;
	ptr = (unsigned char*)b;
	while (len > 0)
	{
		ptr[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
