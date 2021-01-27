#include "rt.h"
#include "math.h"

double pattern_size(t_data *data, char *obj_name)
{
	double size;
	int i;
	double scale;

	scale = data->hit.texture.size;
	i = data->hit.obj_idx;
	if (ft_strcmp(obj_name, "cone") == 0)
		size = 0.5;
	else if (ft_strcmp(obj_name, "sphere") == 0)

		size = (0.125 * data->sphere->radius[i] / 5 * (scale / 2));
	
	
	else if (ft_strcmp(obj_name, "plane") == 0)
	size = 0.5;
	else 
	size = 0.5;
	return (size);
}

t_rgb2 vstripe_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
    
   // double pat_size;
   // pat_size = calculate_checker_size(data, data->hit.obj_name);
 if (fmod(uv.u, pat_size * 2) < pat_size)
			return (obj_color);
		else
			return (texture_color);

} 

t_rgb2 hstripe_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
   // double pat_size;
   // pat_size = calculate_checker_size(data, data->hit.obj_name);
 
  	if (fmod(uv.v, pat_size * 2) < pat_size)
			return (obj_color);
		else
			return (texture_color);

} 

t_rgb2 gradient_pattern(t_vec2 uv, t_rgb2 obj_color, double pat_size)
{
   // double pat_size;
   // pat_size = calculate_checker_size(data, data->hit.obj_name);
 

//ft_putendl("moikka");
  	obj_color.red += (min(fabs(obj_color.red * uv.v * uv.v * pat_size * 0.8), 255));
	obj_color.green += (min(fabs(obj_color.green * uv.v * uv.v * pat_size * 0.8), 255));
	obj_color.blue += (min(fabs(obj_color.blue * uv.v * uv.v * pat_size * 0.8), 255));

    return (obj_color);

} 


t_rgb2 checker_pattern(t_data *data, t_vec2 uv, t_rgb2 obj_color)
{
	
		double	pat_size;
	double u;
	double v;
	u = uv.u;
	v = uv.v;
	pat_size = pattern_size(data, data->hit.obj_name);




/*
	
	if (fmod(u, pat_size * 2) < pat_size)
	return (obj_color);
		else
			return (data->hit.texture.color);
			*/
		//data->test_x = 0;
		//obj_color.red += (min(fabs(obj_color.red * uv.v), 255));
	//	obj_color.green += (min(fabs(obj_color.green * uv.v), 255));
		//obj_color.blue += (min(fabs(obj_color.blue * uv.v ), 255));
		/*
obj_color.red = (min(fabs(((obj_color.red * uv.u) + ((obj_color.red * (uv.v))) * 0.75), 255));
	obj_color.green = (min(fabs((obj_color.green * uv.u) + (( obj_color.green * (uv.v))) * 0.75), 255));
	obj_color.blue = (min(fabs((obj_color.blue * uv.u) + ((obj_color.blue * (uv.v)))), 255));
*/
	if (fmod(u, pat_size * 2) < pat_size)
	{
		if (fmod(v, pat_size * 2) < pat_size)
			return (obj_color);
		else
			return (data->hit.texture.color);
	}
	else
	{
		if (fmod(v, pat_size * 2) < pat_size)
			return (data->hit.texture.color);
		else
			return (obj_color);
	}
	
	return (obj_color);

}

t_rgb2 ppm_texture(t_data *data, unsigned char *ppm_image, t_vec2 uv)
{

	t_rgb2 color;
	double x;
	double y;
	int width;
	int height;
	int i;


	/*
	if (data->hit.texture.type == 2 || data->hit.texture.type == 5)
	{

		width = 4000;
		height = 4000;
	}
	//if (data->hit.texture.type == 4)
	//{
	//	width = 1800;
	//	height = 1800;
	//}
	if (data->hit.texture.type == 5)
	{
		width = 2000;
		height = 2000;
	}
	if (data->hit.texture.name == 3)
	{	
		width = 512;
		height = 512;
	}
	*/
width = data->hit.texture.res.x;
height = data->hit.texture.res.y;

	x = uv.u * (width - 1);
	y = uv.v * (height - 1);
	x = round(x);
	y = round(y);

	i = y * (4 * height) + x * 4;
	/*
if ((ft_strcmp(data->hit.texture.name, "earth") == 0) || ft_strcmp(data->hit.texture.name, "moon") == 0)
{

 color.red = ((int)ppm_image[i + 2]);
 color.green = ((int)ppm_image[i + 3]);
 color.blue = ((int)ppm_image[i + 1]);
}
else
{
	*/
	 color.red = ((int)ppm_image[i + 1]);
 color.green = ((int)ppm_image[i + 2]);
 color.blue = ((int)ppm_image[i + 3]);
//}

	return (color);
}