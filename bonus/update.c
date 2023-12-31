/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:31:20 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 14:35:16 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	update_max_min(t_map *map)
{	
	int	i;
	int	j;

	i = -1;
	j = -1;
	map->min_x = map->offset[0][0].x;
	map->max_x = map->offset[0][0].x;
	map->min_y = map->offset[0][0].y;
	map->max_y = map->offset[0][0].y;
	while (++i < map->map_height)
	{
		while (++j < map->map_width)
		{
			if (map->offset[i][j].x < map->min_x)
				map->min_x = map->offset[i][j].x;
			if (map->offset[i][j].x > map->max_x)
				map->max_x = map->offset[i][j].x;
			if (map->offset[i][j].y < map->min_y)
				map->min_y = map->offset[i][j].y;
			if (map->offset[i][j].y > map->max_y)
				map->max_y = map->offset[i][j].y;
		}
		j = -1;
	}
}

void	update_center(t_map *map)
{
	map->center_x = (map->max_x + map->min_x) / 2;
	map->center_y = (map->max_y + map->min_y) / 2;
}

void	update_coordinates(t_bresenham *b)
{
	int	err;

	err = b->err;
	if (err > -(b->dy))
	{
		b->err -= b->dy;
		b->x1 += b->sx;
	}
	if (err < b->dx)
	{
		b->err += b->dx;
		b->y1 += b->sy;
	}
}
