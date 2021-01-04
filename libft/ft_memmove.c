/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:00:49 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/03 14:04:11 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	size_t				i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (!dst1 && !src1)
		return (0);
	i = -1;
	if (src1 < dst1)
	{
		while ((int)(--len) >= 0)
			*(dst1 + len) = *(src1 + len);
	}
	else
		while (++i < len)
			*(dst1 + i) = *(src1 + i);
	return (dst);
}
