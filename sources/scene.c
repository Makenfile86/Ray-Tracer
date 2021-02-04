#include "rt.h"



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

void		copy_scene_data(t_data *data, char **parts)
{

	data->scene->background = ft_atoi(parts[0]);

		data->scene->lambert = ft_atoi(parts[1]);

		data->scene->light_scale = ft_atoi(parts[2]);

		data->scene->shadows = ft_atoi(parts[3]);

		data->scene->ref_iter = ft_atoi(parts[4]);
  
        data->scene->color_intensity = ft_atoi(parts[5]);
 
        data->scene->reflection = ft_atoi(parts[6]);
   
}
