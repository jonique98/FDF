/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/04 02:29:33 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dda(t_data *image, t_cordinate offset1, t_cordinate offset2)
{
	int		step;
	double	x_;
	double	y_;
	double	x_incre;
	double	y_incre;

	if (fabs(offset1.x - offset2.x) > fabs(offset1.y - offset2.y))
		step = fabs(offset1.x - offset2.x);
	else
		step = fabs(offset1.y - offset2.y);
	x_incre = (offset2.x - offset1.x) / step;
	y_incre = (offset2.y - offset1.y) / step;
	x_ = offset1.x;
	y_ = offset1.y;
	my_mlx_pixel_put(image, round(x_), round(y_), 0XFFFFFF);
	while (--step)
	{
		x_ += x_incre;
		y_ += y_incre;
		my_mlx_pixel_put(image, round(x_), round(y_), 0XFFFFFF);
	}
}

void draw_line(t_map *map, t_data *image)
{
	for(int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
		{
			if (i + 1 < map->height)
				dda(image, map->offset[i][j], map->offset[i + 1][j]);
			if (j + 1 < map->width)
				dda(image, map->offset[i][j], map->offset[i][j + 1]);
		}
	}
}

int	main(int ac, char **av)
{
	int			fd;
	t_cordinate	center;
	t_data		image;
	t_map		map;

	fd = open(av[1], O_RDONLY);
	init_map(fd, &map);
	make_offset(&map);
	init_image(&map, &image);
	algin_image(&map, &image);
	draw_dot(&map, &image);
	draw_line(&map, &image);
	mlx_put_image_to_window(image.mlx_ptr, image.win_ptr, image.img, MAR /2, MAR / 2);
	mlx_loop(image.mlx_ptr);
	return (0);
}
