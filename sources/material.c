#include "rtv1.h"
#include "stdio.h"
#include "math.h"

t_material glass_effect(t_data *data, int i)
{
    
    t_material material;


	material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);

    return (material);
}

t_material mirror_effect(t_data *data, int i)
{
    t_material material;

//Peilin heijastus:
    if (data->iter != data->org_iter && data->hit.mater == 4)
    {
        data->iter += 1;
        	material.diffuse_red = 0;
		material.diffuse_green = 0;
		material.diffuse_blue = 0;
    }
//


if (data->iter != data->org_iter && data->hit.preobj_mater == 4)
			{
	material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);
			}
			
else if (data->iter == data->org_iter && data->hit.mater == 4)
			{
				material.diffuse_red = 0;
		material.diffuse_green = 0;
		material.diffuse_blue = 0;
			}
 else 
{
	material.diffuse_red = ((double)data->spot->power[i] / 200);
	material.diffuse_green = ((double)data->spot->power[i] / 200);
	material.diffuse_blue = ((double)data->spot->power[i] / 200);
}
            return (material);
}