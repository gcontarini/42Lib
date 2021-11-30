/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:34:42 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/30 17:09:08 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX_FD 1024
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);
size_t	check_strchr(char *p, char c);

#endif
