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


t_vector		vector_copy(t_vector v)
{
	t_vector	v2;

	v2.x = v.x;
	v2.y = v.y;
	v2.z = v.z;
	return (v2);
}

t_vector		vectornew(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector		vectoradd(t_vector v1, t_vector v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

double			vectordot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector		vectorscale(double c, t_vector v)
{
	t_vector	result;

	result.x = v.x * c;
	result.y = v.y * c;
	result.z = v.z * c;
	return (result);
}

