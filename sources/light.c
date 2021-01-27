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

#include "rt.h"
#include "math.h"
/*
static t_rgb2 checker_pattern(t_data *data, t_vec2 uv, t_rgb2 obj_color)
{
	
		double	pat_size;
	double u;
	double v;
	u = uv.u;
	v = uv.v;
	pat_size = calculate_checker_size(data, data->hit.obj_name);
	


data->test_x = 0;
obj_color.red = (min(fabs(255 * uv.u) + ((255 * (1 - uv.v))), 255));
	obj_color.green = (min(fabs((255 * uv.u) + ((255 * (1 - uv.v))) * 0.1), 255));
	obj_color.blue = (min(fabs((255 * uv.u) + ((255 * (1 - uv.v))) * 0.2), 255));
	printf("\n%d\n", obj_color.red);
	ft_putchar('\n');

	
	if (fmod(u, pat_size * 2) < pat_size)
	return (obj_color);
		else
			return (data->hit.texture.color);
			


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
*/
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




	if ((data->iter != data->org_iter) && (ft_strcmp(data->hit.obj_name, "plane") == 0) && data->hit.preobj_mater != 4 && data->hit.was_refract != 1)
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

if ((ft_strcmp(data->hit.preobj_name, "plane") == 0) && data->hit.mater == 4)
{

material.diffuse_red = ((double)data->spot->power[i] / 1000);
		material.diffuse_green = ((double)data->spot->power[i] / 1000);
		material.diffuse_blue = ((double)data->spot->power[i] / 1000);
}
else if (data->hit.mater == 4)
material = mirror_effect(data, i);
if (data->hit.preobj_mater == 3)
material = glass_effect(data, i);

if ((ft_strcmp(data->hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter && data->hit.preobj_mater < 3 && data->hit.was_refract != 1)
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
	if (data->hit.was_refract == 1)
	{
		material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);
	}
	//liikaa heijastusta tuli peilista seinaa
if (ft_strcmp(data->hit.texture.name, "redmarble") == 0)
{
	material.diffuse_red = ((double)data->spot->power[i] / 55);
	material.diffuse_green = ((double)data->spot->power[i] / 75);
	material.diffuse_blue = ((double)data->spot->power[i] / 225);
}




	return (material);
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
	
		if (data->hit.texture.txt_loaded == TRUE)
		{	
			
			color = ppm_texture(data, data->sphere->texture[i].txt_ppm, data->sphere->uv[i]);
		}
		else if ((ft_strcmp(data->hit.texture.name, "checker") == 0))
			color = checker_pattern(data, data->sphere->uv[i], data->sphere->rgb2[i]);
		else if ((ft_strcmp(data->hit.texture.name, "vstripe") == 0))
		color = vstripe_pattern(data->sphere->uv[i], data->sphere->rgb2[i], data->hit.texture.color, pattern_size(data, data->hit.obj_name));
		else if ((ft_strcmp(data->hit.texture.name, "hstripe") == 0))
		color = hstripe_pattern(data->sphere->uv[i], data->sphere->rgb2[i], data->hit.texture.color, pattern_size(data, data->hit.obj_name));
		else if ((ft_strcmp(data->hit.texture.name, "gradient") == 0))
		color = gradient_pattern(data->sphere->uv[i], data->sphere->rgb2[i], pattern_size(data, data->hit.obj_name));
		else
		color = data->sphere->rgb2[h];
	
	}
	else if (ft_strcmp(data->hit.obj_name, "plane") == 0)
	{	
	if (data->hit.texture.txt_loaded == TRUE)
			color = ppm_texture(data, data->plane->texture[i].txt_ppm, data->plane->uv[i]);
	else if ((ft_strcmp(data->hit.texture.name, "checker") == 0))
			color = checker_pattern(data, data->plane->uv[i], data->plane->rgb2[i]);
		else if ((ft_strcmp(data->hit.texture.name, "vstripe") == 0))
		color = vstripe_pattern(data->plane->uv[i], data->plane->rgb2[i], data->hit.texture.color, pattern_size(data, data->hit.obj_name));
		else if ((ft_strcmp(data->hit.texture.name, "hstripe") == 0))
		color = hstripe_pattern(data->plane->uv[i], data->plane->rgb2[i], data->hit.texture.color, pattern_size(data, data->hit.obj_name));
		else if ((ft_strcmp(data->hit.texture.name, "gradient") == 0))
		color = gradient_pattern(data->plane->uv[i], data->plane->rgb2[i], pattern_size(data, data->hit.obj_name));
		else
		color = data->plane->rgb2[h];
	}
	else if (ft_strcmp(data->hit.obj_name, "cylinder") == 0)
	{
		if (data->hit.texture.txt_loaded == TRUE)
			color = ppm_texture(data, data->cylinder->texture[i].txt_ppm, data->cylinder->uv[i]);
		else if ((ft_strcmp(data->hit.texture.name, "checker") == 0))
			color = checker_pattern(data, data->cylinder->uv[i], data->cylinder->rgb2[i]);
		else if ((ft_strcmp(data->hit.texture.name, "vstripe") == 0))
		color = vstripe_pattern(data->cylinder->uv[i], data->cylinder->rgb2[i], data->hit.texture.color, pattern_size(data, data->hit.obj_name));
		else if ((ft_strcmp(data->hit.texture.name, "hstripe") == 0))
		color = hstripe_pattern(data->cylinder->uv[i], data->cylinder->rgb2[i], data->hit.texture.color, pattern_size(data, data->hit.obj_name));
		else if ((ft_strcmp(data->hit.texture.name, "gradient") == 0))
		color = gradient_pattern(data->cylinder->uv[i], data->cylinder->rgb2[i], pattern_size(data, data->hit.obj_name));
		else
		color = data->cylinder->rgb2[h];
			
	}
		else if (ft_strcmp(data->hit.obj_name, "cone") == 0)
	{
		if (data->hit.texture.txt_loaded == TRUE)
			color = ppm_texture(data, data->cone->texture[i].txt_ppm, data->cone->uv[i]);
		else if (data->hit.texture.type == 1)
		color = checker_pattern(data, data->cone->uv[i] , data->cone->rgb2[i]);
		else
			color = data->cone->rgb2[h];
			
	}
	else if (ft_strcmp(data->hit.obj_name, "triangle") == 0)
	{
	
			  color = data->obj->model->rgb2[0];
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
//if (data->hit.was_refract == 1)
//{
		rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red * data->hit.fresnel;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green * data->hit.fresnel;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue * data->hit.fresnel;
//}
//else 
//{
	/*
	rgb.red += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.red * material.diffuse_red;
	rgb.green += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.green * material.diffuse_green;
	rgb.blue += get_lambert(data, ray.target, ray.newstart,
			get_dist(light_pos, ray.newstart))
		* intensity.blue * material.diffuse_blue;
		*/
//}
	return (rgb);
}
