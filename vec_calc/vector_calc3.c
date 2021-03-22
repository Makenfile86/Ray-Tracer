/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 10:18:43 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/05 10:48:15 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	reverse_vector(t_vector v)
{
	v.x = -v.x;
	v.y *= -v.y;
	v.z *= -v.z;
	return (v);
}

t_vector	vector_div(t_vector v, double div)
{
	t_vector result;

	if (div == 0.0)
		return (v);
	result.x = v.x / div;
	result.y = v.y / div;
	result.z = v.z / div;
	return (result);
}
