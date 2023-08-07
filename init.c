/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:13:21 by josumin           #+#    #+#             */
/*   Updated: 2023/08/07 09:43:42 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(char *av, t_map *map)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(av, O_RDONLY);
	map->max_x = 0;
	map->min_x = 0;
	map->max_y = 0;
	map->min_y = 0;
	map->arr = make_map_line(fd);
	map->map_width = width_cnt(map->arr);
	map->map_height = height_cnt(map->arr);
	map->offset = make_map(map);
	map->center_x = WIN_MAX_X / 2;
	map->center_y = WIN_MAX_Y / 2;
}

void	init_image(t_data *i)
{
	i->mlx = mlx_init();
	i->img = mlx_new_image(i->mlx, WIN_MAX_X, WIN_MAX_Y);
	i->win = mlx_new_window(i->mlx, WIN_MAX_X + MAR, WIN_MAX_Y + MAR, "*");
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, &i->line_length, &i->endian);
}

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
