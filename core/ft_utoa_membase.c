/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_mem_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:31:19 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/27 18:24:31 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fillitoa(unsigned int n, char *bff, char *b, size_t len);

char	*ft_utoa_membase(char *dst, unsigned int n, char *base)
{
	size_t	len;

	len = ft_fillitoa(n, dst, base, 0);
	return (dst + len);
}

static size_t	ft_fillitoa(unsigned int n, char *bff, char *b, size_t len)
{
	unsigned int	i;
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
