/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:11:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/09 07:52:37 by sumjo            ###   ########.fr       */
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
			while (is_num(*arr) || *arr == '-' || *arr == ','
				|| *arr == 'x' || *arr == 'X' || (*arr >= 'a' && *arr <= 'f')
				|| (*arr >= 'A' && *arr <= 'F'))
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
	int	cnt;

	cnt = 0;
	while (*arr != 0)
	{
		if (*arr == '\n')
			cnt++;
		arr++;
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
	else
		exit(0);
	return (n * minus);
}

int	make_num_16(char **arr)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	if (!is_num(**arr) && !(**arr >= 'a' && **arr <= 'f') \
		&& **arr != 'F')
		exit(0);
	while (i < 2 && (is_num(**arr) || (**arr >= 'a' && **arr <= 'f') \
		|| **arr == 'F'))
	{
		if (is_num(**arr))
			num = num * 16 + (**arr - '0');
		else if (**arr >= 'a' && **arr <= 'f')
			num = num * 16 + (**arr - 'a' + 10);
		else if (**arr == 'F')
			num = num * 16 + 5;
		else
			exit(0);
		(*arr)++;
		i++;
	}
	return (num);
}
