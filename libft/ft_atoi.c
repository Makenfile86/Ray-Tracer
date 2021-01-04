/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:55:23 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/03 12:32:57 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int minus;
	int i;

	res = 0;
	minus = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
		(str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	{
		if (str[i] == '-')
			minus = 1;
		if (str[i] == '+' || str[i] == '-')
			i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + ((int)str[i] - '0');
		i++;
	}
	if (minus == 1)
		return (-res);
	else
		return (res);
}
