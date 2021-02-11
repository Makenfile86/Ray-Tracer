/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 09:35:11 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/05 10:10:11 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vectors.h"
# include "rt.h"
# include "../libft/libft.h"

typedef struct		s_res
{
	double			x;
	double			y;
}					t_res;

typedef struct		s_material
{
	double			diffuse_red;
	double			diffuse_green;
	double			diffuse_blue;

}					t_material;

typedef	struct		s_color
{
	int8_t			channel[4];

}					t_color;

typedef struct		s_rgb2
{
	int				red;
	int				blue;
	int				green;
}					t_rgb2;

typedef	struct		s_texturemap
{
	int				scale;
	t_res			res;
	int				txt_loaded;
	int				txt_pattern;
	int				type;
	t_rgb2			color;
	char			*name;
	char			*path;
	unsigned char	*txt_ppm;
}					t_texturemap;

typedef struct		s_rgb
{
	double			red;
	double			blue;
	double			green;
}					t_rgb;

typedef struct		s_sphere
{
	t_vector		xyz[30];
	t_material		material[30];
	int				radius[30];
	t_vector		rot[30];
	t_rgb2			rgb2[30];
	int				nbr;
	double			mater[30];
	int				checker[30];
	t_texturemap	texture[30];
}					t_sphere;

typedef struct		s_plane
{
	int				nbr;
	t_vector		xyz[30];
	int				radius[30];
	t_vector		point[30];
	t_vector		normal[30];
	t_rgb2			rgb2[30];
	t_vector		rot[30];
	double			mater[30];
	int				checker[30];
	int				ring[30];
	t_texturemap	texture[30];
}					t_plane;

typedef struct		s_spot
{
	int				x[30];
	int				y[30];
	int				z[30];
	double			intensity_red[30];
	double			intensity_green[30];
	double			intensity_blue[30];
	t_color			color[30];
	int				power[30];
	int				nbr;
}					t_spot;

typedef struct		s_cylinder
{
	t_vector		start_xyz[30];
	t_vector		end_xyz[30];
	t_vector		axis[30];
	t_vector		rot[30];
	int				radius[30];
	int				length[30];
	int				nbr;
	t_rgb2			rgb2[30];
	double			mater[30];
	t_texturemap	texture[30];
}					t_cylinder;

typedef struct		s_cone
{
	t_vector		start_xyz[30];
	t_vector		rot[30];
	t_vector		axis[30];
	double			angle[30];
	t_rgb2			rgb2[30];
	int				nbr;
	double			mater[30];
	t_texturemap	texture[30];

}					t_cone;

#endif
