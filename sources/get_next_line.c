/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_net_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:25:02 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/15 10:40:34 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			check_stack(char **s)
{
	size_t			i;
	char			*temp;

	temp = *s;
	i = 0;
	while (temp[i] != '\n')
	{
		if (temp[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static int			check_errors(const int fd, char **line, char **s)
{
	if (fd == -1 || FD_MAXSET < fd || BUFF_SIZE < 1 || !line ||
			(!(s[fd]) && !(s[fd] = ft_strnew(0))))
		return (0);
	return (1);
}

static size_t		scl(const char *s, char c)
{
	size_t len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		len++;
	}
	return (len);
}

static	int			last_line(const int fd, char **line, char **s)
{
	if (!(*line = ft_strsub(s[fd], 0, ft_strlen(s[fd]))))
		return (-1);
	ft_strdel(&s[fd]);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*s[FD_MAXSET];
	char			*temp;

	if ((read(fd, buff, 0) == -1) || !(check_errors(fd, line, s)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) || (check_stack(&s[fd]) == 1))
	{
		buff[ret] = '\0';
		temp = s[fd];
		if (!(s[fd] = ft_strjoin(temp, buff)))
			return (-1);
		free(temp);
		if (((check_stack(&s[fd]) == 1)) || ft_strchr(buff, '\n') != 0)
		{
			if (!(*line = (ft_strsub(s[fd], 0, scl(s[fd], '\n')))))
				return (-1);
			ft_strcpy(s[fd], ft_strchr(s[fd], '\n') + 1);
			return (1);
		}
	}
	if ((*s[fd]) && (last_line(fd, line, s) == 1))
		return (1);
	return (0);
}
