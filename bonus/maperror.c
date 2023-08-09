/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:03:15 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 13:33:16 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	wrong_char_check(char *arr)
{
	if (!arr)
		exit(0);
	while (*arr)
	{
		if (*arr != ' ' && *arr != '-' && \
			(*arr < '0' || *arr > '9') && *arr != ',' && *arr != 'x' && \
			(*arr < 'a' || *arr > 'f') && *arr != 'F' && *arr != '\n')
			exit(0);
		arr++;
	}
}

void	size_check(t_map *map, char *arr)
{
	int	cnt;

	while (*arr)
	{
		cnt = 0;
		while (*arr && *arr != '\n')
		{
			if (is_num(*arr) || *arr == '-')
			{
				cnt++;
				while (is_num(*arr) || *arr == '-' || *arr == ',' \
				|| *arr == 'x' || (*arr >= 'a' && *arr <= 'f') || *arr == 'F')
					arr++;
			}
			else
			{
				while (*arr && *arr != '\n' && (*arr != '-' && !is_num(*arr)))
					arr++;
			}
		}
		if (cnt != map->map_width)
			exit(0);
		if (*arr)
			arr++;
	}
}
