/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/06 21:01:41 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// int handle_mouse_press(int button, int x, int y, t_param *p)
// {
//     if (button == 2) // Left mouse button
//     {
// 		write(1, "click\n", 6);
//         p->mouse_dragging = 1;
//         p->mouse_x = x;
//         p->mouse_y = y;
//     }
//     return 0;
// }


// int handle_mouse_move(int x, int y, t_param *p)
// {
// 	write(1, "click\n", 6);
//     if (p->mouse_dragging == 1)
//     {
//         int dx = x - p->mouse_x;
//         int dy = y - p->mouse_y;
        
// 		mlx_destroy_image(p->image->mlx, p->image->img);
// 		p->image->img = mlx_new_image(p->image->mlx, WIN_MAX_X, WIN_MAX_Y);
// 		p->image->addr = mlx_get_data_addr(p->image->img, &p->image->bits_per_pixel, &p->image->line_length, &p->image->endian);
// 		move(p, dx, dy);
// 		draw(p);
// 		mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, MAR / 2, MAR / 2);
// 		// 이동할 좌표 계산 및 그래픽 업데이트
//         // 이동에 따른 그래픽 객체의 위치를 업데이트하거나 그려주는 로직을 추가해야 합니다.

//         // 현재 위치 업데이트
//         p->mouse_x = x;
//         p->mouse_y = y;
//     }
//     return 0;
// }

void	init_modify(t_modify *modify)
{
	modify->radian_x = 0;
	modify->radian_y = 0;
	modify->radian_z = 0;
	modify->x_move = 0;
	modify->y_move = 0;
	modify->gap = DEF;
}

void	init_param(t_param *param, t_map *map, t_modify *modify, t_data *image)
{
	param->mouse_dragging = 0;
	init_modify(modify);
	param->map = map;
	param->mod = modify;
	param->image = image;
}

void	init_move(t_map *map, t_modify *modify)
	{
		modify->x_move = -((map->max_x + map->min_x) / 2) + (WIN_MAX_X / 2);
		modify->y_move = -((map->max_y + map->min_y) / 2) + (WIN_MAX_Y / 2);
	}

// int	handle_mouse_release(int button, int x, int y, t_param *p)
// {
// 	mlx_destroy_image(p->image->mlx, p->image->img);
// 	p->image->img = mlx_new_image(p->image->mlx, WIN_MAX_X, WIN_MAX_Y);
// 	p->image->addr = mlx_get_data_addr(p->image->img, &p->image->bits_per_pixel, &p->image->line_length, &p->image->endian);
// 	if (button == 4)
// 	{
// 		scale(p, 1.1);
// 		rotate(p, 0, 0, 0);
// 		init_move(p->map, p->mod);
// 		move(p, p->mod->x_move, p->mod->y_move);
// 		draw(p);
// 	}
// 	else if (button == 5)
// 	{
// 		scale(p, 0.9);
// 		rotate(p, 0, 0, 0);
// 		init_move(p->map, p->mod);
// 		move(p, p->mod->x_move, p->mod->y_move);
// 		draw(p);
// 	}
// 	mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, MAR / 2, MAR / 2);
// }

int	main(int ac, char **av)
{
	t_data		image;
	t_map		map;
	t_modify	modify;
	t_param		param;

	init_image(&image);
	init_map(av[1], &map);
	init_param(&param, &map, &modify, &image);

	make_offset(&map, &modify);
	scale(&param, 1);

	rotate(&param, 45, 30, -35);

	init_move(&map, &modify);
	move(&param, modify.x_move, modify.y_move);

	draw(&param);

	mlx_put_image_to_window(image.mlx, image.win, image.img, MAR / 2, MAR / 2);
	// mlx_mouse_hook(image.win, handle_mouse_press, &param);
	// mlx_hook(image.win, 2, 0, handle_mouse_move, &param);
    // mlx_hook(image.win, 4, 0, handle_mouse_release, &param);
	mlx_key_hook(image.win, transform, &param);
	mlx_loop(image.mlx);
}

int  transform(int keycode, t_param *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->image->mlx, p->image->win);
		exit(0);
	}
	// mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, p->map->xm, p->map->ym);
	mlx_destroy_image(p->image->mlx, p->image->img);
	p->image->img = mlx_new_image(p->image->mlx, WIN_MAX_X, WIN_MAX_Y);
	p->image->addr = mlx_get_data_addr(p->image->img, &p->image->bits_per_pixel, &p->image->line_length, &p->image->endian);
	if (keycode == 123)
		move(p, -10, 0);
	else if (keycode == 124)
		move(p, 10, 0);
	else if (keycode == 125)
		move(p, 0, 10);
	else if (keycode == 126)
		move(p, 0, -10);
	draw(p);
	mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, MAR / 2, MAR / 2);
	return (0);
}



// int main(void)
// {
// 	t_data		image;

// 	init_image(&image);
//     // mlx_hook(image.win, 6, 0, handle_mouse_move, &data);

//     mlx_loop(image.mlx);
// }