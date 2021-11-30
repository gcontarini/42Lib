/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:04:48 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:04:49 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_set(char c, char const *set);
static size_t	ft_trimlen(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	char		*p;
	size_t		len;

	if (!s1)
		return (NULL);
	while (ft_is_set(*s1, set))
		s1++;
	len = ft_trimlen(s1, set);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	end = s1 + len;
	while (s1 != end)
		*p++ = *s1++;
	*p = 0;
	return (p - len);
}

static size_t	ft_trimlen(char const *s1, char const *set)
{
	const char	*p;
	size_t		i;

	i = 0;
	while (s1[i])
	{
		p = s1 + i;
		while (ft_is_set(*p, set))
			p++;
		if (*p == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_is_set(char c, char const *set)
{
	while (set && *set)
		if (*set++ == c)
			return (1);
	return (0);
}
