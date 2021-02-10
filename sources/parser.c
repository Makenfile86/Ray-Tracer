/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:09:10 by anikkane          #+#    #+#             */
/*   Updated: 2020/11/18 12:45:35 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			*parse_data_line(char *str, char *line, int *i, int y)
{
	int			x;

	x = *i;
	while (ft_isdigit(line[x]) == 0 && (ft_isalpha(line[x]) == 0)
			&& line[x] != '\0' && line[x] != '-')
		x++;
	str = if_negative(line, str, &x, &y);
	while ((ft_isdigit(line[x]) == 1 || (ft_isalpha(line[x]) == 1)) &&
			line[x] != '\0' && line[x] != '-' && y < 20)
		str[y++] = line[x++];
	*i = x;
	str[y] = '\0';
	return (str);
}

char			*parse_name(char *line, char *name)
{
	int			i;
	int			y;

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

static char		*padding(char *str, int start, int len)
{
	str[start++] = ' ';
	while (start < len)
	{
		if (start % 2 == 0)
			str[start++] = ' ';
		else
			str[start++] = '0';
	}
	str[start] = '\0';
	return (str);
}

static int		get_object_index(char *type, int modelnbr, int *obj_idx)
{
	if ((ft_strcmp(type, "scene") == 0) || (ft_strcmp(type, "camera") == 0))
		return (0);
	else if (ft_strcmp(type, "model") == 0)
		return (modelnbr);
	else
		return (*obj_idx);
}

void			parse_obj(char *line, t_data *data, int *obj_idx, char *type)
{
	char		**parts;
	int			x;
	int			i;
	char		*str;

	x = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(line) + 50);
	while (line[x] != '\0')
	{
		while (ft_isdigit(line[x]) != 1 && line[x] != '\0' &&
				line[x] != ' ' && line[x] != '-' && ft_isalpha(line[x]) != 1)
			x++;
		str[i++] = line[x++];
	}
	str = padding(str, i, (int)ft_strlen(line) + 50);
	parts = ft_strsplit(str, ' ');
	copy_data(data, parts, get_object_index(type, data->modelnbr, obj_idx));
	init_parsed_data(data, type, get_object_index(type,
				data->modelnbr, obj_idx));
	free(str);
	ft_free_strarray(parts);
}
