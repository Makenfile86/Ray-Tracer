# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 14:45:40 by mkivipur          #+#    #+#              #
#    Updated: 2020/07/02 09:38:34 by mkivipur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

SRCS = ./sources/dtr.c ./sources/parse_texture2.c ./sources/light2.c ./sources/textures2.c ./sources/texture_mapping2.c ./sources/reflection.c ./sources/hit.c ./sources/texture_utils.c ./sources/parse_model2.c ./sources/textures.c ./sources/model.c ./sources/intersect_triangle.c ./sources/parse_model.c ./sources/copy_data.c ./sources/renderer.c ./sources/main.c ./sources/material.c ./sources/read.c ./sources/parser.c ./sources/scene.c ./sources/get_next_line.c ./sources/draw.c ./sources/color.c ./vec_calc/vector_calc.c ./vec_calc/vector_calc2.c ./vec_calc/rotate_vec.c ./sources/init.c ./sources/intersect_sphere.c ./sources/intersect_plane.c ./sources/intersect_cylinder.c ./sources/intersect_cone.c ./sources/shadow.c ./sources/error.c ./sources/memory.c ./sources/cylinder.c ./sources/camera.c ./sources/plane.c ./sources/cone.c ./sources/sphere.c ./sources/spot.c ./sources/utils.c ./sources/light.c ./sources/texture_mapping.c ./sources/parse_texture.c


MLX_LNK	= -L /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit

HDR = ./includes/ 

LIBFT = libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(MLX_LNK) $(SRCS) -I $(HDR) -L. libft/libft.a
clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all