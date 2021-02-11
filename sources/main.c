/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:17:18 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 13:16:44 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				main(int argc, char **argv)
{
	t_data		*data;
	void		*mlx_ptr;

	if (argc != 2)
		wrong_scene_name();
	data = NULL;
	data = allocate_memory(data);
	data->scene_name = argv[1];
	mlx_ptr = mlx_init();
	data->mlx = mlx_ptr;
	read_scene(data);
	mlx_key_hook(data->win, keypressed, data);
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	mlx_loop(data->mlx);
	free(data);
}
