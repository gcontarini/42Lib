/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:02:09 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:02:09 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1 && *s1)
		*p++ = *s1++;
	while (s2 && *s2)
		*p++ = *s2++;
	*p = 0;
	return (p - len);
}
