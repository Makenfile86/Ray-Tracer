/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 10:49:04 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:46:42 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		rotate_vector(t_vector origin, t_vector target,
		t_vector rot, int no_z)
{
	t_vector	temp;

	target = vector_minus(target, origin);
	if (rot.x != 0)
	{
		rot.x *= -1 * M_PI / 180.0;
		temp.y = target.y;
		target.y = target.y * cos(rot.x) + target.z * sin(rot.x);
		target.z = -1 * temp.y * sin(rot.x) + target.z * cos(rot.x);
	}
	if (rot.y != 0)
	{
		rot.y *= -1 * M_PI / 180.0;
		temp.x = target.x;
		target.x = target.x * cos(rot.y) + target.z * sin(rot.y);
		target.z = -1 * temp.x * sin(rot.y) + target.z * cos(rot.y);
	}
	if (rot.z != 0 || no_z == 1)
	{
		rot.z *= -1 * M_PI / 180.0;
		temp.x = target.x;
		target.x = target.x * cos(rot.z) - target.y * sin(rot.z);
		target.y = temp.x * sin(rot.z) + target.y * cos(rot.z);
	}
	return (vectoradd(target, origin));
}

t_vector		vec_rot_x(t_vector v, double a)
{
	t_vector	r;

	r.x = v.x;
	r.y = v.y * cos(a) - v.z * sin(a);
	r.z = v.y * sin(a) + v.z * cos(a);
	return (r);
}

t_vector		vec_rot_y(t_vector v, double a)
{
	t_vector	r;

	r.x = v.x * cos(a) + v.z * sin(a);
	r.y = v.y;
	r.z = v.z * cos(a) - v.x * sin(a);
	return (r);
}

t_vector		vec_rot_z(t_vector v, double a)
{
	t_vector	r;

	r.x = v.x * cos(a) - v.y * sin(a);
	r.y = v.x * sin(a) + v.y * cos(a);
	r.z = v.z;
	return (r);
}

t_vector		vec_rot_zyx(t_vector v, t_vector r)
{
	v = vec_rot_z(v, dtr(r.z));
	v = vec_rot_y(v, dtr(r.y));
	v = vec_rot_x(v, dtr(r.x));
	return (v);
}
