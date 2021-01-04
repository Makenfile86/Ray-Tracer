#include "rtv1.h"
#include "../libft/libft.h"

char *parse_data_line(char *str, char *line, int *i, int y)
{
    int x;

    x = *i;

   
		while (ft_isdigit(line[x]) == 0 && line[x] != '\0' && line[x] != '-')
			x++;
		str = if_negative(line, str, &x, &y);
		while (ft_isdigit(line[x]) == 1 && line[x] != '\0' && line[x] != '-'
				&& y < 6)
			str[y++] = line[x++];
            *i = x;
        return (str);
}

char		*parse_name(char *line, char *name)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	if (line[i++] == 32 || line[i++] == 9)
	{
		while (ft_isalpha(line[i]) == 1 && y < 8)
			name[y++] = line[i++];
	}
	name[y] = '\0';
	free(line);
	return (name);
}


void			parse_obj(char *line, t_data *data, int *obj_idx, char *type)
{
	int		i;
	int		y;
	char	*str;
	int		x;
	int e;
	if ((ft_strcmp(type, "scene") == 0) ||  (ft_strcmp(type, "camera") == 0))
	e = 0;
	else 
	e = *obj_idx;
	x = 0;
	i = 0;
	
	if (!(str = (char *)malloc(sizeof(char) * 6 + 1)))
		memory_allocation_fail();
	while (line[i] != '\0')
	{
		y = 0;
		copy_data(data, parse_data_line(str, line, &i, y), &x, e);
		ft_memset(str, 0, ft_strlen(str));
	}
	init_parsed_data(data, type, e);
	free(str);
}