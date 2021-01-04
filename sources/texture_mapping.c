#include "rtv1.h"
#include "stdio.h"
#include "math.h"

static void cylindrical_map(t_data *data, t_vector point)
{
	//double theta;
	//double raw_u;
	t_vec2 uv;
	//t_vector target;
	t_vector up;
	t_vector temp;
	t_vector axis;
	double angle;
//p = ft_add_vec3(r->origin, ft_mul_vec3(r->direction, t));
	int i;
	i = data->hit.obj_idx;
	//target = vector_copy(data->cylinder->axis[i]);

point = vector_copy(data->hit.normal);
//if (point.y == 0)
axis = data->cylinder->axis[i];
//point.y = 0.1;
//printf("\npoint: %f\n", point.z);
//point = normalized_vector(point);ß
//point = normalized_vector(point);
//spoint = normalized_vector(point);
//printf("\npoint normalized: %f\n", point.z);
//point.x = fabs(point.x);
//point.y = fabs(point.y);
//point.z = fabs(point.z);
//printf("%f\n", point.z);
//point = vectornew(0.70711, 0.5, -0.70711);


up = vectornew(0, 1, 0);
angle = atan(axis.x / vectordot(up, axis));
temp = vec_rot_zyx(axis, vectornew(0, 0, angle * 180 / M_PI));
point = vec_rot_zyx(point, vectornew(0, 0, angle * 180 / M_PI));
angle = atan(temp.z / vectordot(up, temp));
point = vec_rot_zyx(point, vectornew(angle * 180 / M_PI, 0, 0));
point = vector_minus(point, data->cylinder->start_xyz[i]);
point = vec_rot_zyx(point, vectornew(0, -data->cylinder->rot[i].y, 0));
	
	//point = normalized_vector(point);
	
	/*
	up = ft_make_vec3(0, 1, 0);
	angle = atan(cylinder->target.x / ft_dot_vec3(up, cylinder->target));
	temp = ft_rotate_vec3(cylinder->target,
		ft_make_vec3(0, 0, angle * 180 / M_PI));
	p = hit->point;
	p = ft_rotate_vec3(p, ft_make_vec3(0, 0, angle * 180 / M_PI));
	angle = atan(temp.z / ft_dot_vec3(up, temp));
	p = ft_rotate_vec3(p, ft_make_vec3(angle * 180 / M_PI, 0, 0));
	p = ft_sub_vec3(p, cylinder->position);
	p = ft_rotate_vec3(p, ft_make_vec3(0, -cylinder->rotation.y, 0));
*/
//uv.u = (atan2(point.x, point.z)) / (2.0 * M_PI) + 0.5;
	//uv.v = point.y - floor(point.y);
	//uv.u *= 6;
	//uv.v *= 6;
	//uv.u *= 6.0;
	//theta = atan2(point.x, point.z);
	//raw_u = theta / (2 * M_PI);

double scale;

	scale = data->hit.texture.size;
	//uv.u = (1 - (raw_u + 0.5));
	//uv.v = fmod(point.y, 1);
	uv.u = (atan2(point.x, point.z)) / (2.0 * M_PI) + 0.5;
	uv.v = point.y - floor(point.y);
		//uv.v = point.y - floor(point.y);
		//uv.v = point.y;
		//uv.u *= 6;
data->cylinder->uv[data->hit.obj_idx].u = uv.u * 12;

  data->cylinder->uv[data->hit.obj_idx].v = uv.v;
  //printf("%f\n", data->cylinder->uv[data->hit.obj_idx].v);
/*
	function cylindrical_map(p)
  # compute the azimuthal angle, same as with spherical_map()
  let theta ← arctan2(p.x, p.z)
  let raw_u ← theta / (2 * π)
  let u ← 1 - (raw_u + 0.5)

  # let v go from 0 to 1 between whole units of y
  let v ← p.y mod 1

  return (u, v)
end function
*/
}

