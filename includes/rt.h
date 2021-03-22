/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 09:35:11 by anikkane          #+#    #+#             */
/*   Updated: 2020/10/05 10:10:11 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "vectors.h"
# include "objects.h"
# include "model.h"

# define WIDTH 			1000
# define HEIGHT			1000

# define TRUE			1
# define FALSE			0

# define FOV			100

# define MAIN_PAD_ESC	53

# define THREAD_WIDTH 50
# define THREAD_NUMBER 20

typedef	struct		s_ray
{
	t_vector		start;
	t_vector		target;
	t_vector		newstart;

}					t_ray;

typedef	struct		s_hit
{
	double			t;
	char			*obj_name;
	int				obj_idx;
	int				poly_idx;
	int				poly;
	char			*preobj_name;
	int				preobj_mater;
	int				preobj_idx;
	int				find_shadow;
	int				in_shadow;
	t_vector		org_target;
	t_vector		org_start;
	t_vector		org_normal;
	t_vector		normal;
	t_texturemap	texture;
	t_vector		point;
	t_vector		pos;
	t_vector		rot;
	t_vector		axis;
	t_rgb2			color;
	int				radius;
	int				mater;
	int				refract;
	int				was_refract;
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
	double			color_intensity;
	int				reflection;
	int				light_scale;
	int				background;
	int				texture;

}					t_scene;

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
	int				modelnbr;
	double			light_scale;
	int				org_iter;
	int				iter;
	char			*scene_name;
	char			*obj_name;
	t_hit			hit;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_spot			*spot;
	t_plane			*plane;
	t_camera		*camera;
	t_scene			*scene;
	t_obj			obj[30];
	t_texturemap	*texture;
	t_model			*model;
}					t_data;

int					read_scene(t_data *data);
int					get_next_line(const int fd, char **line);
void				parse_scene(char *line, t_data *data);
void				init_data(t_data *data);
void				init_camera(t_data *data);
t_vector			init_target(int x, int y);
void				parse_sphere(char *line, t_data *data);
void				parse_cylinder(char *line, t_data *data);
void				parse_cone(char *line, t_data *data);
void				parse_spot(char *line, t_data *data);
void				parse_plane(char *line, t_data *data);
void				parse_camera(char *line, t_data *data);
void				parse_scene(char *line, t_data *data);
void				draw(t_data *data);
void				memory_allocation_fail(void);
void				get_color(t_data *data, int x, int y);
int					intersectsphere(t_ray ray, t_data *data, int i);
t_rgb				get_light(t_data *data, t_rgb rgb, t_ray ray, int i);
int					intersectcylinder(t_ray ray, t_data *data, int i);
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
void				wrong_argument_nbr(void);
void				data_read_error(void);
t_data				*allocate_memory(t_data *data);
void				free_memory(t_data *data);
void				init_mlx(t_data *data);
int					keypressed(int keycode);
char				*if_negative(char *line, char *str, int *i, int *y);
int					min(int num1, int num2);
t_ray				init_pixel(t_data *data, int x, int y, t_rgb *rgb);
void				put_color(t_data *data, t_rgb rgb, int x, int y);
void				wrong_scene_name(void);
t_vector			copy_lightpos(t_data *data, int i);
t_vec2				texture_mapping(t_hit hit, char *obj_name);
unsigned char		*parse_ppm(unsigned char *texture, char *path,
		t_res *res);
t_rgb2				assign_ppm_texture(t_data *data, unsigned char
		*ppm_image, t_vec2 uv);
unsigned char		*copy_ppm(t_data *data, char *name);
char				*parse_data_line(char *str, char *line, int *i, int y);
void				set_old_hit(t_data *data);
char				*parse_name(char *line, char *name);
void				parse_obj(char *line, t_data *data,
		int *obj_idx, char *type);
void				copy_data(t_data *data, char **parts, int e);
void				copy_scene_data(t_data *data, char **parts);
void				copy_sphere_data(t_data *data, char **parts, int e);
void				copy_plane_data(t_data *data, char **parts, int e);
void				copy_spot_data(t_data *data, char **parts, int e);
void				copy_cylinder_data(t_data *data, char **parts, int e);
void				copy_cone_data(t_data *data, char **parts, int e);
void				copy_camera_data(t_data *data, char **parts);
void				copy_model_data(t_data *data, char **parts, int e);
void				init_cylinder(t_data *data, int e);
void				init_cone(t_data *data, int e);
void				init_plane(t_data *data, int e);
void				init_model(t_data *data, int e);
void				init_sphere(t_data *data, int e);
void				init_parsed_data(t_data *data, char *type, int e);
t_obj				init_obj(t_obj *obj, int *obj_nbr);
int					intersecttriangle(t_ray ray, t_data *data, int y, int h);
int					validate_file(char *txt_name, char **path);
t_rgb2				checker_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size);
t_rgb2				vstripe_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size);
t_rgb2				ppm_texture(int width, int height,
		unsigned char *ppm_image, t_vec2 uv);
double				pat_size(double scale, char *obj_name, int radius);
t_rgb2				hstripe_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size);
t_rgb2				gradient_pattern(t_vec2 uv, t_rgb2 obj_color,
		double pat_size);
t_rgb2				add_texture(t_vec2 uv, t_rgb2 color, t_hit hit);
t_rgb2				split_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size);
t_vector			new_start_dir_triangle(t_data *data, t_ray *ray);
t_material			get_material(t_data *data, t_hit hit, int light_power);
t_rgb2				cyl_checker_pattern(t_vec2 uv, t_rgb2 obj_color,
		t_rgb2 texture_color, double pat_size);
char				*get_objpath(char *model);
void				copy_hit (t_data *data, char *obj_name);
void				copy_hit_sphere(t_data *data, int i);
void				copy_hit_plane(t_data *data, int i);
void				copy_hit_cylinder(t_data *data, int i);
void				copy_hit_cone(t_data *data, int i);
void				copy_hit_model(t_data *data, int i);
t_hit				set_hit_default(t_hit hit);
int					check_texture_pattern(char *name);
t_ray				shadow_ray(double *t, t_hit hit, t_ray ray, char *obj_name);
t_hit				init_hit(t_hit hit);
t_ray				reflection_dir(t_ray ray, t_vector n, t_data *data);
void				pthread(t_data *data);
t_vector			get_dist(t_vector light_pos, t_vector newstart);
t_rgb				get_light_intensity(t_data *data);
t_rgb				color_intensity(int scene_col_intensity, t_rgb2 color);
double				shadow_scale(int in_shadow, int iter, int org_iter);
double				get_lambert(t_data *data, t_vector target,
		t_vector newstart, t_vector dist);
void				get_resolution(int fd, double *x, double *y);
char				*get_res_line(int fd);
int					validate_format(int fd);
unsigned char		*fourth_channel_padding(unsigned char *texture,
		int width, int height);
double				dtr(double value);
int					hook_expose(t_data *data);

#endif
