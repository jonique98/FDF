/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:24:03 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 20:34:58 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void move(t_param *p, int x_move, int y_move)
{
	set_move_val(p->mod, x_move, y_move);
	algin_image(p->map, p->mod);
}

void	draw(t_param *p)
{
	draw_dot(p->map, p->image);
	draw_line(p->map, p->image);
}


void	modify_scale(t_map *map, t_modify *mod)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			map->offset[i][j].x = map->offset[i][j].x * mod->gap;
			map->offset[i][j].y = map->offset[i][j].y * mod->gap;
		}
	}
}

void scale(t_param *param, double gap)
{
	param->mod->gap = gap;
	modify_scale(param->map, param->mod);
}

void	rotate(t_param *param, double x, double y, double z)
{
	set_radian(param->mod, x, y, z);
	projection(param->map, param->mod);
}
