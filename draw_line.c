/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:42:50 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 06:34:41 by sumjo            ###   ########.fr       */
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

	if (labs(offset2.x - offset1.x) > labs(offset2.y - offset1.y))
		step = labs(offset2.x - offset1.x);
	else
		step = labs(offset2.y - offset1.y);
	if (step == 0)
		step = 5;
	x_incre = (double)(offset2.x - offset1.x) / step;
	y_incre = (double)(offset2.y - offset1.y) / step;
	x_ = offset1.x;
	y_ = offset1.y;
	int r_change = (offset2.r - offset1.r) / step;
	int g_change = (offset2.g - offset1.g) / step;
	int b_change = (offset2.b - offset1.b) / step;
	int r = offset1.r;
	int g = offset1.g;
	int b = offset1.b;
	while (step >= 0)
	{
		my_mlx_pixel_put(image, round(x_), round(y_), rgb(r, g, b));
		x_ += x_incre;
		y_ += y_incre;
		r += r_change;
		g += g_change;
		b += b_change;
		step--;
	}
}

void draw_line(t_map *map, t_data *image)
{
	for(int i = map->height -1; i >= 0; i--)
	{
		for(int j = map->width -1; j >= 0; j--)
		{
			if (i - 1 >= 0)
				dda(map, image, map->offset[i][j], map->offset[i - 1][j]);
			if (j - 1 >= 0)
				dda(map, image, map->offset[i][j], map->offset[i][j - 1]);
			if (j - 1 >= 0 && i - 1 >= 0)
			{
				dda(map, image, map->offset[i][j], map->offset[i - 1][j - 1]);
				dda(map, image, map->offset[i-1][j], map->offset[i][j - 1]);
			}
			// if (j + 1 < map->width && i + 1 < map->height)
			// 	dda(map, image, map->offset[i+1][j], map->offset[i][j + 1]);
		}
	}
}
