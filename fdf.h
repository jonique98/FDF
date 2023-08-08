/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:06:46 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 06:10:35 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "./mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define DEF 1
# define WIN_MAX_X 1920
# define WIN_MAX_Y 1080
# define MAR 10
# define MOUSE_LEFT_BUTTON 1
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5 
# define KEY_ESC 53

typedef struct c_data
{
	double	x;
	double	y;
	double	z;
	int		r;
	int		g;
	int		b;
}		t_cordinate;

typedef struct m_data
{
	t_cordinate	**offset;
	int			map_width;
	int			map_height;
	long long	max_x;
	long long	min_x;
	long long	max_y;
	long long	min_y;
	long long	center_x;
	long long	center_y;
	char		*arr;
}	t_map;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}		t_data;

typedef struct s_modify
{
	double		gap;
	double		scale;
	double		ratio;
	long long	x_move;
	long long	y_move;
	double		radian_x;
	double		radian_y;
	double		radian_z;
}		t_modify;

typedef struct s_param
{
	t_map		*map;
	t_data		*image;
	t_modify	*mod;
	int			mouse_dragging;
	int			mouse_x;
	int			mouse_y;
	int			z_rotate;
}		t_param;

void			update_max_min(t_map *map);
void			update_center(t_map *map);

t_cordinate		**make_map(t_map *map);
char			*make_map_line(int fd, int *error);
void			dda(t_map *map, t_data *image, \
				t_cordinate offset1, t_cordinate offset2);
void			draw_line(t_map *map, t_data *image);

void			init_map(char *av, t_map *map);
void			make_offset(t_map *map, t_modify *mod);
void			algin_image(t_map *map, t_modify *mod);
void			draw_dot(t_map *map, t_data *image);
void			projection(t_map *map, t_modify *mod);

void			rotate_x(t_cordinate *center, double gamma);
void			rotate_y(t_cordinate *center, double beta);
void			rotate_z(t_cordinate *center, double alpha);

int				is_num(char a);
int				width_cnt(char *arr);
int				height_cnt(char *arr);
int				make_num(char **arr);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_dot(t_map *map, t_data *image);

void			offset_cordinate(t_map *map, t_modify *mod, int i, int j);
void			make_offset(t_map *map, t_modify *mod);
void			init_gap(t_map *map, t_modify *modify);
void			init_image(t_data *i);

int				make_num_16(char **arr);
void			make_rgb(t_cordinate *c, char **arr, int i, int j);
int				rgb(int r, int g, int b);
void			modify_scale(t_map *map, t_modify *mod, int a);

void			set_radian(t_modify *modify, double x, double y, double z);
void			init_move_val(t_modify *mod, int x_move, int y_move);
void			set_gap(t_map *map, t_modify *mod, int gap);
void			logic(t_map *map, t_data *image, t_modify *modify);

void			move_image(t_map *map, t_modify *mod);
void			move(t_param *p, int x_move, int y_move);
void			draw(t_param *p);
void			scale(t_param *param, double scale);
void			rotate(t_param *param, double x, double y, double z);
void			set_move(t_map *map, t_modify *modify, \
				long long center_x, long long center_y);
int				rotate_end(int keycode, t_param *param);

int				mouse_event_draw(int x, int y, t_param *p);
int				mouse_event_down(int keycode, int x, int y, t_param *p);
int				mouse_event_up(int keycode, int x, int y, t_param *p);
void			update_max_min(t_map *map);
void			destroy(t_param *p);
int				rotate_end(int keycode, t_param *p);
void			make_new_img(t_param *p);
void			init_param(t_param *param, t_map *map, \
				t_modify *modify, t_data *image);
void			wrong_char_check(char *arr);
void			size_check(t_map *map, char *arr);

#endif