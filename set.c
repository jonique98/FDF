/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 07:31:28 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/07 09:31:13 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_radian(t_modify *modify, double x, double y, double z)
{
	modify->radian_x = x * (M_PI / 180);
	modify->radian_y = y * (M_PI / 180);
	modify->radian_z = z * (M_PI / 180);
}

void	set_move_val(t_modify *mod, int x_move, int y_move)
{
	mod->x_move = x_move;
	mod->y_move = y_move;
}
