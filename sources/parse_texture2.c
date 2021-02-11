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
