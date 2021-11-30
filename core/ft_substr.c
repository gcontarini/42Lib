/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:04:32 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/21 16:28:32 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	max_i;
	size_t	i;

	if (!s)
		return (NULL);
	max_i = ft_strlen((char *) s);
	if (max_i < len)
		p = (char *) malloc((max_i + 1) * sizeof(char));
	else
		p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	if (start < max_i)
		while (i < len && *(s + start))
			p[i++] = *(s++ + start);
	p[i] = 0;
	return (p);
}
