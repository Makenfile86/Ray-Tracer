#include "rt.h"

#include "math.h"

static t_vec2 cylindrical_map(t_data *data, t_vector point)
{
	t_vec2 uv;
	t_vector up;
	t_vector temp;
	t_vector axis;
	double angle;
	double scale;

	int i;
	i = data->hit.obj_idx;

	scale = data->hit.texture.size;
	point = vector_copy(data->hit.normal);
	axis = data->cylinder->axis[i];


up = vectornew(0, 1, 0);
angle = atan(axis.x / vectordot(up, axis));
temp = vec_rot_zyx(axis, vectornew(0, 0, angle * 180 / M_PI));
point = vec_rot_zyx(point, vectornew(0, 0, angle * 180 / M_PI));
angle = atan(temp.z / vectordot(up, temp));
point = vec_rot_zyx(point, vectornew(angle * 180 / M_PI, 0, 0));
point = vector_minus(point, data->cylinder->start_xyz[i]);
point = vec_rot_zyx(point, vectornew(0, -data->cylinder->rot[i].y, 0));
	
//uv.u *= 240;
//uv.v *= 90;
	uv.u = (atan2(point.x, point.z)) / (2.0 * M_PI) + 0.5;
	uv.v = point.y - floor(point.y);
	uv.u *= 12;
	return (uv);
}

static t_vec2 planar_map(t_data *data, t_vector point)
{

	double scale;

	scale = data->hit.texture.size;
		t_vec2	uv;
	t_vector	p;
	t_vector	n;
	t_vector	u;
	double	temp[3];

	point = vector_copy(data->hit.point);
	n = data->hit.normal;
	
	u = normalized_vector(vectornew(n.y, -n.x, 0));
	p = vector_minus(point, data->plane->xyz[data->hit.obj_idx]);
	if (n.x == 0 && n.y == 0)
		u = normalized_vector(vectornew(n.y, -n.x, n.z));
	uv.u = vectordot(u, p);
	uv.v = vectordot(cross_vector(n, u), p);

if (data->hit.texture.txt_pattern != TRUE)
{
	uv.u = uv.u / (data->hit.texture.res.x / 6) / scale;
	uv.v = uv.v / (data->hit.texture.res.y / 6) / scale;
}
else 
{
	uv.u = uv.u / 9 / scale;
	uv.v = uv.v / 6 / scale;
}
	temp[0] = data->plane->rot[data->hit.obj_idx].y * M_PI / 180;
	temp[1] = uv.u * cos(temp[0]) - uv.v * sin(temp[0]);
	temp[2] = uv.v * cos(temp[0]) + uv.u * sin(temp[0]);
	uv.u = temp[1] - floor(temp[1]);
	uv.v = temp[2] - floor(temp[2]);
		
	return (uv);

}

static t_vec2 spherical_map(t_data *data, t_vector p)
{
	t_vec2 uv;
	double theta;
	double phi;
	t_vector rot;
	int i;
i = data->hit.obj_idx;
	p = normalized_vector(p);
	rot.x = data->sphere->rot_x[i];
	rot.y = data->sphere->rot_y[i];
	rot.z = data->sphere->rot_z[i];
	rot.x = -rot.x;
	rot.y = -rot.y;


	p = vec_rot_x(p, rot.x);
	p = vec_rot_y(p, rot.y);
	p = vec_rot_z(p, rot.z);

	theta = atan2(p.x, p.z) / (2.0 * M_PI) + 0.5;

	phi = 0.5 - asin(p.y) / M_PI;

	uv.u = theta;
	uv.v = phi;
	//data->sphere->uv[i].u = uv.u;
	//data->sphere->uv[i].v = uv.v;
	if (data->hit.texture.txt_pattern == TRUE)
{
	
//data->sphere->uv[i].u = uv.u * 9;
	//data->sphere->uv[i].v = uv.v * 6;
	//ft_putendl("moii");
	uv.u *= 9;
	uv.v *= 6;
}
	//else (data->hit.texture.type == 5)
	//{
//data->sphere->uv[i].u = uv.u / 180;
	//data->sphere->uv[i].v = uv.v / 180;
	//uv.u /= 180;
	//uv.v /= 180;
	//}
	

	//printf("\nUV.U: %f\n", data->sphere->uv[i].u);
	
	return (uv);

}

t_vec2 texture_mapping(t_data *data, t_vector n, char *obj_name)
{
	int i;
	 i = data->hit.obj_idx;

		 if (ft_strcmp(obj_name, "sphere") == 0)
 return(spherical_map(data, n));
if (ft_strcmp(obj_name, "plane") == 0)
 return(planar_map(data, n));
 
else
	return(cylindrical_map(data, n));
	 
}

t_rgb2 add_texture(t_vec2 uv, t_rgb2 color, t_hit hit)
{
	char *name;
	
	name = hit.obj_name;
	

	if ((ft_strcmp(name, "cone") == 0) || (ft_strcmp(name, "triangle") == 0) ||  (ft_strcmp(name, "cone") == 0))
		return (color);
	else
	{
		if ((ft_strcmp(hit.texture.name, "checker") == 0))
		return (checker_pattern(uv, color, hit.texture.color, pat_size(hit.texture.size, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "vstripe") == 0))
		return (vstripe_pattern(uv, color, hit.texture.color, pat_size(hit.texture.size, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "hstripe") == 0))
		return (hstripe_pattern(uv, color, hit.texture.color, pat_size(hit.texture.size, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "gradient") == 0))
		return (gradient_pattern(uv, color, pat_size(hit.texture.size, name, hit.radius)));
		else
		return (color);
	}
	
}