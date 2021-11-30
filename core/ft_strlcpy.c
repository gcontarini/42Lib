/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:27 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:02:33 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;

	s = src;
	while (*s && dstsize > 1)
	{
		*dst++ = *s++;
		dstsize--;
	}
	if (dstsize)
		*dst = 0;
	while (*s)
		s++;
	return (s - src);
}
