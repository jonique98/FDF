/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/05 21:02:20 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	int			fd;
	t_data		image;
	t_map		map;

	fd = open(av[1], O_RDONLY);
	init_map(fd, &map);
	make_offset(&map);
	projection(&map);
	init_image(&map, &image);
	algin_image(&map, &image);
	draw_dot(&map, &image);
	draw_line(&map, &image);
	mlx_put_image_to_window(image.mlx_ptr, image.win_ptr, image.img, MAR / 2, MAR / 2);
	mlx_loop(image.mlx_ptr);
	return (0);
}
