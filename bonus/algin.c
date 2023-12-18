/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:16:02 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 14:34:40 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	algin_image(t_map *map, t_modify *mod)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			map->offset[i][j].x += mod->x_move;
			map->offset[i][j].y += mod->y_move;
		}
	}
	map->max_x += mod->x_move;
	map->min_x += mod->x_move;
	map->max_y += mod->y_move;
	map->min_y += mod->y_move;
}

void	move_image(t_map *map, t_modify *mod)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			map->offset[i][j].x += mod->x_move;
			map->offset[i][j].y += mod->y_move;
		}
	}
	map->max_x += mod->x_move;
	map->min_x += mod->x_move;
	map->max_y += mod->y_move;
	map->min_y += mod->y_move;
	map->center_x += mod->x_move;
	map->center_y += mod->y_move;
}

void	init_move_val(t_modify *mod, int x_move, int y_move)
{
	mod->x_move = x_move;
	mod->y_move = y_move;
}
