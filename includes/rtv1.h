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

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "vectors.h"
# include "objects.h"


# define WIDTH 			1000
# define HEIGHT			1000

# define FOV			90

# define MAIN_PAD_ESC	53

# define DTR(k)	((double)k * (M_PI / 180))





typedef	struct		s_ray
{
	t_vector		start;
	t_vector		target;
	t_vector		newstart;

}					t_ray;






typedef struct			s_fresnel
{
	double				kr;
	double				cosi;
	double				etai;
	double				etat;
	double				sint;
	double				cost;
	double				rs;
	double				rp;
}						t_fresnel;




typedef	struct		s_hit
{
	double			t;
	char			*obj_name;
	int				obj_idx;
	char 			*preobj_name;
	int				preobj_mater;
	int				preobj_idx;
	int				find_shadow;
	t_vector		org_target;
	t_vector		org_start;
	t_vector		org_normal;
	t_vector		normal;
	t_texturemap 	texture;
	int				mater;
	int				refract;
	double			refract_lent;
	int				double_target;
	double			a;
	double			b;
	double			fresnel;
}					t_hit;

typedef struct		s_camera
{
	t_vector		xyz;
	t_vector		target;
	t_vector		rot;
	t_vector		direction;
	t_vector		right;
	t_vector		up;
}					t_camera;

typedef struct		s_scene
{
	int				shadows;
	int				lambert;
	int				ref_iter;
	double				color_intensity;
	int				reflection;
	int				light_scale;
	int				background;

}					t_scene;

typedef struct		s_texture
{
	char *name;
}					t_texture;

typedef struct		s_data
{
	void			*win;
	void			*mlx;
	char			*data_addr;
	int				bits_per_pixel;
	void			*image;
	int				size_line;
	int				endian;
	int				start_line;
	int				finish_line;
	int				objnbr;
	double			light_scale;
	int				org_iter;
	int				iter;
	char			*scene_name;
	int				exposure;
	double			mat;
	double			x;
	double 			y;
	double 			pattern;
	char 			*obj_name;
	t_hit			hit;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_spot			*spot;
	t_plane			*plane;
	t_camera		*camera;
	t_scene			*scene;
	t_texturemap		*texture;
}					t_data;

int					read_scene(t_data *data);
int					get_next_line(const int fd, char **line);
void				parse_scene(char *line, t_data *data);
void				init_data(t_data *data);
void				init_camera(t_data *data);
t_vector			init_target(int x, int y);
void			init_scene(t_data *data);
void				parse_sphere(char *line, t_data *data);
void				parse_cylinder(char *line, t_data *data);
void				parse_cone(char *line, t_data *data);
void				parse_spot(char *line, t_data *data);
void				parse_plane(char *line, t_data *data);
void				parse_camera(char *line, t_data *data);
void				parse_scene(char *line, t_data *data);
void				draw(t_data *data);
void				get_color(t_data *data, int x, int y);
double				vectordot(t_vector v1, t_vector v2);
t_vector			vectoradd(t_vector v1, t_vector v2);
t_vector			vectorscale(double c, t_vector v);
t_vector			vector_minus(t_vector v1, t_vector v2);
t_vector			normalized_vector(t_vector v);
t_vector			vector_plus(t_vector v1, t_vector v2);
t_vector			return_vector(int x, int y, int z);
int					intersectsphere(t_ray ray, t_data *data, int i);
t_rgb				get_light(t_data *data, t_rgb rgb, t_ray ray, int i);
t_vector			cross_vector(t_vector v1, t_vector v2);
t_vector			rotate_vector(t_vector origin, t_vector target,
		t_vector rot, int no_z);
int					intersectcylinder(t_ray ray, t_data *data, int i);
double				double_sqr(double n);
t_vector			vectorsub(t_vector a, t_vector b);
t_vector			vectoradd(t_vector v1, t_vector v2);
int					intersectplane(t_data *data, int i, t_ray ray);
int					intersectcone(t_ray ray, t_data *data, int i);
void				set_hit(t_data *data, char *name, int i);
t_vector			new_start_dir_plane(t_data *data, t_ray *ray);
t_vector			new_start_dir_sphere(t_data *data, t_ray *ray);
t_vector			new_start_dir_cylinder(t_data *data, t_ray *ray);
t_vector			new_start_dir_cone(t_data *data, t_ray *ray);
int					shadow_sphere(t_vector newstart, int i, t_data *data,
		t_vector light_pos);
int					shadow_cone(t_vector newstart, int i, t_data *data,
		t_vector light_pos);
int					shadow_cylinder(t_vector newstart, int i, t_data *data,
		t_vector light_pos);
int					shadow_plane(t_vector newstart, int i, t_data *data,
		t_vector light_pos);
int					shadow(t_data *data, t_vector newstart, int i);
t_vector			vectornew(double x, double y, double z);
double				vector_length(t_vector v);
t_vector			vector_copy(t_vector v);
t_vector			vec_rot_zyx(t_vector v, t_vector r);
t_vector			vec_rot_z(t_vector v, double a);
t_vector			vec_rot_y(t_vector v, double a);
t_vector			vec_rot_x(t_vector v, double a);
void				memory_allocation_fail(void);
void				wrong_argument_nbr(void);
void				data_read_error(void);
t_data				*allocate_memory(t_data *data);
void				free_memory(t_data *data);
void				init_mlx(t_data *data);
int					keypressed(int keycode);
char				*if_negative(char *line, char *str, int *i, int *y);
int 				min(int num1, int num2);
t_ray  				init_pixel(t_data *data, int x, int y, t_rgb *rgb);
void 				put_color(t_data *data, t_rgb rgb, int x, int y);
void				wrong_scene_name(void);
t_vector 			copy_lightpos(t_data *data, int i);
int		handle_expose(t_data *tmp_data);
void texture_mapping(t_data *data, t_vector n, char *obj_name);
unsigned char    *parse_ppm(t_data *data, unsigned char *texture, int type);
t_rgb2 assign_ppm_texture(t_data *data, unsigned char *ppm_image, t_vec2 uv);
unsigned char *copy_ppm(t_data *data, int type);
char *parse_data_line(char *str, char *line, int *i, int y);
t_rgb get_background_color(t_data *data, int x, int y);
void		draw_background(t_data *data);
t_material mirror_effect(t_data *data, int i);
t_material glass_effect(t_data *data, int i);
void set_old_hit(t_data *data);
char		*parse_name(char *line, char *name);
void			parse_obj(char *line, t_data *data, int *obj_idx, char *type);
void		copy_data(t_data *data, char *str, int *x, int e);
void		copy_scene_data(t_data *data, char *str, int x);
void		copy_sphere_data(t_data *data, char *str, int x, int e);
void			copy_plane_data(t_data *data, char *str, int x, int e);
void		copy_spot_data(t_data *data, char *str, int x, int e);
void		copy_cylinder_data(t_data *data, char *str, int x, int e);
void		copy_cone_data(t_data *data, char *str, int x, int e);
void			copy_camera_data(t_data *data, char *str, int x);
void		init_cylinder(t_data *data, int e);
void		init_cone(t_data *data, int e);
void		init_plane(t_data *data, int e);
void init_sphere(t_data *data, int e);
void			init_parsed_data(t_data *data, char *type, int e);

#endif
