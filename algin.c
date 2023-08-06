/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:16:02 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 10:43:51 by sumjo            ###   ########.fr       */
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

// void	algin_image(t_map *map, t_data *image)
// {
// 	int	x_move;
// 	int	y_move;
// 	int	i;
// 	int	j;

// 	x_move = 0;
// 	y_move = 0;
// 	i = -1;
// 	while (map->min_x + x_move < 0)
// 		x_move++;
// 	while (map->min_y + y_move < 0)
// 		y_move++;
// 	while (++i < map->height)
// 	{
// 		j = -1;
// 		while (++j < map->width)
// 		{
// 			map->offset[i][j].x += x_move;
// 			map->offset[i][j].y += y_move;
// 		}
// 	}
// }