/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:50:19 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 07:53:41 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	make_rgb(t_cordinate *c, char **arr, int i, int j)
{
	if (**arr == ',')
	{
		(*arr)++;
		if (**arr != '0')
			exit(0);
		(*arr)++;
		if (**arr != 'x')
			exit(0);
		(*arr)++;
		if (!is_num(**arr) && !(**arr >= 'a' && **arr <= 'f')
			&& **arr != 'F')
			exit(0);
		c->r = make_num_16(arr);
		c->g = make_num_16(arr);
		c->b = make_num_16(arr);
	}
	else
	{
		c->r = 0;
		c->g = 0;
		c->b = 0;
	}
}
