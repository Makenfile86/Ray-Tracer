#include "rtv1.h"
#include "stdio.h"

void copy_ppm(t_data *data, char *obj_name, int obj_idx, int type)
{
    
    if ((ft_strcmp(obj_name, "sphere") == 0))
    {
        if (type == 2)
        {
            if (data->texture->wood_ppm)
             data->sphere->texture[obj_idx].txt_ppm = data->texture->wood_ppm;
            else
            {
            parse_ppm(data, type);
            data->sphere->texture[obj_idx].txt_ppm = data->texture->wood_ppm;
            }
        }
        else if (type == 4)
        {
           
        
            //if (!(data->texture->moon_ppm))
               parse_ppm(data, type);
             data->sphere->texture[obj_idx].txt_ppm = data->texture->moon_ppm;
    
        }
        else if (type == 3)
        {
        //ft_putendl("moon");
        //ft_putnbr(data->texture->moon_ppm[0]);
            if (!(data->texture->earth_ppm))
            parse_ppm(data, type);
             
                 data->sphere->texture[obj_idx].txt_ppm = data->texture->earth_ppm;
         
            }
            else if (type == 5)
        {
        //ft_putendl("moon");
        //ft_putnbr(data->texture->moon_ppm[0]);
           // if (!(data->texture->black_marble_ppm))
            parse_ppm(data, type);
             
                 data->sphere->texture[obj_idx].txt_ppm = data->texture->black_marble_ppm;
         
            }
    
    }
    else if ((ft_strcmp(obj_name, "plane")) == 0)
    {
        if (type == 2)
        {
            if (data->texture->wood_ppm)
            data->plane->texture[obj_idx].txt_ppm = data->texture->wood_ppm;
            else
            {
            parse_ppm(data, type);
            data->plane->texture[obj_idx].txt_ppm = data->texture->wood_ppm;
            }
        }
        else if (type == 5)
        {
    
        //ft_putnbr(data->texture->moon_ppm[0]);
          //  if (!(data->texture->black_marble_ppm))
            parse_ppm(data, type);
             
                 data->plane->texture[obj_idx].txt_ppm = data->texture->black_marble_ppm;
         
            }
    }
    else if ((ft_strcmp(obj_name, "cylinder")) == 0)
    {
        if (type == 2)
        {
            if (data->texture->wood_ppm)
            data->cylinder->texture[obj_idx].txt_ppm = data->texture->wood_ppm;
            else
            {
            parse_ppm(data, type);
            data->cylinder->texture[obj_idx].txt_ppm = data->texture->wood_ppm;
            }
        }
        else if (type == 5)
        {

            parse_ppm(data, type);
             
                 data->cylinder->texture[obj_idx].txt_ppm = data->texture->black_marble_ppm;
         
            }
    }
    
}

void    parse_ppm(t_data *data, int type)
{
    int     fd;
    int     check;
   char     text_data[1];
    int     i;
//char    *data;
 char    *filename;
int 	x;
    int     width;
    int     height;



    width = WIDTH;
    height = HEIGHT;
x = 0;
i = 0;

if (type == 2)
{
    filename = "./textures/ballroom4.ppm";
    fd = open(filename, O_RDONLY);

if (!(data->texture->wood_ppm = (unsigned char*)malloc(sizeof(unsigned char) * 4000 * 4000 * 4)))
	ft_putendl("lisa mallo error");
}
else if (type == 3)
{
    filename = "./textures/earth.ppm";
 fd = open(filename, O_RDONLY);

if (!(data->texture->earth_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	ft_putendl("./textures/lisa mallo error");
}
else if (type == 4)
{
    filename = "./textures/moon.ppm";
 fd = open(filename, O_RDONLY);

if (!(data->texture->moon_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	ft_putendl("lisa mallo error");
}
else if (type == 5)
{
    filename = "./textures/black_marble.ppm";
 fd = open(filename, O_RDONLY);

if (!(data->texture->black_marble_ppm = (unsigned char*)malloc(sizeof(unsigned char) * 4016 * 4016 * 4)))
	ft_putendl("lisa mallo error");
}
else if (type == 9)
{
    filename = "./textures/lib.ppm";
 fd = open(filename, O_RDONLY);

 if (!(data->texture->background_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	ft_putendl("lisa mallo error");
}



	
	i = 0;
	while (i < width * height)
	{
        if (type == 2)
        {
       data->texture->wood_ppm[i * 4 + 0] = 1;
		data->texture->wood_ppm[i * 4 + 1] = 1;
	data->texture->wood_ppm[i * 4 + 2] = 1;
		data->texture->wood_ppm[i * 4 + 3] = 1;
        }
      else if (type == 3)
      {
          data->texture->earth_ppm[i * 4 + 0] = 1;
		data->texture->earth_ppm[i * 4 + 1] = 1;
	data->texture->earth_ppm[i * 4 + 2] = 1;
		data->texture->earth_ppm[i * 4 + 3] = 1;
      }
      else if (type == 4)
      {
       
          data->texture->moon_ppm[i * 4 + 0] = 1;
		data->texture->moon_ppm[i * 4 + 1] = 1;
	data->texture->moon_ppm[i * 4 + 2] = 1;
		data->texture->moon_ppm[i * 4 + 3] = 1;
      }
      else if (type == 5)
      {
       
          data->texture->black_marble_ppm[i * 4 + 0] = 1;
		data->texture->black_marble_ppm[i * 4 + 1] = 1;
	data->texture->black_marble_ppm[i * 4 + 2] = 1;
		data->texture->black_marble_ppm[i * 4 + 3] = 1;
      }
      else if (type == 9)
      {
       
          data->texture->background_ppm[i * 4 + 0] = 1;
		data->texture->background_ppm[i * 4 + 1] = 1;
	data->texture->background_ppm[i * 4 + 2] = 1;
		data->texture->background_ppm[i * 4 + 3] = 1;
      }
		i++;
        }
i = 0;
while ((check = read(fd, text_data, 1)) > 0 && i < 4000 * 4000 * 4)
{
	if (x % 3 == 0)
	i++;
	x++;
    if (type == 2)
   data->texture->wood_ppm[i] = text_data[0];
   else if (type == 3)
   data->texture->earth_ppm[i] = text_data[0];
   else if (type == 4)
   data->texture->moon_ppm[i] = text_data[0];
   else if (type == 5)
   data->texture->black_marble_ppm[i] = text_data[0];
   else if (type == 9)
   data->texture->background_ppm[i] = text_data[0];
 
    i++;
}

close (fd);

}