/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_mem_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:30:39 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/27 18:23:44 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fillitoa(unsigned long n, char *bff, char *b, size_t len);

char	*ft_ultoa_membase(char *dst, unsigned long n, char *base)
{
	size_t	len;

	len = ft_fillitoa(n, dst, base, 0);
	return (dst + len);
}

static size_t	ft_fillitoa(unsigned long n, char *bff, char *b, size_t len)
{
	unsigned long	i;
	unsigned int	base;

	i = n;
	base = ft_strlen(b);
	if (i < base)
		bff[len++] = b[i];
	else
	{
		len = ft_fillitoa(i / base, bff, b, len);
		bff[len++] = b[i % base];
	}
	return (len);
}
