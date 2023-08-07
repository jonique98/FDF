/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:16:02 by josumin           #+#    #+#             */
/*   Updated: 2023/08/07 09:43:21 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
