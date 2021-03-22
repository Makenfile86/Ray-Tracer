/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:41:38 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/06 13:43:28 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int							hook_expose(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	return (0);
}

static void					put_pixel(t_data *data, int x, int y, t_color color)
{
	int						i;

	i = (x * data->bits_per_pixel / 8) + (y * data->size_line);
	data->data_addr[i] = color.channel[3];
	data->data_addr[++i] = color.channel[2];
	data->data_addr[++i] = color.channel[1];
	data->data_addr[++i] = color.channel[0];
}

void						put_color(t_data *data, t_rgb rgb, int x, int y)
{
	t_color					color;

	color.channel[0] = 0;
	color.channel[1] = (int8_t)((min(rgb.red * 255, 255)));
	color.channel[2] = (int8_t)((min(rgb.green * 255, 255)));
	color.channel[3] = (int8_t)((min(rgb.blue * 255, 255)));
	put_pixel(data, x, y, color);
}

void						draw(t_data *data)
{
	int						y;
	int						x;
	int						height;

	y = data->start_line;
	height = data->finish_line;
	while (y < height)
	{
		x = 0;
		while (x < WIDTH)
		{
			get_color(data, x, y);
			x++;
		}
		y++;
	}
}
