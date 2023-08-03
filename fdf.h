/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:06:46 by josumin           #+#    #+#             */
/*   Updated: 2023/08/04 01:59:17 by josumin          ###   ########.fr       */
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

# define DEF 30
# define WIN_MAX_X 2000
# define WIN_MAX_Y 1500
# define MAR 100

typedef struct c_data
{
	int	x;
	int	y;
	int	z;
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
void	init_image(t_map *map, t_data *image);
void	algin_image(t_map *map, t_data *image);
void	draw_dot(t_map *map, t_data *image);

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

char	*make_map_line(int fd);
void	make_int_map(int **arr, t_map *map);
int		**make_map(t_map *map);

void	dda(t_data *image, t_cordinate offset1, t_cordinate offset2);
void	draw_line(t_map *map, t_data *image);



#endif