/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:42:24 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 07:48:02 by sumjo            ###   ########.fr       */
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
			rotate_z(&(map->offset[i][j]), mod->radian_z);
			rotate_x(&(map->offset[i][j]), mod->radian_x);
			rotate_y(&(map->offset[i][j]), mod->radian_y);
		}
	}
	update_max_min(map);
}
