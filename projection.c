/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:42:24 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 06:37:54 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			rotate_z(&(map->offset[i][j]), -25 * (M_PI / 180));
			rotate_x(&(map->offset[i][j]), 10 * (M_PI / 180));
			rotate_y(&(map->offset[i][j]), -5 * (M_PI / 180));
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
