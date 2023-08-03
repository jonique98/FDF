/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:15:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/04 00:27:03 by josumin          ###   ########.fr       */
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
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			my_mlx_pixel_put(image, map->offset[i][j].x, map->offset[i][j].y, 0xFFFFFF);
	}
}
