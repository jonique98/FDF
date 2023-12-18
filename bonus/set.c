/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:31:28 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 14:35:14 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	set_radian(t_modify *modify, double x, double y, double z)
{
	modify->radian_x = x * (M_PI / 180);
	modify->radian_y = y * (M_PI / 180);
	modify->radian_z = z * (M_PI / 180);
}

void	set_move(t_map *map, t_modify *modify, \
		long long center_x, long long center_y)
{
	modify->x_move = -(map->max_x + map->min_x) / 2 + center_x;
	modify->y_move = -(map->max_y + map->min_y) / 2 + center_y;
}
