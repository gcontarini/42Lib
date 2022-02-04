/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:01:31 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/21 14:53:00 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	if (!p)
		return (NULL);
	while (*p)
	{
		if (*p == (char) c)
			return (p);
		p++;
	}
	if (c == 0 && *p == 0)
		return (p);
	return (NULL);
}
