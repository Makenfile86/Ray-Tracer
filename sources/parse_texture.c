/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:51:22 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:50:31 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				validate_file(char *txt_name, char **path)
{
	int			fd;
	char		*tmp_path1;
	char		*tmp_path2;
	char		*tmp_path3;
	char		*filename;

	tmp_path1 = ft_strdup("./resources/");
	tmp_path2 = ft_strdup(".ppm");
	tmp_path3 = ft_strjoin(tmp_path1, txt_name);
	filename = ft_strjoin(tmp_path3, tmp_path2);
	free(tmp_path1);
	free(tmp_path2);
	free(tmp_path3);
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		close(fd);
		free(filename);
		return (0);
	}
	*path = ft_strdup(filename);
	close(fd);
	free(filename);
	return (1);
}

unsigned char	*fourth_channel_padding(unsigned char *texture,
		int width, int height)
{
	int			i;

	i = 0;
	while (i < width * height)
	{
		texture[i * 4 + 0] = 1;
		texture[i * 4 + 1] = 1;
		texture[i * 4 + 2] = 1;
		texture[i * 4 + 3] = 1;
		i++;
	}
	return (texture);
}

static int		validate_format(int fd)
{
	char		*line;

	if ((get_next_line(fd, &line)) == 1)
	{
		if (line[0] == 'P' && line[1] == '6')
			ft_putendl("Loading new texture");
		else
		{
			ft_putendl("Wrong texture format, not loaded");
			free(line);
			return (0);
		}
		free(line);
		return (1);
	}
	return (0);
}

static char		*get_res_line(int fd)
{
	int			i;
	char		*line;

	i = 0;
	while (i < 2 && ((get_next_line(fd, &line)) == 1))
	{
		if (i == 0)
			free(line);
		i++;
	}
	return (line);
}

static void		get_resolution(int fd, double *x, double *y)
{
	char		*line;
	char		*resolution;
	int			h;
	int			i;

	i = 0;
	h = 0;
	line = get_res_line(fd);
	resolution = (char *)malloc(sizeof(char) * ft_strlen(line));
	while ((ft_isdigit(line[i]) == 1) && line[i] != '\0')
	{
		resolution[i] = line[i];
		i++;
	}
	resolution[i] = '\0';
	*x = ft_atoi(resolution);
	i++;
	while (ft_isdigit(line[i] == 1))
		resolution[h++] = line[i++];
	resolution[i] = '\0';
	*y = ft_atoi(resolution);
	free(line);
	free(resolution);
}

unsigned char	*init_texture(unsigned char *texture, char *path, t_res *res)
{
	int			fd;
	int			y;

	y = 0;
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		if (!(validate_format(fd)))
			return (NULL);
		close(fd);
		if ((fd = open(path, O_RDONLY)) > 0)
		{
			get_resolution(fd, &res->x, &res->y);
			close(fd);
			if (!(texture = (unsigned char*)malloc(sizeof(unsigned char)
							* res->x * res->y * 4)))
				memory_allocation_fail();
			texture = fourth_channel_padding(texture, res->x, res->y);
			return (texture);
		}
	}
	return (NULL);
}

unsigned char	*parse_ppm(unsigned char *texture, char *path, t_res *res)
{
	int			fd;
	char		text_data[1];
	int			i;
	int			ret;
	int			x;

	x = 0;
	i = 0;
	texture = init_texture(texture, path, res);
	if (texture != NULL)
	{
		if ((fd = open(path, O_RDONLY)) > 0)
		{
			while ((ret = read(fd, text_data, 1)) > 0 &&
					i < res->x * res->y * 4)
			{
				if (x % 3 == 0)
					i++;
				x++;
				texture[i++] = text_data[0];
			}
		}
		close(fd);
	}
	return (texture);
}
