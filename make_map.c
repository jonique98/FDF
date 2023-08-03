/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:12:26 by josumin           #+#    #+#             */
/*   Updated: 2023/08/04 00:22:03 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*make_map_line(int fd)
{
	char	*arr;
	char	*temp;

	arr = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == 0)
			break ;
		arr = ft_strjoin(arr, temp, 0, 0);
	}
	return (arr);
}

void	make_int_map(int **arr, t_map *map)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	temp = map->arr;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			arr[i][j] = make_num(&temp);
			j++;
		}
		i++;
	}
}

int	**make_map(t_map *map)
{
	int	**temp;
	int	i;

	i = -1;
	temp = malloc(sizeof(int *) * map->height);
	while (++i < map->height)
		temp[i] = malloc(sizeof(int) * map->width);
	make_int_map(temp, map);
	return (temp);
}
