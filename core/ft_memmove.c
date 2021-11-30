/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:59:41 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 10:54:54 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dst + len - 1;
	s = (unsigned char *) src + len - 1;
	if ((intptr_t) src <= (intptr_t) dst
		&& (intptr_t) s < (intptr_t) d)
	{
		while (len--)
			*d-- = *s--;
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
