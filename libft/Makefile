# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:14:44 by mkivipur          #+#    #+#              #
#    Updated: 2019/10/30 10:27:46 by mkivipur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRC = ft_atof.c ft_fabs.c ft_dclamp.c ft_dmax.c ft_dswap.c ft_free_strarray.c ft_atoi.c ft_memdel.c ft_strcmp.c ft_strncpy.c ft_bzero.c ft_memmove.c	ft_strcpy.c	ft_strnequ.c ft_isalnum.c ft_memset.c ft_strdel.c ft_strnew.c ft_isalpha.c ft_putchar.c ft_strdup.c ft_strnstr.c ft_isascii.c ft_putchar_fd.c ft_strequ.c ft_strrchr.c ft_isdigit.c ft_putendl.c ft_striter.c ft_strsplit.c ft_isprint.c ft_putendl_fd.c ft_striteri.c ft_strstr.c ft_itoa.c ft_putnbr.c ft_strjoin.c ft_strsub.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_memalloc.c ft_putstr.c ft_strlen.c ft_tolower.c ft_memccpy.c ft_putstr_fd.c	ft_strmap.c	ft_toupper.c ft_memchr.c	ft_strcat.c	ft_strmapi.c ft_memcmp.c	ft_strchr.c	ft_strncat.c ft_memcpy.c	ft_strclr.c	ft_strncmp.c 

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
