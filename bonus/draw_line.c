/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:42:50 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 14:34:44 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	dda(t_data *image, t_cordinate offset1, t_cordinate offset2)
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
	while (step >= 0)
	{
		if (x_ >= 0 && y_ >= 0 && x_ < WIN_MAX_X && y_ < WIN_MAX_Y)
			my_mlx_pixel_put(image, round(x_), round(y_), 0xffffff);
		x_ += x_incre;
		y_ += y_incre;
		step--;
	}
}

void	bresenham(t_data *image, t_cordinate p1, t_cordinate p2)
{
	t_bresenham	b;

	b.x1 = round(p1.x);
	b.y1 = round(p1.y);
	b.x2 = round(p2.x);
	b.y2 = round(p2.y);
	b.dx = abs(b.x2 - b.x1);
	b.dy = abs(b.y2 - b.y1);
	if (b.x1 < b.x2)
		b.sx = 1;
	else
		b.sx = -1;
	if (b.y1 < b.y2)
		b.sy = 1;
	else
		b.sy = -1;
	b.err = b.dx - b.dy;
	while (1)
	{
		if (b.x1 >= 0 && b.y1 >= 0 && b.x1 < WIN_MAX_X && b.y1 < WIN_MAX_Y)
			my_mlx_pixel_put(image, b.x1, b.y1, p1.color);
		if (b.x1 == b.x2 && b.y1 == b.y2)
			break ;
		update_coordinates(&b);
	}
}

void	draw_line(t_map *map, t_data *image)
{
	int			i;
	int			j;
	t_cordinate	**os;

	os = map->offset;
	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			if (i + 1 < map->map_height)
				bresenham(image, os[i][j], os[i + 1][j]);
			if (j + 1 < map->map_width)
				bresenham(image, os[i][j], os[i][j + 1]);
		}
	}
}
