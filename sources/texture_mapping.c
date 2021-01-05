#include "rtv1.h"
#include "stdio.h"
#include "math.h"

static void cylindrical_map(t_data *data, t_vector point)
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
	

	uv.u = (atan2(point.x, point.z)) / (2.0 * M_PI) + 0.5;
	uv.v = point.y - floor(point.y);
	data->cylinder->uv[data->hit.obj_idx].u = uv.u * 12;
	data->cylinder->uv[data->hit.obj_idx].v = uv.v;
}

static void planar_map(t_data *data, t_vector point)
{

	double scale;

	scale = data->hit.texture.size;
		t_vec2	uv;
	t_vector	p;
	t_vector	n;
	t_vector	u;
	double	temp[3];
	point = vector_copy(data->plane->tmp_xyz);
	n = data->hit.normal;
	
	u = normalized_vector(vectornew(n.y, -n.x, 0));
	p = vector_minus(point, data->plane->xyz[data->hit.obj_idx]);
	if (n.x == 0 && n.y == 0)
		u = normalized_vector(vectornew(n.y, -n.x, n.z));
	uv.u = vectordot(u, p);
	uv.v = vectordot(cross_vector(n, u), p);

if (data->hit.texture.type == 5)
{
	uv.u = uv.u / 240 / scale;
	uv.v = uv.v / 180 / scale;
}
else 
{
	uv.u = uv.u / 9 / scale;
	uv.v = uv.v / 6 / scale;
}
	temp[0] = 0;
	temp[1] = uv.u * cos(temp[0]) - uv.v * sin(temp[0]);
	temp[2] = uv.v * cos(temp[0]) + uv.u * sin(temp[0]);
	uv.u = temp[1] - floor(temp[1]);
	uv.v = temp[2] - floor(temp[2]);
	
	data->plane->uv[data->hit.obj_idx].u = uv.u;

  data->plane->uv[data->hit.obj_idx].v = uv.v;

}

static void spherical_map(t_data *data, t_vector p)
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
	data->sphere->uv[i].u = uv.u;
	data->sphere->uv[i].v = uv.v;
	if (data->hit.texture.type == 1)
	{
data->sphere->uv[i].u = uv.u * 9;
	data->sphere->uv[i].v = uv.v * 6;
	}
	if (data->hit.texture.type == 5)
	{
data->sphere->uv[i].u = uv.u / 180;
	data->sphere->uv[i].v = uv.v / 180;
	}

}

void texture_mapping(t_data *data, t_vector n, char *obj_name)
{
if (ft_strcmp(obj_name, "sphere") == 0)
    spherical_map(data, n);
if (ft_strcmp(obj_name, "plane") == 0)
   planar_map(data, n);
if (ft_strcmp(obj_name, "cylinder") == 0)
	cylindrical_map(data, n);
}