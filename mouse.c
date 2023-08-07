/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:17:32 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/07 09:50:04 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_event_draw(int x, int y, t_param *p)
{
	int	dx;
	int	dy;

	if (p->mouse_dragging)
	{
		make_new_img(p);
		dx = (x - p->mouse_x);
		dy = (y - p->mouse_y);
		set_move_val(p->mod, dx, dy);
		move_image(p->map, p->mod);
		draw(p);
		mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, MAR / 2, MAR / 2);
		p->mouse_x = x;
		p->mouse_y = y;
	}
	return (0);
}

int	mouse_event_down(int keycode, int x, int y, t_param *p)
{
	if (keycode == MOUSE_LEFT_BUTTON)
	{
		p->mouse_dragging = 1;
		p->mouse_x = x;
		p->mouse_y = y;
		return (0);
	}
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		make_new_img(p);
		if (keycode == MOUSE_SCROLL_UP)
			scale(p, 0.7);
		else
			scale(p, 1.5);
		init_move(p->map, p->mod, p->map->center_x, p->map->center_y);
		algin_image(p->map, p->mod);
		draw(p);
		mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, MAR / 2, MAR / 2);
	}
	return (0);
}

int	mouse_event_up(int keycode, int x, int y, t_param *p)
{
	if (keycode == MOUSE_LEFT_BUTTON)
	{
		p->mouse_dragging = 0;
		p->mouse_x = x;
		p->mouse_y = y;
	}
	return (0);
}

void	destroy(t_param *p)
{
	int	i;

	i = -1;
	while (++i < p->map->map_height)
		free(p->map->offset[i]);
	free(p->map->offset);
	// free(p->map);
	// free(p->image);
	// free(p->mod);
	// free(p);
	mlx_destroy_image(p->image->mlx, p->image->img);
	exit(0);
}

int	rotate_end(int keycode, t_param *p)
{
	if (keycode == 53)
		destroy(p);
	make_new_img(p);
	if (keycode == 6 && p->z_rotate)
		p->z_rotate = 0;
	else if (keycode == 6 && p->z_rotate == 0)
		p->z_rotate = 1;
	if (keycode == 123 && p->z_rotate == 0)
		rotate(p, 0, 10, 0);
	else if (keycode == 123 && p->z_rotate == 1)
		rotate(p, 0, 0, 10);
	else if (keycode == 124 && p->z_rotate == 0)
		rotate(p, 0, -10, 0);
	else if (keycode == 124 && p->z_rotate == 1)
		rotate(p, 0, 0, -10);
	else if (keycode == 125)
		rotate(p, -10, 0, 0);
	else if (keycode == 126)
		rotate(p, 10, 0, 0);
	init_move(p->map, p->mod, p->map->center_x, p->map->center_y);
	algin_image(p->map, p->mod);
	draw(p);
	mlx_put_image_to_window(p->image->mlx, p->image->win, p->image->img, MAR / 2, MAR / 2);
	return (0);
}
