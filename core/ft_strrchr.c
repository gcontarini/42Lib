/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:04:02 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/21 14:55:04 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == (char) c)
			p = (char *) s;
		s++;
	}
	if (c == 0 && *s == 0)
		p = (char *) s;
	return (p);
}
