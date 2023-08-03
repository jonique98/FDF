/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:13:21 by josumin           #+#    #+#             */
/*   Updated: 2023/08/04 02:38:23 by josumin          ###   ########.fr       */
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
	while (map->gap * width > WIN_MAX_X || map->gap * width > WIN_MAX_Y)
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

	width = m->max_x - m->min_x;
	height = m->max_y - m->min_y;
	i->mlx_ptr = mlx_init();
	i->img = mlx_new_image(i->mlx_ptr, width + 200, height + 200);
	i->win_ptr = mlx_new_window(i->mlx_ptr, width + MAR, height + MAR, "*");
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, &i->line_length, &i->endian);
}

void	init_cordinate(t_map *map, int i, int j)
{
	t_cordinate	c;

	c.x = j - ((map->width - 1) * map->gap / 2) + (j * map->gap);
	c.y = i - ((map->height - 1) * map->gap / 2) + (i * map->gap);
	c.z = -map->map[i][j] * (map->gap * 0.15);
	rotate_z(&c, -35.365 * (M_PI / 180));
	rotate_x(&c, 45 * (M_PI / 180));
	map->offset[i][j] = c;
	if (c.x > map->max_x)
		map->max_x = c.x;
	if (c.x < map->min_x)
		map->min_x = c.x;
	if (c.y > map->max_y)
		map->max_y = c.y;
	if (c.y < map->min_y)
		map->min_y = c.y;
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
