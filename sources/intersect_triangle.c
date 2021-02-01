#include "rt.h"
#include <unistd.h>
#include <stdio.h>

t_vector				new_start_dir_triangle(t_data *data, t_ray *ray)
{
	
t_vector n;
	//t_vector scaled;


	t_vector temp;

	temp = vectorscale(0.00001, data->hit.normal);
	ray->newstart = vectoradd(data->hit.point, temp);
	//ray.start = 
	
	//ft_add_vec3(hit->point, ft_mul_vec3(hit->normal,
		//EPSILON));
if (vectordot(ray->target, data->hit.normal) < 0)
		n = data->hit.normal;
	
	else
		n = vectorscale(-1, data->hit.normal);

	//scaled = vectorscale(data->hit.t, ray->target);
	//ray->newstart = vectoradd(ray->start, scaled);
	//ray->newstart = vector_copy(data->hit.point);
	//if (vectordot(ray->target, data->hit.normal) < 0)
	//	n = data->hit.normal;
		//else
		//n = vectorscale(-1, data->hit.normal);
	//data->hit.point = vector_copy(ray->newstart);
//	n = data->hit.normal;
return (n);
	/*
	{
			s_ray.origin = ft_add_vec3(hit.point, ft_mul_vec3(hit.normal, EPSILON));
	s_ray.direction = ft_sub_vec3(light.position, hit.point);
	s_ray.source_shape = hit.shape;
	new_hit.light_dist = ft_len_vec3(s_ray.direction);
	new_hit.shape = NULL;
	s_ray.direction = ft_normalize_vec3(s_ray.direction);
		}
	*/	
/*
	t_vector		n;
	t_vector		tmp[3];
	int i;
	int h;
	double u;
	double v;
	double m;
	//double temp[3];


	h = data->hit.tri_idx;
i = data->hit.obj_idx;
     ray->newstart = data->hit.point;
	 tmp[0] = vector_minus(data->hit.point, data->obj[i].polygonals[h].ve[0]);
	 tmp[1] = vector_minus(data->obj[i].polygonals[h].ve[2], data->obj[i].polygonals[h].ve[0]);
	 tmp[2] = cross_vector(tmp[0], tmp[1]);
	u = vector_length(tmp[2]) * 0.5;
	tmp[0] = vector_minus(data->hit.point, data->obj[i].polygonals[h].ve[1]);
 tmp[1] = vector_minus(data->obj[i].polygonals[h].ve[2], data->obj[i].polygonals[h].ve[1]);
tmp[2] = cross_vector(tmp[0], tmp[1]);
v = vector_length(tmp[2]) * 0.5;
m = 1 - u - v;
tmp[0] = vectorscale(u, data->obj[i].polygonals[h].no[0]);
tmp[1] = vectorscale(v, data->obj[i].polygonals[h].no[1]);
tmp[2] = vectorscale(m, data->obj[i].polygonals[h].no[2]);
n = vector_div(vectoradd(tmp[0], vectoradd(tmp[1], tmp[2])), 3);
return (normalized_vector(n));
*/

}


static t_ray		update_ray(t_data *data, t_ray ray)
{
	data->hit.t = 1000 ;
	t_vector temp;

	temp = vectorscale(0.00001, data->hit.normal);
	ray.start = vectoradd(data->hit.point, temp);
	//ray.start = 
	
	//ft_add_vec3(hit->point, ft_mul_vec3(hit->normal,
		//EPSILON));
	ray.target = vector_minus(ray.target, ray.start);
	ray.target = normalized_vector(ray.target);
	return (ray);
}

int		intersecttriangle(t_ray ray, t_data *data, int y, int h)
{
	//intersects_triangle(t_ray *ray, t_data *triface, int h)
 
    double t;
    t_vector point;
    t_vector abc[3];
    //t_vec3	p[3];
	double	discr;

    if (data->hit.find_shadow == 1)
		ray = update_ray(data, ray);
		//if (data->hit.poly == y && data->iter != data->org_iter)
		//return (0);
//ft_putnbr(data->obj[y].polygonals[h].normal.y);
discr = vectordot(data->obj[y].polygonals[h].normal, ray.target);
//printf("%f x\n", data->obj[y].polygonals[h].normal.x);

		//printf("%f y\n", data->obj[y].polygonals[h].normal.y);

		//printf("%f z\n", data->obj[y].polygonals[h].normal.z);
	//d = ft_dot_vec3(triface->normal, ray.direction);
if (fabs(discr) < 0.00001)
return (0);
	t = vectordot(vectorsub(data->obj[y].polygonals[h].ve[0], ray.start),
    data->obj[y].polygonals[h].normal) / discr;
	if (t < 0.00001 || t > 1000)
	return (0);
   //ft_putendl("kaytko taalla");
   // hit->t = ft_dot_vec3(ft_sub_vec3(triface->v[0], ray.origin),
	//	triface->normal) / d;
	//if (hit->t < MIN_CLIP || hit->t > MAX_CLIP)
		//return (FALSE);
       // ft_putendl("normals");
       // ft_putnbr(data->obj[y].normals[h].x);
       // ft_putchar('\n');
        point = vectoradd(ray.start, vectorscale(t, ray.target));
        abc[0] = vectorsub(point, data->obj[y].polygonals[h].ve[0]);
        abc[1] = vectorsub(point, data->obj[y].polygonals[h].ve[1]);
        abc[2] = vectorsub(point, data->obj[y].polygonals[h].ve[2]);
        //data->hit.point = vector_copy(point);
        	//hit->point = ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, hit->t));
	//p[0] = ft_sub_vec3(hit->point, triface->v[0]);
	//p[1] = ft_sub_vec3(hit->point, triface->v[1]);
	//p[2] = ft_sub_vec3(hit->point, triface->v[2]);
    if (vectordot(data->obj[y].polygonals[h].normal, cross_vector(data->obj[y].polygonals[h].te[0], abc[0])) >= 0 &&
    vectordot(data->obj[y].polygonals[h].normal, cross_vector(data->obj[y].polygonals[h].te[1], abc[1])) >= 0 &&
    vectordot(data->obj[y].polygonals[h].normal, cross_vector(data->obj[y].polygonals[h].te[2], abc[2])) >= 0)
   {
       
       //t[0] = distance;
       if (t < data->hit.t)
       {
       data->hit.t = t;
       data->hit.normal = data->obj[y].polygonals[h].normal;
	   if (data->hit.find_shadow != 1)
	   data->hit.point = vector_copy(point);
      // data->hit.poly_idx = h;
	  // if (data->iter != data->org_iter && data->hit.poly == -1)
	  // data->hit.poly = y;
       //ft_putendl("hoi");
       return (1);
       }
   }
   return (0);
}

	//if (ft_dot_vec3(triface->normal, ft_cross_vec3(triface->e[0], p[0])) >= 0 &&
		//ft_dot_vec3(triface->normal, ft_cross_vec3(triface->e[1], p[1])) >= 0 &&
		//ft_dot_vec3(triface->normal, ft_cross_vec3(triface->e[2], p[2])) >= 0)
	//{
		//hit->distance = hit->t;
		//hit->normal = triface->normal;
		//hit->triface = triface;
		//return (TRUE);
	//}
	//return (FALSE);
