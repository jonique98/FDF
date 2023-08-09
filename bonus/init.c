/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:13:21 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 12:47:14 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

void	init_map_var(t_map *map)
{
	map->map_width = 0;
	map->map_height = 0;
	map->max_x = 0;
	map->min_x = 0;
	map->max_y = 0;
	map->min_y = 0;
	map->center_x = WIN_MAX_X / 2;
	map->center_y = WIN_MAX_Y / 2;
	map->offset = 0;
}

void	init_map(char *av, t_map *map)
{
	int	i;
	int	fd;
	int	error;

	error = 0;
	i = -1;
	fd = open(av, O_RDONLY);
	if (fd == -1 || ft_strlen(av) < 5 \
		|| ft_strncmp(av + ft_strlen(av) - 4, ".fdf", 4))
		exit(0);
	init_map_var(map);
	map->arr = make_map_line(fd, &error);
	if (error)
		exit(0);
	wrong_char_check(map->arr);
	map->map_width = width_cnt(map->arr);
	map->map_height = height_cnt(map->arr);
	if (map->map_width == 0 || map->map_height == 0)
		exit(0);
	size_check(map, map->arr);
	map->offset = make_map(map);
	free(map->arr);
}

void	init_image(t_data *i)
{
	i->mlx = mlx_init();
	i->img = mlx_new_image(i->mlx, WIN_MAX_X, WIN_MAX_Y);
	i->win = mlx_new_window(i->mlx, WIN_MAX_X + MAR, WIN_MAX_Y + MAR, "*");
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, \
	&i->line_length, &i->endian);
}
