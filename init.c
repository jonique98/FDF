/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:13:21 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 06:38:19 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_gap(t_map *map)
{
	int	width;
	int	height;

	map->gap = DEF;
	width = map->width;
	height = map->height;
	while (map->gap * width > WIN_MAX_X || map->gap * height > WIN_MAX_Y)
		map->gap--;
}

void	init_map(int fd, t_map *map)
{
	int	i;

	i = -1;
	map->max_x = -2147482648;
	map->min_x = 2147483647;
	map->max_y = -2147483648;
	map->min_y = 2147483647;
	map->arr = make_map_line(fd);
	map->width = width_cnt(map->arr);
	map->height = height_cnt(map->arr);
	map->offset = make_map(map);
}

void	init_image(t_map *m, t_data *i)
{
	int	width;
	int	height;

	i->mlx_ptr = mlx_init();
	width = m->max_x - m->min_x + 1;
	height = m->max_y - m->min_y + 1;
	i->img = mlx_new_image(i->mlx_ptr, width, height);
	i->win_ptr = mlx_new_window(i->mlx_ptr, WIN_MAX_X, WIN_MAX_Y, "*");
	m->win_width = width;
	m->win_height = height;
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, &i->line_length, &i->endian);
}

void	offset_cordinate(t_map *map, int i, int j)
{
	int	x;
	int	y;
	int	z;
	x = map->offset[i][j].x;
	y = map->offset[i][j].y;
	z = map->offset[i][j].z;
	map->offset[i][j].x = x + (x * map->gap);
	map->offset[i][j].y = y + (y * map->gap);
	map->offset[i][j].z = -z * (map->gap * 0.5);
}

void	make_offset(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			offset_cordinate(map, i, j);
	}
}
