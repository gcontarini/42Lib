/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:17 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:02:18 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	re_size;
	size_t	len;

	re_size = dstsize;
	len = 0;
	while (re_size > 0 && dst[len])
	{
		len++;
		re_size--;
	}
	if (re_size > 0)
	{
		while (*src && re_size-- > 1)
			dst[len++] = *src++;
		dst[len] = 0;
		while (*src && src++)
			len++;
		return (len);
	}
	return (ft_strlen((char *) src) + dstsize);
}
