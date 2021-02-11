/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:18:21 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:39 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			*if_negative(char *line, char *str, int *i, int *y)
{
	if (line[*i] == '-')
	{
		if (str[0] != '\0')
			data_read_error();
		str[0] = '-';
		*i += 1;
		*y = 1;
	}
	return (str);
}

static void		check_name(t_data *data, char *data_name, char *line)
{
	if ((ft_strcmp(data_name, "SPHERE") == 0) && data->sphere->nbr < 30)
		parse_obj(line, data, &data->sphere->nbr, "object");
	else if ((ft_strcmp(data_name, "CYLINDER") == 0) && data->cylinder->nbr
			< 30)
		parse_obj(line, data, &data->cylinder->nbr, "object");
	else if ((ft_strcmp(data_name, "CONE") == 0) && data->cone->nbr < 30)
		parse_obj(line, data, &data->cone->nbr, "object");
	else if ((ft_strcmp(data_name, "SPOT") == 0) && data->spot->nbr < 30)
		parse_obj(line, data, &data->spot->nbr, "spot");
	else if ((ft_strcmp(data_name, "PLANE") == 0) && data->cone->nbr < 30)
		parse_obj(line, data, &data->plane->nbr, "object");
	else if (ft_strcmp(data_name, "SCENE") == 0)
		parse_obj(line, data, 0, "scene");
	else if (ft_strcmp(data_name, "CAMERA") == 0)
		parse_obj(line, data, 0, "camera");
	else if ((ft_strcmp(data_name, "MODEL") == 0))
	{
		parse_obj(line, data, 0, "model");
	}
}

static void		get_data(t_data *data, int fd)
{
	int			i;
	char		*line;
	int			line_count;

	line_count = 0;
	i = 0;
	while (((get_next_line(fd, &line)) == 1) && line_count < 50)
	{
		line_count++;
		if (line[i] == '*')
		{
			data->obj_name = parse_name(line, data->obj_name);
			if (get_next_line(fd, &line) == 1)
				check_name(data, data->obj_name, line);
			ft_memset(data->obj_name, 0, ft_strlen(data->obj_name));
		}
		if (line[i] != '*')
			free(line);
	}
}

int				read_scene(t_data *data)
{
	int			fd;

	fd = 0;
	if ((fd = open(data->scene_name, O_RDONLY)) > 0)
		init_data(data);
	else
		wrong_scene_name();
	if (!(data->obj_name = (char *)malloc((sizeof(char) * (8 + 1)))))
		memory_allocation_fail();
	get_data(data, fd);
	close(fd);
	init_mlx(data);
	pthread(data);
	return (0);
}
