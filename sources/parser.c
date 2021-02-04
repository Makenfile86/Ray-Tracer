#include "rt.h"
#include <stdio.h>

char *parse_data_line(char *str, char *line, int *i, int y)
{
    int x;

    x = *i;

   
		while (ft_isdigit(line[x]) == 0 && (ft_isalpha(line[x]) == 0) && line[x] != '\0' && line[x] != '-')
			x++;
		str = if_negative(line, str, &x, &y);
		while ((ft_isdigit(line[x]) == 1 || (ft_isalpha(line[x]) == 1)) && line[x] != '\0' && line[x] != '-'
				&& y < 20)
			str[y++] = line[x++];
            *i = x;
		str[y] = '\0';
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
	int e;
	char **parts;
	int x;
	int i;
	char *str;
	x = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	if ((ft_strcmp(type, "scene") == 0) ||  (ft_strcmp(type, "camera") == 0))
	e = 0;
	else if (ft_strcmp(type, "model") == 0)
	e = data->modelnbr;
	else 
	e = *obj_idx;
	while (line[x] != '\0')
	{
		while (ft_isdigit(line[x]) != 1 && line[x] != '\0' && line[x] != ' ' && line[x] != '-' && ft_isalpha(line[x]) != 1)
		x++;
		str[i++] = line[x++];
	}
	//while (i < ft_strlen(line))
	//ft_putendl(str);
	parts = ft_strsplit(str, ' ');
	copy_data(data, parts, e);
	init_parsed_data(data, type, e);
}