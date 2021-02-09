#include "rt.h"
#include "stdio.h"
#include "math.h"

static t_vec2 scale_planar_uv(t_vec2 uv, t_hit hit, double scale)
{
	if (hit.texture.txt_pattern != TRUE)
{
	uv.u = uv.u / (double)((hit.texture.res.x / 9) / (scale * 0.10));
	uv.v = uv.v / (double)((hit.texture.res.y / 9) / (scale * 0.10));
}
else 
{
	uv.u = uv.u / 9 / scale;
	uv.v = uv.v / 6 / scale;
}
return (uv);
}

static t_vec2 cylindrical_map(t_vector point, t_vector pos, t_vector axis, t_vector rot)
{
	t_vec2 uv;
	//t_vector up;
	//t_vector temp;
	//double angle;
	double theta;
double raw_u;



rot = vectornew(0, 0, 0);
axis = vectornew(0, 0, 0);
pos = vectornew(0, 0, 0);
//point.x = 0.70711;
//point.y = 0.5;
//point.z = 0.70711;
//0, -0.25, 1
//0.70711, 0.5, -0.70711
//-0.70711, 0.5, -0.70711)
//-1, 1.25, 0
//up = vectornew(0, 1, 0);
//angle = atan(axis.x / vectordot(up, axis));
//temp = vec_rot_zyx(axis, vectornew(0, 0, angle * 180 / M_PI));
//point = vec_rot_zyx(point, vectornew(0, 0, angle * 180 / M_PI));
//angle = atan(temp.z / vectordot(up, temp));
//point = vec_rot_zyx(point, vectornew(angle * 180 / M_PI, 0, 0));
//point = vector_minus(point, pos);
//point = vec_rot_zyx(point, vectornew(0, -rot.y, 0));
	
	theta = atan2(point.x, point.z);
raw_u = theta / (2 * M_PI);
uv.u = 1 - (raw_u + 0.5);
	
	//uv.u = 1 - (atan2(point.x, point.z)) / (2.0 * M_PI) + 0.5;
	//uv.v = point.y - floor(point.y);
	uv.v = point.y - floor(point.y);
	uv.u *= 6;
	//uv.u *= 6;
	//uv.v = fmod(point.y, 10);
  //uv.v /= 4;
  //uv.u /= 10;
  //uv.v /= (10 / 10);
  //let theta ← arctan2(p.x, p.z)
  //let raw_u ← theta / (2 * π)
  //let u ← 1 - (raw_u + 0.5)
//uv.u *= 12;
//if (uv.u > 1)
//printf("U: %f\n", uv.u);
//if (uv.v > 1)
//printf("V: %f\n", uv.v);
	return (uv);
}

static t_vec2 planar_map(t_hit hit, t_vector point, t_vector pos, t_vector rot)
{
    t_vec2	uv;
	t_vector	p;
	t_vector	n;
	t_vector	u;
	double	temp[3];

	n = hit.normal;
	u = normalized_vector(vectornew(n.y, -n.x, 0));
	p = vector_minus(point, pos);
	if (n.x == 0 && n.y == 0)
	u = normalized_vector(vectornew(n.y, -n.x, n.z));
	uv.u = vectordot(u, p);
	uv.v = vectordot(cross_vector(n, u), p);
	uv = scale_planar_uv(uv, hit, hit.texture.scale);
	temp[0] = rot.y * M_PI / 180;
	temp[1] = uv.u * cos(temp[0]) - uv.v * sin(temp[0]);
	temp[2] = uv.v * cos(temp[0]) + uv.u * sin(temp[0]);
	uv.u = temp[1] - floor(temp[1]);
	uv.v = temp[2] - floor(temp[2]);
	return (uv);
}

static t_vec2 spherical_map(t_hit hit, t_vector point, t_vector rot)
{
	t_vec2 uv;
	double theta;
	double phi;
	
	rot.x = -rot.x;
	rot.y = -rot.y;
	point = vec_rot_x(point, rot.x);
	point = vec_rot_y(point, rot.y);
	point = vec_rot_z(point, rot.z);

	theta = atan2(point.x, point.z) / (2.0 * M_PI) + 0.5;

	phi = 0.5 - asin(point.y) / M_PI;

	uv.u = theta;
	uv.v = phi;
	
	if (hit.texture.txt_pattern == TRUE)
{
	uv.u *= 9;
	uv.v *= 6;
}
return (uv);
}

t_vec2 texture_mapping(t_hit hit, char *obj_name)
{


		 if (ft_strcmp(obj_name, "sphere") == 0)
 return(spherical_map(hit, normalized_vector(hit.point), hit.rot));
if (ft_strcmp(obj_name, "plane") == 0)
 return(planar_map(hit, hit.point, hit.pos, hit.rot));
 
else
	return(cylindrical_map(hit.normal, hit.pos, 
	hit.axis, hit.rot));
	 
}

t_rgb2 add_texture(t_vec2 uv, t_rgb2 color, t_hit hit)
{
	char *name;
	
	name = hit.obj_name;
	

	if ((ft_strcmp(name, "cone") == 0) || (ft_strcmp(name, "triangle") == 0))
		return (color);
	else
	{
		if ((ft_strcmp(hit.texture.name, "checker") == 0))
		return (checker_pattern(uv, color, hit.texture.color, pat_size(hit.texture.scale, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "vstripe") == 0))
		return (vstripe_pattern(uv, color, hit.texture.color, pat_size(hit.texture.scale, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "hstripe") == 0))
		return (hstripe_pattern(uv, color, hit.texture.color, pat_size(hit.texture.scale, name, hit.radius)));
		else if ((ft_strcmp(hit.texture.name, "gradient") == 0))
		return (gradient_pattern(uv, color, pat_size(hit.texture.scale, name, hit.radius)));
		if ((ft_strcmp(hit.texture.name, "split") == 0))
		return (split_pattern(uv, color, hit.texture.color, pat_size(hit.texture.scale, name, hit.radius)));
		else
		return (color);
	}
	
}