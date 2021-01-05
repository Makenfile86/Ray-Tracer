#include "rtv1.h"
#include "../libft/libft.h"
#include "stdio.h"


void			init_scene(t_data *data)
{
	data->org_iter = data->scene->ref_iter;
		//if (data->scene->background == 1)
	//{
		//data->hit.texture.type = 9;
		//parse_ppm(data, 9);
		//draw_background(data);
		//data->hit.texture.type = 0;
	//}
}

void		copy_scene_data(t_data *data, char *str, int x)
{
	if (x == 0)
	data->scene->background = ft_atoi(str);
	else if (x == 1)
		data->scene->lambert = ft_atoi(str);
        else if (x == 2)
		data->scene->light_scale = ft_atoi(str);
	else if (x == 3)
		data->scene->shadows = ft_atoi(str);
	else if (x == 4)
		data->scene->ref_iter = ft_atoi(str);
    else if (x == 5)
        data->scene->color_intensity = ft_atoi(str);
    else
        data->scene->reflection = ft_atoi(str);
   
}
