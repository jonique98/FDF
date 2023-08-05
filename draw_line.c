/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:42:50 by josumin           #+#    #+#             */
/*   Updated: 2023/08/05 16:27:55 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dda(t_map * map, t_data *image, t_cordinate offset1, t_cordinate offset2)
{
	int		step;
	double	x_;
	double	y_;
	double	x_incre;
	double	y_incre;

	if (fabs(offset2.x - offset1.x) > fabs(offset2.y - offset1.y))
	{
		step = fabs(offset2.x - offset1.x);
	}
	else
	{
		step = fabs(offset2.y - offset1.y);
	}
	x_incre = (double)(offset2.x - offset1.x) / step;
	y_incre = (double)(offset2.y - offset1.y) / step;
	x_ = offset1.x;
	y_ = offset1.y;
	while (step >= 0)
	{
		if (round(x_) >= 0 && round(x_) <=  map->win_width &&
            round(y_) >= 0 && round(y_) <= map->win_height) {
            my_mlx_pixel_put(image, round(x_), round(y_), 0xFFFFFF);
        }
        x_ += x_incre;
        y_ += y_incre;
        step--;
    }
}




void draw_line(t_map *map, t_data *image)
{
	for(int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
		{
			if (i + 1 < map->height)
				dda(map, image, map->offset[i][j], map->offset[i + 1][j]);
			if (j + 1 < map->width)
				dda(map, image, map->offset[i][j], map->offset[i][j + 1]);
			// if (j + 1 < map->width && i + 1 < map->height)
			// 	dda(map, image, map->offset[i][j], map->offset[i + 1][j + 1]);
		}
	}
}
