#include "rtv1.h"
#include "stdio.h"

unsigned char *copy_ppm(t_data *data, int type)
{

 if (type == 2)
        {
            if (data->texture->wood_loaded == 1)
            return (data->texture->wood_ppm);
            return (parse_ppm(data, data->texture->wood_ppm, type));
        }
        else if (type == 4)
        {
           if (data->texture->moon_loaded == 1)
           return (data->texture->moon_ppm);
            return (parse_ppm(data, data->texture->moon_ppm, type));
         }
        else if (type == 3)
        {
            if (data->texture->earth_loaded == 1)
            return (data->texture->earth_ppm);
           return (parse_ppm(data, data->texture->earth_ppm, type));
         }
            else
        {
            if (data->texture->black_marble_loaded == 1)
            return (data->texture->black_marble_ppm);
            return (parse_ppm(data, data->texture->black_marble_ppm, type));
        }
   
    }
  
    


static void fourth_channel_padding(unsigned char *texture, int width, int height)
{   
    int i;

    i = 0;
	while (i < width * height)
	{
       texture[i * 4 + 0] = 1;
		texture[i * 4 + 1] = 1;
	texture[i * 4 + 2] = 1;
		texture[i * 4 + 3] = 1;
        i++;
        }
}

static char *init_texture(t_data *data, int type, int width, int height)
{

if (type == 2)
{
    width = 4000;
    height = 4000;
    if (!(data->texture->wood_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	memory_allocation_fail();
    fourth_channel_padding(data->texture->wood_ppm, width, height);
    data->texture->wood_loaded = 1;
    return ("./textures/ballroom4.ppm");
}
else if (type == 3)
{
if (!(data->texture->earth_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	memory_allocation_fail();
    fourth_channel_padding(data->texture->earth_ppm, width, height);
       data->texture->earth_loaded = 1;
    return ("./textures/earth.ppm");
}
else if (type == 4)
{
  if (!(data->texture->moon_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	memory_allocation_fail();
    fourth_channel_padding(data->texture->moon_ppm, width, height);
       data->texture->moon_loaded = 1;
    return ("./textures/moon.ppm");
}
else if (type == 5)
{
     width = 4016;
    height = 4016;
if (!(data->texture->black_marble_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	memory_allocation_fail();
    fourth_channel_padding(data->texture->black_marble_ppm, width, height);
       data->texture->black_marble_loaded = 1;
    return ("./textures/black_marble.ppm");
}
else
{
if (!(data->texture->background_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	memory_allocation_fail();
    fourth_channel_padding(data->texture->background_ppm, width, height);
           data->texture->background_loaded = 1;
    return ("./textures/background.ppm");
}


}

unsigned char    *parse_ppm(t_data *data, unsigned char *texture, int type)
{
    int     fd;
    int     check;
   char     text_data[1];
    int     i;
 char    *filename;
int 	x;
    int     width;
    int     height;



    width = WIDTH;
    height = HEIGHT;
x = 0;
i = 0;

filename = init_texture(data, type, width, height);
fd = open(filename, O_RDONLY);

	
if (!(texture = (unsigned char*)malloc(sizeof(unsigned char) * 4016 * 4016 * 4)))
	memory_allocation_fail();

while ((check = read(fd, text_data, 1)) > 0 && i < 4016 * 4016 * 4)
{
	if (x % 3 == 0)
	i++;
	x++;
   texture[i] = text_data[0];
    i++;
}
close (fd);
return (texture);



}