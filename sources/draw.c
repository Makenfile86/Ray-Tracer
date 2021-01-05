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

#include "rtv1.h"
#include "stdio.h"

static void					put_pixel(t_data *data, int x, int y, t_color color)
{
	int					i;

	i = (x * data->bits_per_pixel / 8) + (y * data->size_line);

	data->data_addr[i] = color.channel[3];
	data->data_addr[++i] = color.channel[2];
	data->data_addr[++i] = color.channel[1];
	data->data_addr[++i] = color.channel[0];
	
	
}

void						put_color(t_data *data, t_rgb rgb, int x, int y)
{
	t_color			color;

		if (data->hit.texture.type == 9)
		{
			color.channel[0] = 0;
		color.channel[3] = (int)(min(rgb.red, 255));
	color.channel[2] = (int)(min(rgb.green, 255));
	color.channel[1] = (int)(min(rgb.blue, 255));
	}
	else
	{
	
	color.channel[0] = 0;
	color.channel[1] = (int8_t)((min(rgb.red * 255, 255)));
	color.channel[2] = (int8_t)((min(rgb.green * 255, 255)));
	color.channel[3] = (int8_t)((min(rgb.blue * 255, 255)));
	}

	put_pixel(data, x, y, color);
}

void						draw(t_data *data)
{
	
	int				y;
	int				x;
	t_color color;
	color.channel[0] = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			get_color(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

t_rgb get_background_color(t_data *data, int x, int y)
{
	t_rgb rgb;
	int i;
	
	i = y * (4 * WIDTH) + x * 4;
	rgb.red = data->texture->background_ppm[i + 1];
		rgb.green = data->texture->background_ppm[i + 2];
			rgb.blue = data->texture->background_ppm[i + 3];
			return (rgb);
}

void		draw_background(t_data *data)
{
	int x;
	int y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH )
		{
			put_color(data, get_background_color(data, x, y), x, y);
			x++;
		}
		y++;
	}
}
