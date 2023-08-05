/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:50:19 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/06 04:54:38 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

int	make_num_16(char **arr)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (i < 2 && (is_num(**arr) || (**arr >= 'a' && **arr <= 'f')
			|| (**arr >= 'A' && **arr <= 'F')))
	{
		if (is_num(**arr))
			num = num * 16 + (**arr - '0');
		else if (**arr >= 'a' && **arr <= 'f')
			num = num * 16 + (**arr - 'a' + 10);
		else if (**arr >= 'A' && **arr <= 'F')
			num = num * 16 + (**arr - 'A' + 10);
		(*arr)++;
		i++;
	}
	return (num);
}

void	make_rgb(t_cordinate *c, char **arr, int i, int j)
{
	if (**arr == ',')
	{
		(*arr)+=3;
		c->r = make_num_16(arr);
		c->g = make_num_16(arr);
		c->b = make_num_16(arr);
	}
	else
	{
		c->r = 100;
		c->g = 100;
		c->b = 100;
	}
}
