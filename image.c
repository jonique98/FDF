/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:15:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 20:33:31 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_dot(t_map *map, t_data *image)
{
	t_cordinate	offset;
	int			i;
	int			j;
	int			color;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			offset = map->offset[i][j];
			color = rgb(offset.r, offset.g, offset.b);
			if (map->offset[i][j].x >= 0 && map->offset[i][j].x < WIN_MAX_X
				&& map->offset[i][j].y >= 0 && map->offset[i][j].y < WIN_MAX_Y)
				my_mlx_pixel_put(image, round(map->offset[i][j].x), round(map->offset[i][j].y), color);
		}
	}
}
