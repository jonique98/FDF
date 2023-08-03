/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:11:44 by josumin           #+#    #+#             */
/*   Updated: 2023/08/04 00:19:36 by josumin          ###   ########.fr       */
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
	while (*arr != 0 && *arr != '\n')
	{
		if (is_num(*arr))
		{
			cnt++;
			while (is_num(*arr))
				arr++;
		}
		else
		{
			while (*arr && !is_num(*arr))
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

	n = 0;
	while (**arr && !is_num(**arr))
		*arr = *arr + 1;
	if (is_num(**arr))
	{
		while (is_num(**arr))
		{
			n = n * 10 + (**arr - '0');
			*arr = *arr + 1;
		}
	}
	return (n);
}
