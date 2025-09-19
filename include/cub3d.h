/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:43:37 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/19 17:51:10 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TILE_SIZE 32
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define FLT_MAX 3.40282347e+38F

# define WIDTH 1000
# define HEIGHT 1200
# define FOV_ANGLE 1.0471975512
# define NUM_RAYS WIDTH

typedef struct s_move
{
	float	move_step;
	float	strafe_step;
	float	new_x;
	float	new_y;
	float	radius;
}	t_move;

typedef struct s_ray
{
	float	rayangle;
	float	wallhitx;
	float	wallhity;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
}	t_ray;

typedef struct s_ray_params
{
	float	yintercept;
	float	xintercept;
	float	ystep;
	float	xstep;
}	t_ray_params;

typedef struct s_hit
{
	float	dist;
	float	x;
	float	y;
}	t_hit;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	radius;
	float	turndirection;
	float	walkdirection;
	float	strafedirection;
	float	rotationangle;
	float	walkspeed;
	float	turnspeed;
}	t_player;

typedef struct s_vmap
{
	char	*path;
	char	*str;
	char	*color;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceil;
	int		n_floor;
	int		n_ceil;
	t_img	north_img;
	t_img	south_img;
	t_img	west_img;
	t_img	east_img;
}	t_vmap;

typedef struct s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	char		**map;
	int			map_width;
	int			map_height;
	t_img		img;
	t_img		ani;
	t_img		wall;
	t_vmap		v_map;
	t_player	player;
	t_ray		rays[NUM_RAYS];
}	t_data;

typedef struct s_value
{
	t_data	*data;
	int		wallstripheightjplane;
	int		*i;
	int		*y;
	int		wallbottompixel;
	int		texx;
	t_img	*tex;
}	t_value;

typedef struct s_decstr
{
	int		i;
	int		wallstripheightjplane;
	int		walltoppixel;
	int		wallbottompixel;
	int		texx;
	int		y;
	t_img	*tex;
	t_value	v;
}	t_decstr;

char			*get_next_line(int fd);
char			*read_file(int fd, char *left_over, char *buffer);
char			*extr_line(char *line);
char			*ft_left_over(char *line);
void			ft_putstr_fd(char *s, int fd);
int				ft_strlen(const char *s);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strchr(char *s, char c);
char			**ft_split(char const *s, char *sep);
void			free_2d_array(char **arr);
int				ft_count_2d_array(char **arr);
void			*ft_memset(void *b, int c, size_t len);
int				ft_strcmp(char *s1, char *s2);
long			ft_atoi(char *str);
int				ft_isdigit(int c);
char			*ft_strtrim(char *s1, char *set);
char			*ft_strtrim_end(char *s1, char *set);
char			*ft_strstr(char *str, char *to_find);
int				ft_parsing(char *map, t_data *data);
int				check_extention(char *map);
int				check_first_part(int fd, char *line, int count, t_data *data);
int				check_line(t_data *data, char *line, int *count);
int				check_v_path(char *str, char *path);
int				check_v_color(char *color, char *path, t_data *data);
int				check_comma(char *path);
int				check_number(char *color, char *path, t_data *data);
int				check_res(char **res);
int				check_element(char *str);
char			*get_word(char *line, int count);
int				check_extention(char *map);
void			free_v_map(t_vmap *v_map);
int				index_end(char *line);
int				index_start(char *line);
int				fd_player(char p);
int				found_player(char **_2darray);
char			**check_map(char **map);
void			free_all(t_data *data);
int				ft_tchklast_laine(char *line, char *lineTow, char *linThre);
int				chick_all_line(char *str);
int				tchk_fixsed_mapp(char **maps, int contLaien, int j, int i);
int				init_window(t_data *data);
void			move_player(t_data *data);
void			cleanup(t_data *data);
void			handle_event(t_data *data);
float			normalize_angl(float angle);
int				cast_ray(t_data *data, int columId, float rayangle);
void			cast_all_rays(t_data *data);
float			d_bt_points(float x1, float y1, float x2, float y2);
int				has_wall_at(t_data *data, float x, float y);
void			project_wall(t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				load_textures(t_data *data);
unsigned int	get_pixel_color(t_img *img, int x, int y);
int				put_image(t_data *data);
int				put_addr(t_data *data);
int				load_textures(t_data *data);
void			tchck_vertecal_presontal(t_img **tex, t_data *data, int *i);
int				tcheck_ofset(t_data *data, int *i, t_img *tex);
void			print_ceil(t_data *data, int *i, int *y, int walltoppixel);
void			print_floor(t_data *data, int *i, int *y);
int				calcul_hite_wall(t_data *data, int *i);
unsigned int	get_pixel_color(t_img *img, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				has_wall_at_1337(t_data *data, float x, float y);
void			free_2d_array(char **arr);
char			**men(void);
int				has_wall_at(t_data *data, float x, float y);
int				calculate_height(char **map);
int				calculate_width(char **map);
float			d_bt_points(float x1, float y1, float x2, float y2);
void			init_hit(t_hit *hit);
void			choose_hit(t_ray *ray, t_hit horz, t_hit ver);
t_ray_params	set_horz_params(t_data *data, t_ray *ray, float angle);
t_ray_params	set_ver_params(t_data *data, t_ray *ray, float angle);
void			get_horz_hit(t_data *data,
					t_ray *ray, t_ray_params p, t_hit *hit);
void			get_ver_hit(t_data *data,
					t_ray *ray, t_ray_params p, t_hit *hit);
int				ft_tchklast_laine(char *line, char *lineTow, char *linThre);
int				ft_tcheck_ziro_he(int lin, int li, char *lineTow, char *hd);
int				ft_tcheck_ziro(int lin, int li, char *lineTow);
#endif