static void planar_map(t_data *data, t_vector point)
{
	//p = normalized_vector(p);
	//printf("%f\n", p.x)2
	double scale;

	scale = data->hit.texture.size;
		t_vec2	uv;
	t_vector	p;
	t_vector	n;
	t_vector	u;
	double	temp[3];
//point.x = data->tmp_x;
//	point.y = data->tmp_y;
//	point.z = data->tmp_z;
	point = vector_copy(data->plane->tmp_xyz);
	n = data->hit.normal;
	
	//printf("%f\n", data->hit.normal.z);
	u = normalized_vector(vectornew(n.y, -n.x, 0));
	p = vector_minus(point, data->plane->xyz[data->hit.obj_idx]);
	if (n.x == 0 && n.y == 0)
		u = normalized_vector(vectornew(n.y, -n.x, n.z));
	uv.u = vectordot(u, p);
	uv.v = vectordot(cross_vector(n, u), p);
	//uv.u /= plane->material->u_scale;
	//uv.v /= plane->material->v_scale;
//	temp[0] = ft_deg_to_rad(plane->rotation.y);z
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
//printf("%f\n", uv.u);
	/*
	//p = vectornew(data->tmp_x, data->tmp_y, data->tmp_z);
	p.x = data->tmp_x;
	p.y = data->tmp_y;
	p.z = data->tmp_z;
	p = normalized_vector(p);
	//printf("%f\n", p.x);
	p.x = fabs(p.x);
	p.y = fabs(p.y);
	p.z = fabs(p.z);
  data->plane->uv[data->hit.obj_idx].u = p.x * 9;

  data->plane->uv[data->hit.obj_idx].v = p.z * 6;
 // printf("%f\n", data->plane->uv[data->hit.obj_idx].u);
*/
}

static void spherical_map(t_data *data, t_vector p)
{
	t_vec2 uv;
	double theta;
	//t_checkers size;
	//t_vector from_origin;
	double phi;
	t_vector rot;
	int i;
i = data->hit.obj_idx;
	//double raw_u;
	//double radius;
	//p.x = data->tmp_x;
	p = normalized_vector(p);
	//p.y = data->tmp_y;
	rot.x = data->sphere->rot_x[i];
	rot.y = data->sphere->rot_y[i];
	rot.z = data->sphere->rot_z[i];
	rot.x = -rot.x;
	rot.y = -rot.y;


	p = vec_rot_x(p, rot.x);
	p = vec_rot_y(p, rot.y);
	p = vec_rot_z(p, rot.z);
	//p.z = data->tmp_z;n = ft_rotate_vec3(hit->normal, ft_invert_vec3(sphere->rotation));
//ft_putendl("moikka2");
	theta = atan2(p.x, p.z) / (2.0 * M_PI) + 0.5;
	//from_origin = vectornew(p.x, p.y, p.z);
	//radius = sqrt((f.rom_originx + from_origin.y + from_origin.z));
	//printf("%f\n", radius);
	phi = 0.5 - asin(p.y) / M_PI;
	//raw_u = theta / (2.0 * M_PI);
	//uv.u = 1 - (raw_u + 0.5);
	//uv.v = 1 - phi / M_PI;
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
	//size.width = 9;
	//size.height = 6;

}

void texture_mapping(t_data *data, t_vector n, char *obj_name)
{

	//double u;
	//double v;
   //double temp[3];
    //t_vec2 uv;

	//int u2;
    //int v2;
	

if (ft_strcmp(obj_name, "sphere") == 0)
{
    spherical_map(data, n);
	//n = ft_rotate_vec3(hit->normal, ft_invert_vec3(sphere->rotation));
	//u = atan2(n.x, n.z) / (2.0 * M_PI) + 0.5;
	//v = 0.5 - asin(n.y) / M_PI;
	//u /= data->sphere->radius[data->hit.obj_idx] / 2;
	//v /= data->sphere->radius[data->hit.obj_idx] / 1;

	//data->sphere->uv[data->hit.obj_idx].v = v * 9;
	//data->sphere->uv[data->hit.obj_idx].u = u * 6;
	//printf("\n%f\n", data->sphere->uv[data->hit.obj_idx].u);
	// printf("%f\n", data->sphere->uv[data->hit.obj_idx].v);
}

if (ft_strcmp(obj_name, "plane") == 0)
{
	//n = ft_rotate_vec3(hit->normal, ft_invert_vec3(sphere->rotation));
   planar_map(data, n);
   /*
    uv.u = data->tmp_x;
    uv.v = data->tmp_z;
  
	//u /= data->sphere->radius[data->hit.obj_idx] / 2;
	//v /= data->sphere->radius[data->hit.obj_idx] / 1;
	data->plane->uv[data->hit.obj_idx].v = fabs(uv.v / 6);
	data->plane->uv[data->hit.obj_idx].u = fabs(uv.u / 3);
	*/
		//data->plane->uv[data->hit.obj_idx].v = fabs(uv.v * 6);
	//data->plane->uv[data->hit.obj_idx].u = fabs(uv.u * 18);
	//data->plane->uv[data->hit.obj_idx].v = fabs(fmod(uv.v, 1) * 6);
	//data->plane->uv[data->hit.obj_idx].u = fabs(fmod(uv.u, 1) * 18);
  // printf("%f\n", data->plane->uv[data->hit.obj_idx].v);
	//printf("\n%f\n", uv.v);
}
if (ft_strcmp(obj_name, "cylinder") == 0)
{
	cylindrical_map(data, n);
}
	
}