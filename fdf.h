/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:06:46 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 06:36:29 by sumjo            ###   ########.fr       */
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
#include<stdio.h>

# define DEF 35
# define WIN_MAX_X 2560
# define WIN_MAX_Y 1440
# define MAR 100

typedef struct c_data
{
	long	x;
	long	y;
	long	z;
	int	r;
	int	g;
	int	b;
}		t_cordinate;

typedef struct m_data
{
	t_cordinate	**offset;
	int			width;
	int			height;
	int			max_x;
	int			min_x;
	int			max_y;
	int			min_y;
	int			gap;
	char		*arr;
	int			**map;
	int			win_width;
	int			win_height;
}	t_map;


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}		t_data;

void	init_map(int fd, t_map *map);
void	make_offset(t_map *map);
void	init_image(t_map *m, t_data *i);
void	algin_image(t_map *map, t_data *image);
void	draw_dot(t_map *map, t_data *image);

void	projection(t_map *map);

void	rotate_x(t_cordinate *c, double gamma);
void	rotate_y(t_cordinate *c, double beta);
void	rotate_z(t_cordinate *c, double alpha);

int		is_num(char a);
int		width_cnt(char *arr);
int		height_cnt(char *arr);
int		make_num(char **arr);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_dot(t_map *map, t_data *image);

void	algin_image(t_map *map, t_data *image);

t_cordinate	**make_map(t_map *map);
char	*make_map_line(int fd);
void	init_cordinate(t_cordinate **offset, t_map *map);

void	dda(t_map * map, t_data *image, t_cordinate offset1, t_cordinate offset2);
void	draw_line(t_map *map, t_data *image);

void	init_gap(t_map *map);
void	init_image(t_map *m, t_data *i);
void	offset_cordinate(t_map *map, int i, int j);
void	make_offset(t_map *map);

int		make_num_16(char **arr);
void	make_rgb(t_cordinate *c, char **arr, int i, int j);
int	rgb(int r, int g, int b);



#endif