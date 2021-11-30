/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:01:44 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 12:01:45 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_seterrno(void);

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen((char *) s1);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (ft_seterrno());
	while (*s1)
		*p++ = *s1++;
	*p = 0;
	return (p - len);
}

static void	*ft_seterrno(void)
{
	errno = ENOMEM;
	return (NULL);
}
