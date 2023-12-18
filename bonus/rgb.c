/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:50:19 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 14:35:11 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	make_rgb(t_cordinate *c, char **arr)
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
		c->color = make_num_16(arr);
	}
	else
		c->color = 0xffffff;
	(*arr)++;
}
