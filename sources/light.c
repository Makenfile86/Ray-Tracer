/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:09:10 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:45:35 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "stdio.h"
#include "math.h"

static double		get_lambert(t_data *data, t_vector target,
		t_vector newstart, t_vector dist)
{
	t_ray		lightray;
	double		lambert;
	double		lambert_scale;
	

	lambert_scale = (data->scene->lambert / 1.8);
	if (lambert_scale < 1)
	lambert_scale = 1;
		//if (data->hit.preobj_mater == 4)
	//{
		//lambert_scale = 5;
		//data->light_scale *= 1;
	//}
	lightray.start = newstart;
	lightray.target = vectorscale((lambert_scale / (data->hit.t)), dist);
	//if (data->hit.mater == 4)
	//data->light_scale *= 1.15;
	lambert = vectordot(lightray.target, target) * data->light_scale;
	data->light_scale *= 0.9;
	//data->hit.mater == 4
	//data->light_scale *= (data->scene->light_scale / 5.8);
	//if (data->hit.texture.type == 2)
	//data->light_scale *= (data->scene->light_scale / 7.5);
	return (lambert);
}

static t_vector		get_dist(t_vector light_pos, t_vector newstart)
{
	t_vector	dist;

	dist = (vector_minus(light_pos, newstart));
	return (dist);
}
/*
static t_material	get_material(t_data *data, int i)
{
	t_material	material;

	material.diffuse_red = ((double)data->spot->power[i] / 100);
	material.diffuse_green = ((double)data->spot->power[i] / 100);
	material.diffuse_blue = ((double)data->spot->power[i] / 100);
	if ((ft_strcmp(data->hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter)
	{
		material.diffuse_red = 0.05;
		material.diffuse_green = 0.05;
		material.diffuse_blue = 0.05;
	}
	return (material);
}
*/
/*
static double mix(double a, double b, double value)
{
	return (a * (1 - value) + b * value)
}
*/
static t_material	get_material(t_data *data, int i)
{
	t_material	material;

/*
if (data->hit.mater == 4 || data->hit.preobj_mater == 4)
material = mirror_effect(data, i);
*/
if (data->hit.texture.type == 2)
{
	material.diffuse_red = ((double)data->spot->power[i] / 100);
	material.diffuse_green = ((double)data->spot->power[i] / 100);
	material.diffuse_blue = ((double)data->spot->power[i] / 100);
}
else 
{
	if ((data->iter != data->org_iter) && (ft_strcmp(data->hit.obj_name, "plane") == 0) && data->hit.preobj_mater != 4)
	{
		material.diffuse_red = ((double)data->spot->power[i] / 500);
		material.diffuse_green = ((double)data->spot->power[i] / 500);
		material.diffuse_blue = ((double)data->spot->power[i] / 500);
	}
	else
	{
	material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);
	}
}
/*
if ((ft_strcmp(data->hit.obj_name, "sphere") == 0) &&
			data->iter == data->org_iter && data->hit.mater == 4)
			{
				material.diffuse_red = 0;
		material.diffuse_green = 0;
		material.diffuse_blue = 0;
			}
*/

if (data->hit.mater == 4 || data->hit.preobj_mater == 4)
material = mirror_effect(data, i);
if (data->hit.mater == 3 || data->hit.preobj_mater == 3)
material = glass_effect(data, i);

