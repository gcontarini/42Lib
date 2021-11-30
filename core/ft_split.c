/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:01:12 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:01:13 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strsdup(char const *s, char c);
static int		ft_check_alloc(char **dp, size_t wc);
static size_t	ft_count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**dp;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, c);
	dp = (char **) malloc((wc + 1) * sizeof(char *));
	if (!dp)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != 0)
			*dp++ = ft_strsdup(s, c);
		while (*s != c && *s)
			s++;
	}
	*dp = NULL;
	if (ft_check_alloc(dp, wc))
		return (dp - wc);
	free(dp - wc);
	return (NULL);
}

static char	*ft_strsdup(char const *s, char c)
{
	size_t	len;
	char	*p;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s != c && *s)
		*p++ = *s++;
	*p = 0;
	return (p - len);
}

static int	ft_check_alloc(char **dp, size_t wc)
{
	unsigned int	i;

	i = 0;
	while (i < wc)
	{
		if (*(dp - wc + i) == NULL)
			break ;
		i++;
	}
	if (i == wc)
		return (1);
	free(*dp);
	while (wc > 0)
		free(*(dp - wc--));
	return (0);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s && *s)
	{
		while (*s == c && *s)
			s++;
		if (*s != 0)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}
