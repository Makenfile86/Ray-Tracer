#include "rt.h"
#include "math.h"
#include "stdio.h"

double pat_size(double scale, char *obj_name, int radius)
{
	double size;
	
	//double scale;

	//scale = dahit.texture.size;
	//i = data->hit.obj_idx;
	//ft_putendl(obj_name);
	if (radius < 1)
	radius = 1;
	if (ft_strcmp(obj_name, "sphere") == 0)
	size = (0.125 * radius / 5 * (scale / 2));
	else if (ft_strcmp(obj_name, "plane") == 0)
	size = 0.5;
	else 
	size = (0.1 / radius * scale);
	return (size);
}


t_rgb2 cyl_checker_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
pat_size = 1;
double u2;
double v2;
//double res;
//double res2;
//uv.u *= 6;
u2 = floor(uv.u * 500);
v2 = floor(uv.v * 50);

//printf("U: %f\n", u2);
//if (uv.v > 1)
//printf("V: %f\n", v2);
//function uv_pattern_at(checkers, u, v)
  //let u2 ← floor(u * checkers.width)
  //printf("MOD eka %f\n", (fmod((u2 + v2), 2)));
  //let v2 ← floor(v * checkers.height)
//res = u2 + v2;
//printf("%f\n", res);
//res2 = fmod(res, 1.0);
//printf("%f\n", res2);
 if ((fmod((u2 + v2), 2)) == 0)
 
	  return (obj_color);
 
 else
  
	   return (texture_color);
  

}


t_rgb2 checker_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
   
   
   if (fmod(uv.u, pat_size * 2) < pat_size)
	{
		if (fmod(uv.v, pat_size * 2) < pat_size)
			return (obj_color);
		else
			return (texture_color);
	}
	else
	{
		if (fmod(uv.v, pat_size * 2) < pat_size)
			return (texture_color);
		else
			return (obj_color);
	}


} 

t_rgb2 split_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
   // double pat_size;
   // pat_size = calculate_checker_size(data, data->hit.obj_name);
 pat_size = 0;
 uv.v /= 6.0;
// printf("%d\n", obj_color.red);
  	if (uv.v < 0.5)
	  return (obj_color);
	  else
	return (texture_color);
	  

} 

t_rgb2 hstripe_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
   // double pat_size;
   // pat_size = calculate_checker_size(data, data->hit.obj_name);
//printf("fmod pre %f\n", uv.v);
//printf("fmod post %f\n", fmod(uv.v, pat_size * 2));
//if (uv.u > 1)
//printf("U: %f\n", uv.u);
//if (uv.v > 1)
//printf("V: %f\n", uv.v);
 
  	if (fmod(uv.v, pat_size * 2) < pat_size)
	return (obj_color);
	else
	return (texture_color);
		

} 

t_rgb2 gradient_pattern(t_vec2 uv, t_rgb2 obj_color, double pat_size)
{
   
  	obj_color.red += (min(fabs(obj_color.red * uv.v * uv.v * pat_size * 0.8), 255));
	obj_color.green += (min(fabs(obj_color.green * uv.v * uv.v * pat_size * 0.8), 255));
	obj_color.blue += (min(fabs(obj_color.blue * uv.v * uv.v * pat_size * 0.8), 255));

    return (obj_color);

} 


t_rgb2 vstripe_pattern(t_vec2 uv, t_rgb2 obj_color, t_rgb2 texture_color, double pat_size)
{
	
	
 if (fmod(uv.u, pat_size * 2) < pat_size)
			return (obj_color);
		else
			return (texture_color);
			



}

t_rgb2 ppm_texture(int width, int height, unsigned char *ppm_image, t_vec2 uv)
{

	t_rgb2 color;
	double x;
	double y;

	int i;


	
	x = uv.u * (width - 1);
	y = uv.v * (height - 1);
	x = round(x);
	y = round(y);

	i = y * (4 * height) + x * 4;

	 color.red = ((int)ppm_image[i + 1]);
 color.green = ((int)ppm_image[i + 2]);
 color.blue = ((int)ppm_image[i + 3]);


	return (color);
}