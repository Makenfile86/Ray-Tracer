#include "rtv1.h"
#include "../libft/libft.h"
#include "stdio.h"



void		copy_data(t_data *data, char *str, int *x, int e)
{
    int i;

    i = *x;
    

	if (ft_strcmp(data->obj_name, "SPHERE") == 0)
    copy_sphere_data(data, str, i, e);
    else if (ft_strcmp(data->obj_name, "CYLINDER") == 0)
    copy_cylinder_data(data, str, i, e);
   else  if (ft_strcmp(data->obj_name, "CONE") == 0)
    copy_cone_data(data, str, i, e);
    else if (ft_strcmp(data->obj_name, "PLANE") == 0)
    copy_plane_data(data, str, i, e);
     else if (ft_strcmp(data->obj_name, "SPOT") == 0)
    copy_spot_data(data, str, i, e);
        else if (ft_strcmp(data->obj_name, "CAMERA") == 0)
    copy_camera_data(data, str, i);
    else if (ft_strcmp(data->obj_name, "SCENE") == 0)
    copy_scene_data(data, str, i);
    *x += 1;
}

