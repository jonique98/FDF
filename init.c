/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:13:21 by josumin           #+#    #+#             */
/*   Updated: 2023/08/05 21:04:35 by josumin          ###   ########.fr       */
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
	map->map = make_map(map);
	map->offset = malloc(sizeof(t_cordinate *) * map->height);
	while (++i < map->height)
		map->offset[i] = malloc(sizeof(t_cordinate) * map->width);
	init_gap(map);
}

void	init_image(t_map *m, t_data *i)
{
	int	width;
	int	height;

	i->mlx_ptr = mlx_init();
	width = abs(m->max_x - m->min_x) + 1;
	height = abs(m->max_y - m->min_y) + 1;
	i->img = mlx_new_image(i->mlx_ptr, width, height);
	i->win_ptr = mlx_new_window(i->mlx_ptr, width + MAR, height + MAR, "*");
	m->win_width = width;
	m->win_height = height;
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, &i->line_length, &i->endian);
}

void	init_cordinate(t_map *map, int i, int j)
{
	t_cordinate	c;

	c.x = j + (j * map->gap);
	c.y = i + (i * map->gap);
	c.z = -map->map[i][j] * (map->gap * 0.2);
	map->offset[i][j] = c;
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
			init_cordinate(map, i, j);
	}
}
