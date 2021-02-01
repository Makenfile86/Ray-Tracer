#include "rt.h"

void			init_model(t_data *data, int e)
{

	ft_putnbr(e);
	data->obj[e].num_geometry = 0;
	data->obj[e].geometry = NULL;
	data->obj[e].num_coordinates = 0;
	data->obj[e].coordinates = NULL;
	data->obj[e].num_normals = 0;
	data->obj[e].normals = NULL;
	data->obj[e].num_polygonals = 0;
	data->obj[e].polygonals = NULL;
	data->modelnbr += 1;
	data->obj[e] = init_obj(&data->obj[e], &data->objnbr);
}

    void		copy_model_data(t_data *data, char *str, int x, int e)
{
	//ft_putendl("moikka");
    if (x == 0)
    {
		ft_putendl("MONTAKOOO");
	ft_putendl(str);
      data->obj[e].model.name = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
    ft_strcpy(data->obj[e].model.name, str);
    }
    if (x == 1)
		data->obj[e].model.xyz.x = ft_atoi(str);
	else if (x == 2)
	data->obj[e].model.xyz.y = ft_atoi(str);
	else if (x == 3)
		data->obj[e].model.xyz.z = ft_atoi(str);
	else if (x == 4)
		data->obj[e].model.rgb2.red = ft_atoi(str);
	else if (x == 5)
		data->obj[e].model.rgb2.green = ft_atoi(str);
	else if (x == 6)
		data->obj[e].model.rgb2.blue = ft_atoi(str);
	else if (x == 7)
		data->obj[e].model.rot.x = ft_atoi(str);
	else if (x == 8)
		data->obj[e].model.rot.y = ft_atoi(str);
	else if (x == 9)
		data->obj[e].model.rot.z = ft_atoi(str);
	else if (x == 10)
		data->obj[e].model.mater = ft_atoi(str);
        else
        data->obj[e].model.size = ft_atoi(str);
        

//if (x == 10)
//ft_putnbr(data->obj[e].model->size);
}
