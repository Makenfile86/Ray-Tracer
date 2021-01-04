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

#include "../libft/libft.h"
#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_data	*data;
	//int		fd;
	void	*mlx_ptr;

	//fd = 0;
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

ft_putendl("valmis");
	mlx_loop(data->mlx);
}
