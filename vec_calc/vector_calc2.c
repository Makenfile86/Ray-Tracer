/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 10:48:24 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/05 10:48:45 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


double			vector_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector		normalized_vector(t_vector v)
{
	double		len;
	double		inv_len;
	t_vector	v2;

	len = vector_length(v);
	if (len > 0)
	{
		inv_len = 1 / len;
		v2.x = v.x * inv_len;
		v2.y = v.y * inv_len;
		v2.z = v.z * inv_len;
		return (v2);
	}
	else
		return (v);
}

t_vector		cross_vector(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}

t_vector		vectorsub(t_vector a, t_vector b)
{
	b = vectorscale(-1, b);
	return (vectoradd(a, b));
}

t_vector		vector_minus(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
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

t_vector	reverse_vector(t_vector v)
{
	v.x = -v.x;
	v.y *= -v.y;
	v.z *= -v.z;
	return (v);
}