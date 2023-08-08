/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:15:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 00:36:04 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) \
		+ (x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
				my_mlx_pixel_put(image, (map->offset[i][j].x), \
				(map->offset[i][j].y), color);
		}
	}
}

void	make_new_img(t_param *p)
{
	mlx_destroy_image(p->image->mlx, p->image->img);
	p->image->img = mlx_new_image(p->image->mlx, WIN_MAX_X, WIN_MAX_Y);
	p->image->addr = mlx_get_data_addr(p->image->img, \
	&p->image->bits_per_pixel, &p->image->line_length, &p->image->endian);
}
