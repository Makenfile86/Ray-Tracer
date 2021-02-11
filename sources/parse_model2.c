/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_model2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:51:22 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:50:31 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				malloc_obj(t_obj *obj, size_t num_geometry,
		size_t num_coordinates)
{
	obj->geometry = (t_vector*)malloc(sizeof(t_vector) * num_geometry);
	obj->coordinates = (t_vec2*)malloc(sizeof(t_vec2) * num_coordinates);
}

void				malloc_obj2(t_obj *obj, size_t num_normals,
		size_t num_polygonals)
{
	obj->normals = (t_vector*)malloc(sizeof(t_vector) * num_normals);
	obj->polygonals = (t_vertices*)malloc(sizeof(t_vertices) * num_polygonals);
}

t_vector			parse_normals(char *line)
{
	t_vector	vector;
	char		**parts;

	parts = ft_strsplit(line + 1, ' ');
	vector.x = ft_atof(parts[0]);
	vector.y = ft_atof(parts[1]);
	vector.z = ft_atof(parts[2]);
	ft_free_strarray(parts);
	return (vector);
}

t_vector			parse_geo(char *line)
{
	t_vector	vector;
	char		**parts;

	parts = ft_strsplit(line + 1, ' ');
	vector.x = ft_atof(parts[0]);
	vector.y = ft_atof(parts[1]);
	vector.z = ft_atof(parts[2]);
	ft_free_strarray(parts);
	return (vector);
}

t_vec2				parse_coord(char *line)
{
	t_vec2		vector;
	char		**parts;

	parts = ft_strsplit(line + 1, ' ');
	vector.u = ft_atof(parts[0]);
	vector.v = ft_atof(parts[1]);
	ft_free_strarray(parts);
	return (vector);
}
