#include "rt.h"
#include "math.h"
#include "stdio.h"

static t_material add_material(double value)
{
    t_material material;

    material.diffuse_red = value;
    material.diffuse_green = value;
    material.diffuse_blue = value;

    return (material);
}


t_material get_material(t_data *data, t_hit hit, int light_power)
{
t_material material;

material = add_material((double)light_power / 200);
if ((ft_strcmp(hit.preobj_name, "plane") == 0) && hit.mater == 4)
material = add_material((double)light_power / 1000);
else if (hit.mater == 4)
material = add_material((double)light_power / (1800 / hit.texture.scale));
if (hit.preobj_mater == 3)
material = add_material((double)light_power / 200);
if ((data->iter != data->org_iter) && (ft_strcmp(hit.obj_name, "plane") == 0) && hit.preobj_mater != 4
&& hit.was_refract != 1)
{
    if (ft_strcmp(data->hit.preobj_name, "plane") == 0)
    material = add_material((double)light_power / 1000);
    else
    material = add_material((double)light_power / 500);
}
if ((ft_strcmp(hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter && hit.preobj_mater < 3 && hit.was_refract != 1)
            material = add_material((double)light_power / 1000);
if ((ft_strcmp(hit.preobj_name, "plane") == 0) && (ft_strcmp(hit.obj_name, "plane") == 0) &&
			data->iter != data->org_iter)  
            {
                if (data->hit.preobj_mater == 4)
                material = add_material((double)light_power / 200);  
             else
    material = add_material((double)light_power / 1000); 
            }
    if (hit.mater == 3)
    add_material((double)light_power / 1800);

    return (material);
}

/*
t_material glass_effect(t_data *data, int i)
{
    
    t_material material;


	material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);
    return (material);
}
*/
//t_material mirror_effect(t_data *data, int i)
//{
    //t_material material;

	//material.diffuse_red = ((double)data->spot->power[i] / (1800 / data->hit.texture.scale));
	//material.diffuse_green = ((double)data->spot->power[i] / (1800 / data->hit.texture.scale));
	//material.diffuse_blue = ((double)data->spot->power[i] / (1800 / data->hit.texture.scale));

          //  return (material);
//}
/*
t_material plane_reflection(t_data *data, int i)
{
    t_material material;

        if (ft_strcmp(data->hit.preobj_name, "plane") == 0)
        {
            material.diffuse_red = 0.05;
		material.diffuse_green = 0.05;
		material.diffuse_blue = 0.05;
        }
        else
        {
        
	    material.diffuse_red = ((double)data->spot->power[i] / 500);
		material.diffuse_green = ((double)data->spot->power[i] / 500);
		material.diffuse_blue = ((double)data->spot->power[i] / 500);
        }

        return (material);
}
*/
