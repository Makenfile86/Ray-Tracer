/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:51:22 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:50:31 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		read_obj(t_obj *obj, int fd)
{
	char		*line;
	int			i;

	i = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (ft_strncmp(line, "v ", 2) == 0)
			obj->num_geometry++;
		else if (ft_strncmp(line, "vt", 2) == 0)
			obj->num_coordinates++;
		else if (ft_strncmp(line, "vn", 2) == 0)
			obj->num_normals++;
		else if (ft_strncmp(line, "f ", 2) == 0)
			obj->num_polygonals++;
		free(line);
	}
	malloc_obj(obj, obj->num_geometry, obj->num_coordinates);
	malloc_obj2(obj, obj->num_normals, obj->num_polygonals);
}

static void		put_data(t_obj *obj, size_t i)
{
	obj->polygonals[i].te[0] = vector_minus(obj->polygonals[i].ve[1],
			obj->polygonals[i].ve[0]);
	obj->polygonals[i].te[1] = vector_minus(obj->polygonals[i].ve[2],
			obj->polygonals[i].ve[1]);
	obj->polygonals[i].te[2] = vector_minus(obj->polygonals[i].ve[0],
			obj->polygonals[i].ve[2]);
	obj->polygonals[i].normal = obj->polygonals[i].no[0];
}

static void		parse_poly(t_obj *obj, size_t i, char *line)
{
	char		**parts;
	char		**num;
	size_t		n;
	size_t		j;

	j = 0;
	parts = ft_strsplit(line + 1, ' ');
	while (parts[j] && (num = ft_strsplit(parts[j], '/')))
	{
		if (!num[0] || (n = ft_atoi(num[0])))
			obj->polygonals[i].ve[j] = obj->geometry[n - 1];
		if (!num[1] || (n = ft_atoi(num[1])))
		{
			obj->polygonals[i].uv[j] = obj->coordinates[n - 1];
		}
		if (!num[2] || (n = ft_atoi(num[2])))
		{
			obj->polygonals[i].no[j] = obj->normals[n - 1];
		}
		j++;
		ft_free_strarray(num);
	}
	ft_free_strarray(parts);
	put_data(obj, i);
}

static void		read_obj_data(int fd, t_obj *obj)
{
	char		*line;
	size_t		i[4];
	double		scale;

	scale = obj->model.scale * 0.15;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "v ", 2) == 0)
			obj->geometry[i[0]++] = vec_rot_zyx(vectorscale(scale,
						vectoradd(parse_geo(line + 1), obj->model.xyz)),
						obj->model.rot);
		if (ft_strncmp(line, "vt ", 2) == 0)
			obj->coordinates[i[1]++] = parse_coord(line + 1);
		if (ft_strncmp(line, "vn ", 2) == 0)
			obj->normals[i[2]++] = vec_rot_zyx(parse_normals(line + 2),
			obj->model.rot);
		if (ft_strncmp(line, "f ", 2) == 0)
			parse_poly(obj, i[3]++, line);
		free(line);
	}
}

t_obj			init_obj(t_obj *obj, int *obj_nbr)
{
	int			fd;
	char		*path;

	path = get_objpath(obj->model.name);
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		read_obj(obj, fd);
		close(fd);
	}
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		read_obj_data(fd, obj);
		close(fd);
	}
	if (*obj_nbr < (int)obj->num_polygonals)
		*obj_nbr = obj->num_polygonals;
	free(path);
	return (*obj);
}
