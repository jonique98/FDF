/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:01:23 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 10:40:36 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	offset_cordinate(t_map *map, t_modify *mod, int i, int j)
{
	int	x;
	int	y;
	int	z;

	x = map->offset[i][j].x;
	y = map->offset[i][j].y;
	z = map->offset[i][j].z;
	map->offset[i][j].x = x + (i * mod->gap);
	map->offset[i][j].y = y + (j * mod->gap);
	map->offset[i][j].z = -z * (mod->gap * 0.3);
	if (map->offset[i][j].x > map->max_x)
		map->max_x = map->offset[i][j].x;
	if (map->offset[i][j].x < map->min_x)
		map->min_x = map->offset[i][j].x;
	if (map->offset[i][j].y > map->max_y)
		map->max_y = map->offset[i][j].y;
	if (map->offset[i][j].y < map->min_y)
		map->min_y = map->offset[i][j].y;
}

void	make_offset(t_map *map, t_modify *mod)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
			offset_cordinate(map, mod, i, j);
	}
}
