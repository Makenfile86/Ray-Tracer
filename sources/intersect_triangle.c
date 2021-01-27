#include "rt.h"
#include <unistd.h>
#include <stdio.h>

int		intersecttriangle(t_ray ray, t_data *data, int h)
{
	//intersects_triangle(t_ray *ray, t_data *triface, int h)
 
    double t;
    t_vector point;
    t_vector abc[3];
    //t_vec3	p[3];
	double	discr;
//ft_putnbr(data->obj->polygonals[h].normal.y);
discr = vectordot(data->obj->polygonals[h].normal, ray.target);
//printf("%f x\n", data->obj->polygonals[h].normal.x);

		//printf("%f y\n", data->obj->polygonals[h].normal.y);

		//printf("%f z\n", data->obj->polygonals[h].normal.z);
	//d = ft_dot_vec3(triface->normal, ray.direction);
if (fabs(discr) < 0.000001)
return (0);
	t = vectordot(vectorsub(data->obj->polygonals[h].ve[0], ray.start),
    data->obj->polygonals[h].normal) / discr;
   //ft_putendl("kaytko taalla");
   // hit->t = ft_dot_vec3(ft_sub_vec3(triface->v[0], ray.origin),
	//	triface->normal) / d;
	//if (hit->t < MIN_CLIP || hit->t > MAX_CLIP)
		//return (FALSE);
       // ft_putendl("normals");
       // ft_putnbr(data->obj->normals[h].x);
       // ft_putchar('\n');
        point = vectoradd(ray.start, vectorscale(t, ray.target));
        abc[0] = vectorsub(point, data->obj->polygonals[h].ve[0]);
        abc[1] = vectorsub(point, data->obj->polygonals[h].ve[1]);
        abc[2] = vectorsub(point, data->obj->polygonals[h].ve[2]);
        data->hit.point = vector_copy(point);
        	//hit->point = ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, hit->t));
	//p[0] = ft_sub_vec3(hit->point, triface->v[0]);
	//p[1] = ft_sub_vec3(hit->point, triface->v[1]);
	//p[2] = ft_sub_vec3(hit->point, triface->v[2]);
    if (vectordot(data->obj->polygonals[h].normal, cross_vector(data->obj->polygonals[h].te[0], abc[0])) >= 0 &&
    vectordot(data->obj->polygonals[h].normal, cross_vector(data->obj->polygonals[h].te[1], abc[1])) >= 0 &&
    vectordot(data->obj->polygonals[h].normal, cross_vector(data->obj->polygonals[h].te[2], abc[2])) >= 0)
   {
       
       //t[0] = distance;
       if (t < data->hit.t)
       {
       data->hit.t = t;
       data->hit.normal = data->obj->polygonals[h].normal;
       
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
