/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:00:37 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:00:38 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fillitoa(int n, char *bff, size_t len);

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	buff[MAX_INT_LENGTH];

	len = ft_fillitoa(n, buff, 0);
	write(fd, buff, len);
}

static size_t	ft_fillitoa(int n, char *bff, size_t len)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		i = -n;
		bff[len++] = '-';
	}
	if (i < 10)
		bff[len++] = i + 48;
	else
	{
		len = ft_fillitoa(i / 10, bff, len);
		bff[len++] = i % 10 + 48;
	}
	return (len);
}
