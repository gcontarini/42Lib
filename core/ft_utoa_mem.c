/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:30:59 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/27 18:23:59 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fillitoa(unsigned int n, char *bff, size_t len);

char	*ft_utoa_mem(char *dst, unsigned int n)
{
	size_t	len;

	len = ft_fillitoa(n, dst, 0);
	return (dst + len);
}

static size_t	ft_fillitoa(unsigned int n, char *bff, size_t len)
{
	unsigned int	i;

	i = n;
	if (i < 10)
		bff[len++] = i + 48;
	else
	{
		len = ft_fillitoa(i / 10, bff, len);
		bff[len++] = i % 10 + 48;
	}
	return (len);
}
