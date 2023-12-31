/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:13:12 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/09 14:00:39 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd, int *error);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*free_arr(char **original, int *error);
int			is_line(char *arr);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif
#endif
