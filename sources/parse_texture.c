#include "rt.h"
#include "stdio.h"

int validate_file(char *txt_name, char **path)
{
int fd;
char *tmp_path1;
char *tmp_path2;
char *tmp_path3;
char *filename;

tmp_path1 = ft_strdup("./textures/");
tmp_path2 = ft_strdup(".ppm");
tmp_path3 = ft_strjoin(tmp_path1, txt_name);
filename = ft_strjoin(tmp_path3, tmp_path2);

free(tmp_path1);
free(tmp_path2);
free(tmp_path3);

if ((fd = open(filename, O_RDONLY)) < 0)
{
    close(fd);
    free(filename);
    return (0);
}
*path = ft_strdup(filename);

ft_putendl(*path);
close(fd);
free(filename);
//close (fd);

return (1);

}

    
        
   
    
  
    


static unsigned char *fourth_channel_padding(unsigned char *texture, int width, int height)
{   
    int i;

    i = 0;
    ft_putendl("fouurth");
    ft_putendl("mooor");
	while (i < width * height)
	{
       texture[i * 4 + 0] = 1;
		texture[i * 4 + 1] = 1;
	texture[i * 4 + 2] = 1;
		texture[i * 4 + 3] = 1;
        i++;
        }
        return (texture);
}

static unsigned char *init_texture(unsigned char *texture, char *path, t_res *res)
{


int fd;
char *resolution;
char *line;
int i;
int x;
int y;

i = 0;
x = 0;
y = 0;

if ((fd = open(path, O_RDONLY)) < 0)
return (NULL);

while (((get_next_line(fd, &line)) == 1) && x < 2)
{

   if (x == 0)
    {
    if (line[0] == 'P' && line[1] == '6')
        ft_putendl("Loading new texture");
        else
       {
           ft_putendl("Wrong texture format, not loaded");
           return (NULL);
       }
    }

    if (x == 1)
    {
            resolution = (char *)malloc(sizeof(char) * ft_strlen(line));
            while ((ft_isdigit(line[i]) == 1) && line[i] != '\0')
            {
                resolution[i] = line[i];
                i++;
            }
                resolution[i] = '\0';
            res->x = ft_atoi(resolution);
            i++;
            while (ft_isdigit(line[i] == 1))
            resolution[y++] = line[i++];
            resolution[i] = '\0';
            res->y = ft_atoi(resolution);
    }
    x++;
    free(line);
}
free(line);
close (fd);
free(resolution);
         if (!(texture = (unsigned char*)malloc(sizeof(unsigned char) * res->x * res->y * 4)))
    memory_allocation_fail();
    texture = fourth_channel_padding(texture, res->x, res->y);
    return (texture);       

}
    







//else
//{
//if (!(data->texture->background_ppm = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
	//memory_allocation_fail();
    //fourth_channel_padding(data->texture->background_ppm, width, height);
           //data->texture->background_loaded = 1;
    //return ("./textures/background.ppm");
//}




unsigned char    *parse_ppm(unsigned char *texture, char *path, t_res *res)
{
    int     fd;
   char     text_data[1];
    int     i;
 int ret;
int 	x;
    



   
x = 0;
i = 0;

ft_putendl("PATH");
ft_putendl(path);

texture = init_texture(texture, path, res);
if (res->x == 0 && res->y == 0)
return (NULL);
	if (texture != NULL)
   {
if ((fd = open(path, O_RDONLY)) > 0)
{


while ((ret = read(fd, text_data, 1)) > 0 && i < res->x * res->y * 4)
{
	if (x % 3 == 0)
	i++;
	x++;
    //if (i > 18)
   texture[i] = text_data[0];

    i++;
}   
}
    close (fd);
}
return (texture);

}