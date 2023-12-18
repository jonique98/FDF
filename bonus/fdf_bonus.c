/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:25:53 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 14:34:47 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

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
	rotate(&param, 90, 0, 0);
	update_center(&map);
	set_move(&map, &modify, WIN_MAX_X / 2, WIN_MAX_Y / 2);
	move_image(param.map, param.mod);
	draw(&param);
	mlx_put_image_to_window(image.mlx, image.win, image.img, MAR / 2, MAR / 2);
	mlx_hook(image.win, 2, 0, rotate_end, &param);
	mlx_mouse_hook(image.win, mouse_event_down, &param);
	mlx_hook(image.win, 5, 0, mouse_event_up, &param);
	mlx_hook(image.win, 6, 0, mouse_event_draw, &param);
	mlx_hook(image.win, 17, 0, end, &param);
	mlx_loop(image.mlx);
}
