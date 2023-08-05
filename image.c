/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:15:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/06 08:02:30 by sumjo            ###   ########.fr       */
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
			// printf("%ld %ld\n", map->offset[i][j].x, map->offset[i][j].y);
			offset = map->offset[i][j];
			color = rgb(offset.r, offset.g, offset.b);
			my_mlx_pixel_put(image, map->offset[i][j].x, map->offset[i][j].y, color);
		}
	}
}
