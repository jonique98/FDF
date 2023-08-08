/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:43:57 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 07:45:32 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data		image;
	t_map		map;
	t_modify	modify;
	t_param		param;

	if (ac != 2)
		return (0);
	init_image(&image);
	init_map(av[1], &map);
	init_param(&param, &map, &modify, &image);
	modify_scale(&map, &modify, 1);
	rotate(&param, 45, 30, -35);
	update_center(&map);
	set_move(&map, &modify, WIN_MAX_X / 2, WIN_MAX_Y / 2);
	move_image(param.map, param.mod);
	draw(&param);
	mlx_put_image_to_window(image.mlx, image.win, image.img, MAR / 2, MAR / 2);
	mlx_mouse_hook(image.win, mouse_event_down, &param);
	mlx_hook(image.win, 5, 0, mouse_event_up, &param);
	mlx_hook(image.win, 6, 0, mouse_event_draw, &param);
	mlx_hook(image.win, 2, 0, rotate_end, &param);
	mlx_loop(image.mlx);
}
