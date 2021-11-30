/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:58:30 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 11:58:31 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numbersize(int n);
static char		*ft_putnbrstr(int n, char *s);

char	*ft_itoa(int n)
{
	size_t		size;
	char		*s;

	size = ft_numbersize(n);
	s = (char *) malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_putnbrstr(n, s);
	*(s + size) = 0;
	return (s);
}

static size_t	ft_numbersize(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_putnbrstr(int n, char *s)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		*s++ = '-';
		i = -n;
	}
	if (i < 10)
		*s = i + 48;
	else
	{
		s = ft_putnbrstr(i / 10, s);
		*s = i % 10 + 48;
	}
	return (s + 1);
}
