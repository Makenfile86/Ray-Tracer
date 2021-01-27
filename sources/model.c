#include "rt.h"

void			init_model(t_data *data)
{

	
	data->obj->num_geometry = 0;
	data->obj->geometry = NULL;
	data->obj->num_coordinates = 0;
	data->obj->coordinates = NULL;
	data->obj->num_normals = 0;
	data->obj->normals = NULL;
	data->obj->num_polygonals = 0;
	data->obj->polygonals = NULL;
	init_obj(data);
}

    void		copy_model_data(t_data *data, char *str, int x, int e)
{
	//ft_putendl("moikka");
    if (x == 0)
    {
	ft_putendl(str);
      data->obj->model->name = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
    ft_strcpy(data->obj->model->name, str);
    }
    if (x == 1)
		data->obj->model->xyz[e].x = ft_atoi(str);
	else if (x == 2)
	data->obj->model->xyz[e].y = ft_atoi(str);
	else if (x == 3)
		data->obj->model->xyz[e].z = ft_atoi(str);
	else if (x == 4)
		data->obj->model->rgb2[e].red = ft_atoi(str);
	else if (x == 5)
		data->obj->model->rgb2[e].green = ft_atoi(str);
	else if (x == 6)
		data->obj->model->rgb2[e].blue = ft_atoi(str);
	else if (x == 7)
		data->obj->model->rot[e].x = ft_atoi(str);
	else if (x == 8)
		data->obj->model->rot[e].y = ft_atoi(str);
	else if (x == 9)
		data->obj->model->rot[e].z = ft_atoi(str);
	else if (x == 10)
		data->obj->model->mater = ft_atoi(str);
        else
        data->obj->model->size = ft_atoi(str);
        

//if (x == 10)
//ft_putnbr(data->obj->model->size);
}
