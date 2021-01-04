#include "rtv1.h"
#include "../libft/libft.h"

void			parse_texture(char *line, t_data *data)
{
    data->texture->name = "cat";
    ft_putendl(line);
ft_putendl("We have a texture!");
ft_putendl(data->texture->name);
}