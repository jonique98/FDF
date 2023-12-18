/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:24:03 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 14:34:59 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	draw(t_param *p)
{
	draw_dot(p->map, p->image);
	draw_line(p->map, p->image);
}

void	rotate(t_param *param, double x, double y, double z)
{
	set_radian(param->mod, x, y, z);
	projection(param->map, param->mod);
}

void	scale(t_param *param, double scale)
{
	if (param->mod->ratio * scale < param->mod->gap / 20
		|| param->map->max_x * scale > 80000
		|| param->map->max_y * scale > 80000)
		return ;
	param->mod->ratio *= scale;
	param->mod->scale = scale;
	modify_scale(param->map, param->mod, 0);
}

void	modify_scale(t_map *map, t_modify *mod, int a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
				map->offset[i][j].x = map->offset[i][j].x * mod->scale;
				map->offset[i][j].y = map->offset[i][j].y * mod->scale;
			if (a == 1)
				map->offset[i][j].z = -map->offset[i][j].z * (mod->scale * 0.4);
			else
				map->offset[i][j].z = map->offset[i][j].z * mod->scale;
		}
	}
	map->max_x = round(map->max_x * mod->scale);
	map->min_x = round(map->min_x * mod->scale);
	map->max_y = round(map->max_y * mod->scale);
	map->min_y = round(map->min_y * mod->scale);
}
