/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:11:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/05 06:03:05 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_num(char a)
{
	if (!a)
		return (0);
	if (a <= '9' && a >= '0')
		return (1);
	return (0);
}

int	width_cnt(char *arr)
{
	int	cnt;

	cnt = 0;
	while (*arr && *arr != '\n')
	{
		if (is_num(*arr) || *arr == '-')
		{
			cnt++;
			while (is_num(*arr) || *arr == '-')
				arr++;
		}
		else
		{
			while (*arr && *arr != '-' && !is_num(*arr))
				arr++;
		}
	}
	return (cnt);
}

int	height_cnt(char *arr)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < ft_strlen(arr))
	{
		if (arr[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

int	make_num(char **arr)
{
	int	n;
	int	minus;

	n = 0;
	minus = 1;
	while (**arr && **arr != '-' && !is_num(**arr))
		*arr = *arr + 1;
	if (**arr == '-')
	{
		minus = -1;
		*arr = *arr + 1;
	}
	if (is_num(**arr))
	{
		while (is_num(**arr))
		{
			n = n * 10 + (**arr - '0');
			*arr = *arr + 1;
		}
	}
	return (n * minus);
}
