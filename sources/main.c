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


int		main(int argc, char **argv)
{
	t_data	*data;
	
	void	*mlx_ptr;
	if (argc != 2)
		wrong_scene_name();
	data = NULL;
	data = allocate_memory(data);
	data->scene_name = argv[1];
		mlx_ptr = mlx_init();
		data->mlx = mlx_ptr;
		
	
	read_scene(data);
	
	//ft_putendl("zoe");
	
	//ft_putendl("moikka");
	//ft_putnbr(data->obj->num_polygonals);
	//ft_putnbr(data->obj->polygonals[0].ve[0].x);
	//printf("hoes hoes");
//printf("%zu tama on tama luku /n", data->obj->num_polygonals);
//	ft_putnbr(data->obj->num_normals);
	mlx_key_hook(data->win, keypressed, data);
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
ft_putendl("valmis");
//free(data->texture->moon_ppm);
	mlx_loop(data->mlx);
	free(data);
}
