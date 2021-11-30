/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:57:01 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 11:57:02 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*wp;
	void			*p;
	size_t			bytes;

	bytes = count * size;
	p = malloc(bytes);
	if (!p)
		return (NULL);
	wp = (unsigned char *) p;
	while (bytes--)
		*wp++ = 0;
	return (p);
}
