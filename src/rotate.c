/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:36:48 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 06:01:51 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_cordinate *c, double gamma)
{
	double	prev_y;
	double	prev_z;

	prev_y = c->y;
	prev_z = c->z;
	c->y = (prev_y * cos(gamma)) + (prev_z * sin(gamma));
	c->z = (-prev_y * sin(gamma)) + (prev_z * cos(gamma));
}

void	rotate_y(t_cordinate *c, double beta)
{
	double	prev_x;
	double	prev_z;

	prev_x = c->x;
	prev_z = c->z;
	c->x = (prev_x * cos(beta)) + prev_z * sin(beta);
	c->z = (-prev_x * sin(beta)) + prev_z * cos(beta);
}

void	rotate_z(t_cordinate *c, double alpha)
{
	double	prev_x;
	double	prev_y;

	prev_x = c->x;
	prev_y = c->y;
	c->x = prev_x * cos(alpha) + prev_y * sin(alpha);
	c->y = -prev_x * sin(alpha) + prev_y * cos(alpha);
}
