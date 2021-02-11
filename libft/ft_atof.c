/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:24:15 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/31 11:37:44 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	integ;
	double	dec;
	char	*c;
	int		len;

	c = (char *)str;
	integ = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	dec = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		dec /= 10;
	return (integ + ((integ > 0) ? dec : -dec));
}
