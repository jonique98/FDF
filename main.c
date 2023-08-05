/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/06 08:19:11 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int  close1(int keycode, t_data *image)
{
	if (keycode == 53)
	{
		mlx_destroy_window(image->mlx, image->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	t_data		image;
	t_map		map;
	t_modify	modify;

	fd = open(av[1], O_RDONLY);
	init_map(fd, &map);
	set_gap(&map, &modify, DEF, 0); // scale
	set_radian(&modify, 40, 30, -30); // rotate
	set_move_val(&map, &modify, -map.min_x, -map.min_y); // move
	make_offset(&map, &modify);
	projection(&map, &modify);
	algin_image(&map, &image, &modify);
	init_image(&map, &image);
	draw_dot(&map, &image);
	draw_line(&map, &image);
	mlx_put_image_to_window(image.mlx, image.win, image.img, map.xm, map.ym);
	mlx_key_hook(image.win, close1, &image);
	mlx_loop(image.mlx);
	return (0);
}