if ((ft_strcmp(data->hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter && data->hit.preobj_mater < 3)
	{
		material.diffuse_red = 0.05;
		material.diffuse_green = 0.05;
		material.diffuse_blue = 0.05;
	}

if ((ft_strcmp(data->hit.preobj_name, "plane") == 0) && (ft_strcmp(data->hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter)
	{
		if (data->hit.preobj_mater == 4)
		{
				material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);
		}
		else
		{
		material.diffuse_red = 0;
		material.diffuse_green = 0;
		material.diffuse_blue = 0;
		}
	}

	//if ((ft_strcmp(data->hit.preobj_name, "plane") == 0) && data->hit.preobj_mater == 4)
	//ft_putendl("ei pitais olla");
	/*
	if ((ft_strcmp(data->hit.preobj_name, "plane") == 0) &&
			data->iter != data->org_iter && data->hit.preobj_mater != 4)
	{
		material.diffuse_red = 0.05;
		material.diffuse_green = 0.05;
		material.diffuse_blue = 0.05;
	}
	*/


/*

else if (data->hit.texture.type > 1 && data->iter != data->org_iter)
	{
		material.diffuse_red = 0.05;
		material.diffuse_green = 0.05;
		material.diffuse_blue = 0.05;
	}
	*/
	/*
		if ((ft_strcmp(data->hit.preobj_name, "plane") == 0) && (ft_strcmp(data->hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter)
	{
		material.diffuse_red = 0;
		material.diffuse_green = 0;
		material.diffuse_blue = 0;
	}
*/
//if ((ft_strcmp(data->hit.preobj_name, "plane") == 0) && data->hit.preobj_mater == 4)
//	{
//		ft_putendl("ei pitais olla");
//	}
	return (material);
}
/*
static double ft_min_max(double value, double min, double max)
{
	double result;
	if (value < min)
	result = min;
	else if (value > max)
	result = max;
	else
	result = value;
	return (result);

}
*/
static double calculate_checker_size(t_data *data, char *obj_name)
{
	double size;
	int i;
	double scale;

	scale = data->hit.texture.size;
	i = data->hit.obj_idx;
	if (ft_strcmp(obj_name, "cone") == 0)
		size = 0.5;
	else if (ft_strcmp(obj_name, "sphere") == 0)

		size = (0.25 * data->sphere->radius[i] / 5 * (scale / 2));
	
	
	else if (ft_strcmp(obj_name, "plane") == 0)
	size = 0.5;
	else 
	size = 0.5;
	return (size);
}

static t_rgb2 assign_pattern_checker(t_data *data, t_vec2 uv, t_rgb2 obj_color)
{
	
		double	pat_size;
	double u;
	double v;
	u = uv.u;
	v = uv.v;
	//ft_putendl("taaallaa");
	pat_size = calculate_checker_size(data, data->hit.obj_name);
	//pat_size = 0.5;

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

t_rgb2 assign_ppm_texture(t_data *data, unsigned char *ppm_image, t_vec2 uv)
{

	t_rgb2 color;
	double x;
	double y;
	int width;
	int height;
	//uv.v = (1 - uv.v);
	int i;
	//int g;
	//ft_putendl("moikka");
	width = 0;
	height = 0;
	if (data->hit.texture.type == 2 || data->hit.texture.type == 5)
	{
		//uv.v = (1 - uv.v);
		//width = 880;
		//height = 602;2551 1701
		width = 4000;
		height = 4000;
	}
	if (data->hit.texture.type == 5)
	{
		width = 2000;
		height = 2000;
	}
	if (data->hit.texture.type == 3 || data->hit.texture.type == 4)
	{	
		//if (data->hit.texture.type == 2)
		//uv.v = (1 - uv.v);
		width = 512;
		height = 512;
	}
	
	x = uv.u * (width - 1);
	y = uv.v * (height - 1);
	x = round(x);
	y = round(y);

	i = y * (4 * height) + x * 4;
	
if (data->hit.texture.type == 3 || data->hit.texture.type == 4)
{

 color.red = ((int)ppm_image[i + 2]);
 color.green = ((int)ppm_image[i + 3]);
 color.blue = ((int)ppm_image[i + 1]);
}
else
{
	 color.red = ((int)ppm_image[i + 1]);
 color.green = ((int)ppm_image[i + 2]);
 color.blue = ((int)ppm_image[i + 3]);
}

	return (color);
}
/*
static t_rgb2 cylinder_checker(t_data *data, t_vec2 uv, t_rgb2 obj_color)
{
	int u2;
	int v2;
//printf("\nX: %f\n", u);
//printf("\nY: %f\n", v);
	u2 = floor(uv.u * 300);
	v2 = floor(uv.v * 200);
	if (fmod((u2 + v2), 2) == 0)
	return (obj_color);
	else
	return (data->hit.texture.color);
}
*/
/*

*/
/*
static t_rgb2 uv_pattern_checkers(double u, double v, t_rgb2 org, t_rgb2 second)
{
	double	pat_size;
	//u = floor(u);
	//v = floor(v);
	
	pat_size = ft_min_max(0.5, 0.01, 20);

//printf("V: \n%f\n", v);
	//printf("U: \n%f\n", u);
	if (fmod(u, pat_size * 2) < pat_size)
	{
		if (fmod(v, pat_size * 2) < pat_size)
			return (org);
		else
			return (second);
	}
	else
	{
		if (fmod(v, pat_size * 2) < pat_size)
			return (second);
		else
			return (org);
	}
	//ft_putendl("ala tuu tanne");
	return (org);
}
*/

static t_rgb		get_light_intensity(t_data *data, int h)
{
	t_rgb		intensity;
	t_rgb2		color;

	int i;
		 	
	
	i = data->hit.obj_idx;
	if (ft_strcmp(data->hit.obj_name, "cone") == 0)
		color = data->cone->rgb2[h];
	else if (ft_strcmp(data->hit.obj_name, "sphere") == 0)
	{	
		if (data->hit.texture.type > 1)
			color = assign_ppm_texture(data, data->sphere->texture[i].txt_ppm, data->sphere->uv[i]);
		else if (data->hit.texture.type == 1)
		{
			color = assign_pattern_checker(data, data->sphere->uv[i], data->sphere->rgb2[i]);
		}
		//color = uv_pattern_checkers(data->sphere->uv[i].u, data->sphere->uv[i].v, data->sphere->rgb2[h], data->hit.texture.color);
		else
		{
			//ft_putendl("ala tuu tanne");
			color = data->sphere->rgb2[h];
		}
	}
	else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
	{	
		//if (data->plane->checker[h] == 0)
	if (data->hit.texture.type > 1)
			color = assign_ppm_texture(data, data->plane->texture[i].txt_ppm, data->plane->uv[i]);
		else if (data->hit.texture.type == 1)
		color = assign_pattern_checker(data, data->plane->uv[i] , data->plane->rgb2[i]);
		else
			color = data->plane->rgb2[h];
			
		//}
		
		/*else
		{
		if (x_pattern > 37 && y_pattern < 37)
		{
		color = data->plane->rgb2[h];
		}
		else
		{
			color.red = 100;
			color.green = 100;
			color.blue = 100;
		}
		}
		*/
	}
	else if (ft_strcmp(data->hit.obj_name, "cylinder") == 0)
	{
		if (data->hit.texture.type > 1)
			color = assign_ppm_texture(data, data->cylinder->texture[i].txt_ppm, data->cylinder->uv[i]);
		else if (data->hit.texture.type == 1)
		color = assign_pattern_checker(data, data->cylinder->uv[i] , data->cylinder->rgb2[i]);
		else
			color = data->cylinder->rgb2[h];
			
	}
		else if (ft_strcmp(data->hit.obj_name, "cone") == 0)
	{
		if (data->hit.texture.type > 1)
			color = assign_ppm_texture(data, data->cone->texture[i].txt_ppm, data->cone->uv[i]);
		else if (data->hit.texture.type == 1)
		color = assign_pattern_checker(data, data->cone->uv[i] , data->cone->rgb2[i]);
		else
			color = data->cone->rgb2[h];
			
	}
		//pattern = mix(color, color * 0.8, pattern); 
	//	data->pattern = pattern;
	
	//if (data->hit.texture.type == 2)
	//{
	//	intensity.red = (double)color.red;
		//intensity.green = (double)color.green;
		//intensity.blue = (double)color.blue;
	//}
	//else
	//{
		
	intensity.red = ((double)color.red / (fabs(data->scene->color_intensity - 9.5) * 25));
	intensity.green = ((double)color.green / (fabs(data->scene->color_intensity - 9.5) * 25));
	intensity.blue = ((double)color.blue / (fabs(data->scene->color_intensity - 9.5) * 25));
	//if (data->hit.refraction == 1)
	//{
	//intensity.red *= data->hit.fresnel;
	//intensity.green *= data->hit.fresnel;
	//intensity.blue *= data->hit.fresnel;
	//}
	//}
	//intensity.red = fabs(intensity.red);
	//intensity.green = fabs(intensity.green);
	//intensity.blue = fabs(intensity.blue);
	return (intensity);
}

t_rgb				get_light(t_data *data, t_rgb rgb, t_ray ray, int i)
{
	t_material	material;
	t_vector	light_pos;
	t_rgb		intensity;
	int			h;
	

	h = data->hit.obj_idx;
	light_pos = copy_lightpos(data, i);
	intensity = get_light_intensity(data, h);
		if (vectordot(ray.target, get_dist(light_pos, ray.newstart)) <= 0.0f)
		return (rgb);
	data->hit.t = sqrt(vectordot(get_dist(light_pos, ray.newstart),
				get_dist(light_pos, ray.newstart)));
	if (data->hit.t <= 0.0f)
		return (rgb);
		//if (data->hit.texture.type != 2)
		//{
	material = get_material(data, i);
	/*
	if (((data->iter + 1) == data->org_iter) && data->hit.mater == 3 && data->hit.fresnel != 1)
	{
	rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red * (1 - data->hit.fresnel);
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green * (1 - data->hit.fresnel);
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue * (1 - data->hit.fresnel);
	//	printf("\n%f\n", data->hit.fresnel);
	}
	*/
	/*
	else if (data->iter != data->org_iter && data->hit.preobj_mater == 3)
	{
		rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red * data->hit.fresnel;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green * data->hit.fresnel;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue * data->hit.fresnel;
		
}
*/
	
		rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue;
		

	//	}
	//else
	//{
	
		//	rgb.red = intensity.red;
			//get_dist(light_pos, ray.newstart));
		//rgb.green = intensity.green;
			//get_dist(light_pos, ray.newstart));
		//rgb.blue = intensity.blue;
			//get_dist(light_pos, ray.newstart));
	//}
	
	

	return (rgb);
}
