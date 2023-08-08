/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:42:50 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 00:10:50 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda(t_map *map, t_data *image, t_cordinate offset1, t_cordinate offset2)
{
	double	x_;
	double	y_;
	double	x_incre;
	double	y_incre;
	long	step;

	if (fabs(offset2.x - offset1.x) > fabs(offset2.y - offset1.y))
		step = fabs(offset2.x - offset1.x);
	else
		step = fabs(offset2.y - offset1.y);
	if (step == 0)
		step = 100;
	x_incre = (double)(offset2.x - offset1.x) / step;
	y_incre = (double)(offset2.y - offset1.y) / step;
	x_ = offset1.x;
	y_ = offset1.y;
	double r_change = (double)(offset1.r - offset2.r) / step;
	double g_change = (double)(offset1.g - offset2.g) / step;
	double b_change = (double)(offset1.b - offset2.b) / step;
	double r = offset1.r;
	double g = offset1.g;
	double b = offset1.b;
	while (step >= 0)
	{
		if (x_ >= 0 && y_ >= 0 && x_ < WIN_MAX_X && y_ < WIN_MAX_Y)
			my_mlx_pixel_put(image, round(x_), round(y_), rgb(round(r), round(g), round(b)));
		x_ += x_incre;
		y_ += y_incre;
		r += r_change;
		g += g_change;
		b += b_change;
		step--;
	}
}

// // void draw_line(t_map *map, t_data *image)
// // {
// // 	for(int i = map->height -1; i >= 0; i--)
// // 	{
// // 		for(int j = map->width -1; j >= 0; j--)
// // 		{
// // 			if (i - 1 >= 0)
// // 				dda(map, image, os[i][j], os[i - 1][j]);
// // 			if (j - 1 >= 0)
// // 				dda(map, image, os[i][j], os[i][j - 1]);
// // 			// if (j - 1 >= 0 && i - 1 >= 0)
// // 			// {
// // 			// 	dda(map, image, os[i][j], os[i - 1][j - 1]);
// // 			// 	dda(map, image, os[i-1][j], os[i][j - 1]);
// // 			// }
// // 		}
// // 	}
// // }

// void draw_line(t_map *map, t_data *image)
// {
// 	int			height;
// 	int			width;
// 	t_cordinate	**os;

// 	height = map->map_height;
// 	width = map->map_width;
// 	os = map->offset;

// 	while (--height >= 0)
// 	{
// 		while (--width >= 0)
// 		{
// 			if (width - 1 >= 0)
// 				dda(map, image, os[height][width], os[height][width - 1]);
// 			if (height - 1 >= 0)
// 				dda(map, image, os[height][width], os[height - 1][width]);
// 		}
// 		width = map->map_width;
// 	}
// }


void bresenham(t_map *map, t_data *image, t_cordinate p1, t_cordinate p2)
{
	int x1 = round(p1.x);
	int y1 = round(p1.y);
	int x2 = round(p2.x);
	int y2 = round(p2.y);

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		if (x1 >= 0 && y1 >= 0 && x1 < WIN_MAX_X && y1 < WIN_MAX_Y)
			my_mlx_pixel_put(image, x1, y1, rgb(round(p1.r), round(p1.g), round(p1.b)));

		if (x1 == x2 && y1 == y2)
			break ;

		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_line(t_map *map, t_data *image)
{
	int			height;
	int			width;
	t_cordinate	**os;

	height = map->map_height;
	width = map->map_width;
	os = map->offset;
	while (--height >= 0)
	{
		while (--width >= 0)
		{
			if (height - 1 >= 0)
				bresenham(map, image, os[height][width], os[height - 1][width]);
			if (width - 1 >= 0)
				bresenham(map, image, os[height][width], os[height][width - 1]);
		}
		width = map->map_width;
	}
}
