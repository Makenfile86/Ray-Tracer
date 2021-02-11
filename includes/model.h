/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 09:35:11 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/05 10:10:11 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include "vectors.h"
# include "rt.h"
# include "../libft/libft.h"

typedef	struct	s_model
{
	char		*name;
	t_rgb2		rgb2;
	t_vector	xyz;
	t_vector	rot;
	double		mater;
	double		scale;
	int			nbr;
}				t_model;

typedef	struct	s_vertices
{
	t_vector	ve[3];
	t_vector	te[3];
	t_vector	no[3];
	t_vector	normal;
	t_vec2		uv[3];
}				t_vertices;

typedef	struct	s_obj
{
	size_t		num_geometry;
	t_vector	*geometry;
	size_t		num_coordinates;
	t_vec2		*coordinates;
	size_t		num_normals;
	t_vector	*normals;
	size_t		num_polygonals;
	t_vertices	*polygonals;
	t_model		model;
}				t_obj;

t_obj			*create_obj_data(void);
void			malloc_obj(t_obj *obj, size_t num_geometry,
	size_t num_coordinates);
void			malloc_obj2(t_obj *obj, size_t num_normals,
	size_t num_polygonals);
t_vector		parse_geo(char *line);
t_vec2			parse_coord(char *line);
t_vector		parse_normals(char *line);

#endif
