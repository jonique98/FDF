/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:42:24 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 08:01:15 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_map *map, t_modify *mod)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			rotate_x(&(map->offset[i][j]), mod->radian_x);
			rotate_y(&(map->offset[i][j]), mod->radian_y);
			rotate_z(&(map->offset[i][j]), mod->radian_z);
			if (map->offset[i][j].x > map->max_x)
				map->max_x = map->offset[i][j].x;
			if (map->offset[i][j].x < map->min_x)
				map->min_x = map->offset[i][j].x;
			if (map->offset[i][j].y > map->max_y)
				map->max_y = map->offset[i][j].y;
			if (map->offset[i][j].y < map->min_y)
				map->min_y = map->offset[i][j].y;
		}
	}
}
