/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 09:35:11 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/05 10:10:11 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "rt.h"

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_vect
{
	double			u;
	double			v;
}					t_vec2;

t_vector			vectornew(double x, double y, double z);
double				vector_length(t_vector v);
t_vector			vector_copy(t_vector v);
t_vector			vec_rot_zyx(t_vector v, t_vector r);
t_vector			vec_rot_z(t_vector v, double a);
t_vector			vec_rot_y(t_vector v, double a);
t_vector			vec_rot_x(t_vector v, double a);
t_vector			vectorsub(t_vector a, t_vector b);
t_vector			vectoradd(t_vector v1, t_vector v2);
t_vector			rotate_vector(t_vector origin, t_vector target,
		t_vector rot, int no_z);
t_vector			cross_vector(t_vector v1, t_vector v2);
t_vector			vectoradd(t_vector v1, t_vector v2);
t_vector			vectorscale(double c, t_vector v);
t_vector			vector_minus(t_vector v1, t_vector v2);
t_vector			normalized_vector(t_vector v);
double				vectordot(t_vector v1, t_vector v2);
t_vector			vector_div(t_vector v, double div);
t_vector			reverse_vector(t_vector v);

#endif
