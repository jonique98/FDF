/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:19:13 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/07 09:44:49 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_modify(t_modify *modify)
{
	modify->radian_x = 0;
	modify->radian_y = 0;
	modify->radian_z = 0;
	modify->x_move = 0;
	modify->y_move = 0;
	modify->gap = DEF;
}

void	init_gap(t_map *map, t_modify *modify)
{
	while (map->map_width * modify->gap < WIN_MAX_X && map->map_height * modify->gap < WIN_MAX_Y)
		modify->gap++;
	modify->ratio = modify->gap;
	modify->scale = modify->gap;
}

void	init_param(t_param *param, t_map *map, t_modify *modify, t_data *image)
{
	init_modify(modify);
	init_gap(map, modify);
	param->mouse_dragging = 0;
	param->map = map;
	param->mod = modify;
	param->image = image;
	param->z_rotate = 0;
}

void	init_move(t_map *map, t_modify *modify, int center_x, int center_y)
{
	modify->x_move = -(map->max_x + map->min_x) / 2 + center_x;
	modify->y_move = -(map->max_y + map->min_y) / 2 + center_y;
}
