/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:12:26 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 04:01:38 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*make_map_line(int fd, int *error)
{
	char	*arr;
	char	*temp;

	arr = 0;
	while (1)
	{
		temp = get_next_line(fd, error);
		if (temp == 0)
			break ;
		arr = ft_strjoin(arr, temp);
		free(temp);
	}
	return (arr);
}

void	init_cordinate(t_cordinate **offset, t_map *map)
{
	int			i;
	int			j;
	char		*temp;

	i = 0;
	temp = map->arr;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			offset[i][j].x = j;
			offset[i][j].y = i;
			offset[i][j].z = make_num(&temp);
			make_rgb(&offset[i][j], &temp, i, j);
			j++;
		}
		i++;
	}
}

t_cordinate	**make_map(t_map *map)
{
	t_cordinate	**offset;
	int			i;

	i = -1;
	offset = malloc(sizeof(t_cordinate *) * map->map_height);
	if (!offset)
		exit(0);
	while (++i < map->map_height)
	{
		offset[i] = malloc(sizeof(t_cordinate) * map->map_width);
		if (!offset[i])
			exit(0);
	}
	init_cordinate(offset, map);
	return (offset);
}
