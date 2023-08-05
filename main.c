/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/06 06:36:18 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			fd;
	t_data		image;
	t_map		map;

	fd = open(av[1], O_RDONLY);
	init_map(fd, &map);
	init_gap(&map);
	make_offset(&map);
	projection(&map);
	algin_image(&map, &image);
	init_image(&map, &image);
	draw_dot(&map, &image);
	draw_line(&map, &image);
	mlx_put_image_to_window(image.mlx_ptr, image.win_ptr, image.img, (WIN_MAX_X - map.max_x) / 2, (WIN_MAX_Y - map.max_y) / 2);
	mlx_loop(image.mlx_ptr);
	return (0);
}
