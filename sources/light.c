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

	lightray.start = newstart;
	lightray.target = vectorscale((lambert_scale / (data->hit.t)), dist);

	lambert = vectordot(lightray.target, target) * data->light_scale;
	data->light_scale *= 0.9;
	
	return (lambert);
}

static t_vector		get_dist(t_vector light_pos, t_vector newstart)
{
	t_vector	dist;

	dist = (vector_minus(light_pos, newstart));
	return (dist);
}

static t_material	get_material(t_data *data, int i)
{
	t_material	material;


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


	return (material);
}

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

	pat_size = calculate_checker_size(data, data->hit.obj_name);


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
	int i;

	width = 0;
	height = 0;
	if (data->hit.texture.type == 2 || data->hit.texture.type == 5)
	{

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

		else
		color = data->sphere->rgb2[h];
	
	}
	else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
	{	
	if (data->hit.texture.type > 1)
			color = assign_ppm_texture(data, data->plane->texture[i].txt_ppm, data->plane->uv[i]);
		else if (data->hit.texture.type == 1)
		color = assign_pattern_checker(data, data->plane->uv[i] , data->plane->rgb2[i]);
		else
			color = data->plane->rgb2[h];
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
		
	intensity.red = ((double)color.red / (fabs(data->scene->color_intensity - 9.5) * 25));
	intensity.green = ((double)color.green / (fabs(data->scene->color_intensity - 9.5) * 25));
	intensity.blue = ((double)color.blue / (fabs(data->scene->color_intensity - 9.5) * 25));
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
	
	material = get_material(data, i);

		rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue;
		

	return (rgb);
}
