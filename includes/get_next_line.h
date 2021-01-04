/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:14:59 by mkivipur          #+#    #+#             */
/*   Updated: 2020/07/15 12:43:23 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# define FD_MAXSET 4864

# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
