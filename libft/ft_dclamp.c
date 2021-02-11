/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclamp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:24:15 by mkivipur          #+#    #+#             */
/*   Updated: 2019/10/31 11:37:44 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_dclamp(double min, double max, double value)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
