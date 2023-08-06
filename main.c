/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/06 11:04:07 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	init_modify(t_modify *modify)
{
	modify->gap = 0;
	modify->radian_x = 0;
	modify->radian_y = 0;
	modify->radian_z = 0;
	modify->x_move = 0;
	modify->y_move = 0;
}

void	init_param(t_param *param, t_map *map, t_modify *modify, t_data *image)
{
	init_modify(modify);
	param->map = map;
	param->mod = modify;
	param->image = image;
}

void logic(t_map *map, t_data *image, t_modify *modify)
{
	make_offset(map, modify);
	projection(map, modify);
	set_move_val(map, modify, -map->min_x, -map->min_y); // move
	algin_image(map, modify);
	init_image(map, image);
	draw_dot(map, image);
	draw_line(map, image);
}

int	main(int ac, char **av)
{
	int			fd;
	t_data		image;
	t_map		map;
	t_modify	modify;
	t_param		param;

	fd = open(av[1], O_RDONLY);
	init_map(fd, &map);
	init_param(&param, &map, &modify, &image);
	set_gap(&map, &modify, DEF, 0); // scale
	set_radian(&modify, 40, 30, -30); // rotate
	logic(&map, &image, &modify);
	mlx_put_image_to_window(image.mlx, image.win, image.img, map.xm, map.ym);
	mlx_key_hook(image.win, &close1, &param);
	mlx_loop(image.mlx);
}

int  close1(int keycode, t_param *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->image->mlx, param->image->win);
		exit(0);
	}

	if (keycode == 123)
	{
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		for (int i = 0; i < param->map->win_height; i++)
		{
			for (int j = 0; j < param->map->win_height; j++)
				my_mlx_pixel_put(param->image, j, i, 0x000000);
		}
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym);
		param->image->img = mlx_new_image(param->image->mlx, 2560, 1440);
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		set_move_val(param->map, param->mod, -30, 0);
		algin_image(param->map, param->mod);
		// init_image(param->map, param->image);
		draw_dot(param->map, param->image);
		draw_line(param->map, param->image);
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym);
	}
	
	if (keycode == 124)
	{
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		for (int i = 0; i < param->map->win_height; i++)
		{
			for (int j = 0; j < param->map->win_height; j++)
				my_mlx_pixel_put(param->image, j, i, 0x000000);
		}
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym);
		param->image->img = mlx_new_image(param->image->mlx, 2560, 1440);
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		set_move_val(param->map, param->mod, 30, 0);
		algin_image(param->map, param->mod);
		// init_image(param->map, param->image);
		draw_dot(param->map, param->image);
		draw_line(param->map, param->image);
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, 0, 0);
	}
	if (keycode == 125)
	{
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		for (int i = 0; i < param->map->win_height; i++)
		{
			for (int j = 0; j < param->map->win_height; j++)
				my_mlx_pixel_put(param->image, j, i, 0x000000);
		}
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym);
		set_move_val(param->map, param->mod, 0, 10);
		param->image->img = mlx_new_image(param->image->mlx, 2560, 1440);
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		draw_dot(param->map, param->image);
		draw_line(param->map, param->image);
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym + param->mod->y_move);
	}
	if (keycode == 126)
	{
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		for (int i = 0; i < param->map->win_height; i++)
		{
			for (int j = 0; j < param->map->win_height; j++)
				my_mlx_pixel_put(param->image, j, i, 0x000000);
		}
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym);
		set_move_val(param->map, param->mod, 0, -10);
		param->image->img = mlx_new_image(param->image->mlx, 2560, 1440);
		param->image->addr = mlx_get_data_addr(param->image->img, &param->image->bits_per_pixel, &param->image->line_length, &param->image->endian);
		draw_dot(param->map, param->image);
		draw_line(param->map, param->image);
		mlx_put_image_to_window(param->image->mlx, param->image->win, param->image->img, param->map->xm, param->map->ym + param->mod->y_move);
	}
	return (0);
}


// int handle_mouse_press(int button, int x, int y, t_data *data)
// {
//     if (button == 1) // Left mouse button
//     {
//         data->is_dragging = 1;
//         data->x = x;
//         data->y = y;
//     }
//     return 0;
// }

// int handle_mouse_release(int button, int x, int y, t_data *data)
// {
//     if (button == 1) // Left mouse button
//     {
//         data->is_dragging = 0;
//     }
//     return 0;
// }

// int handle_mouse_move(int x, int y, t_data *data)
// {
//     if (data->is_dragging)
//     {
//         int dx = x - data->x;
//         int dy = y - data->y;
//         // 이동할 좌표 계산 및 그래픽 업데이트
//         // 이동에 따른 그래픽 객체의 위치를 업데이트하거나 그려주는 로직을 추가해야 합니다.

//         // 현재 위치 업데이트
//         data->x = x;
//         data->y = y;
//     }
//     return 0;
// }

// int main(void)
// {
//     mlx_mouse_hook(data.win, handle_mouse_press, &data);
//     mlx_hook(data.win, 4, 0, handle_mouse_release, &data);
//     mlx_hook(data.win, 6, 0, handle_mouse_move, &data);

//     mlx_loop(data.mlx);
// }