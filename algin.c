/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:16:02 by josumin           #+#    #+#             */
/*   Updated: 2023/08/05 20:33:55 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algin_image(t_map *map, t_data *image)
{
	int	x_gap;
	int	y_gap;
	int	i;
	int	j;

	x_gap = 0;
	y_gap = 0;
	i = -1;
	while (map->min_x + x_gap < 0)
		x_gap++;
	while (map->min_y + y_gap < 0)
		y_gap++;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->offset[i][j].x += x_gap;
			map->offset[i][j].y += y_gap;
		}
	}
}

// void	algin_image(t_map *map, t_data *image)
// {
// 	int	x_gap;
// 	int	y_gap;
// 	int	i;
// 	int	j;

// 	x_gap = 0;
// 	y_gap = 0;
// 	i = -1;
// 	while (map->min_x + x_gap < 0)
// 		x_gap++;
// 	while (map->min_y + y_gap < 0)
// 		y_gap++;
// 	while (++i < map->height)
// 	{
// 		j = -1;
// 		while (++j < map->width)
// 		{
// 			map->offset[i][j].x += x_gap;
// 			map->offset[i][j].y += y_gap;
// 		}
// 	}
// }