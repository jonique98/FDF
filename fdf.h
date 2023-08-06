/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:06:46 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 20:35:12 by josumin          ###   ########.fr       */
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

# define DEF 35
# define WIN_MAX_X 1920
# define WIN_MAX_Y 1080
# define MAR 10

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
	int			max_x;
	int			min_x;
	int			max_y;
	int			min_y;
	char		*arr;
	int			win_width;
	int			win_height;
	int			xm;
	int			ym;
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
	double		x_move;
	double		y_move;
	double	radian_x;
	double	radian_y;
	double	radian_z;
}		t_modify;

typedef struct s_param
{
	t_map		*map;
	t_data		*image;
	t_modify	*mod;
	int			mouse_dragging;
	int			mouse_x;
	int			mouse_y;
}		t_param;


t_cordinate		**make_map(t_map *map);
char			*make_map_line(int fd);
void			dda(t_map * map, t_data *image, t_cordinate offset1, t_cordinate offset2);
void			draw_line(t_map *map, t_data *image);

void			init_map(char *av, t_map *map);
void			make_offset(t_map *map, t_modify *mod);
void			algin_image(t_map *map, t_modify *mod);
void			draw_dot(t_map *map, t_data *image);
void			projection(t_map *map, t_modify *mod);

void			rotate_x(t_cordinate *c, double gamma);
void			rotate_y(t_cordinate *c, double beta);
void			rotate_z(t_cordinate *c, double alpha);

int				is_num(char a);
int				width_cnt(char *arr);
int				height_cnt(char *arr);
int				make_num(char **arr);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_dot(t_map *map, t_data *image);

void			offset_cordinate(t_map *map, t_modify *mod, int i, int j);
void			make_offset(t_map *map, t_modify *mod);
void			init_gap(t_map *map, t_modify *mod, int gap, int a);
void			init_image(t_data *i);

int				make_num_16(char **arr);
void			make_rgb(t_cordinate *c, char **arr, int i, int j);
int				rgb(int r, int g, int b);

void			set_radian(t_modify *modify, double x, double y, double z);
void			set_move_val(t_modify *mod, int x_move, int y_move);
void			set_gap(t_map *map, t_modify *mod, int gap);
void			logic(t_map *map, t_data *image, t_modify *modify);

void move(t_param *p, int x_move, int y_move);
void	draw(t_param *p);
void scale(t_param *param, double gap);
void	rotate(t_param *param, double x, double y, double z);
	void	init_move(t_map *map, t_modify *modify);
	
int  transform(int keycode, t_param *param);

#endif