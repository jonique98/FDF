/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:42:50 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 20:36:19 by josumin          ###   ########.fr       */
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

// void draw_line(t_map *map, t_data *image)
// {
// 	for(int i = map->height -1; i >= 0; i--)
// 	{
// 		for(int j = map->width -1; j >= 0; j--)
// 		{
// 			if (i - 1 >= 0)
// 				dda(map, image, os[i][j], os[i - 1][j]);
// 			if (j - 1 >= 0)
// 				dda(map, image, os[i][j], os[i][j - 1]);
// 			// if (j - 1 >= 0 && i - 1 >= 0)
// 			// {
// 			// 	dda(map, image, os[i][j], os[i - 1][j - 1]);
// 			// 	dda(map, image, os[i-1][j], os[i][j - 1]);
// 			// }
// 		}
// 	}
// }

void draw_line(t_map *map, t_data *image)
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
			if (width - 1 >= 0)
				dda(map, image, os[height][width], os[height][width - 1]);
			if (height - 1 >= 0)
				dda(map, image, os[height][width], os[height - 1][width]);
		}
		width = map->map_width;
	}
}


