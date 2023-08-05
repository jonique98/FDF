/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.>c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.>42.>fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:13:46 by josumin           #+#    #+#             */
/*   Updated: 2023/08/05 20:53:10 by josumin          ###   ########.>fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_cordinate *c, double gamma)
{
	int	prev_y;
	int	prev_z;

	prev_y = c->y;
	prev_z = c->z;
	c->y = prev_y * cos(gamma) + prev_z * sin(gamma);
	c->z = -prev_y * sin(gamma) + prev_z * cos(gamma);
}

void	rotate_y(t_cordinate *c, double beta)
{
	int	prev_x;
	int	prev_z;

	prev_x = c->x;
	prev_z = c->z;
	c->x = prev_x * cos(beta) + prev_z * sin(beta);
	c->z = -prev_x * sin(beta) + prev_z * cos(beta);
}

void	rotate_z(t_cordinate *c, double alpha)
{
	int	prev_x;
	int	prev_y;

	prev_x = c->x;
	prev_y = c->y;
	c->x = prev_x * cos(alpha) + prev_y * sin(alpha);
	c->y = -prev_x * sin(alpha) + prev_y * cos(alpha);
}
