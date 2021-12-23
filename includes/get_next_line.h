/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:34:42 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 16:00:45 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);

#endif
