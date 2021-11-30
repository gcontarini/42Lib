/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:37 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/06 14:10:31 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*cpybuff_nl(char *buff);
static char		*strcat_nl(char *dst, char *src);
static void		upbuff_nl(char *buff);
static size_t	strlen_nl(char *str);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	long		rc;
	char		*p;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	p = cpybuff_nl(buff);
	if (check_strchr(p, '\n'))
		return (p);
	rc = read(fd, buff, BUFFER_SIZE);
	while (rc > 0)
	{
		buff[rc] = 0;
		p = strcat_nl(p, buff);
		if (!p || check_strchr(buff, '\n'))
			break ;
		rc = read(fd, buff, BUFFER_SIZE);
	}
	if (p)
		upbuff_nl(buff);
	return (p);
}

static char	*cpybuff_nl(char *buff)
{
	size_t	len;
	char	*p;

	len = strlen_nl(buff);
	if (len == 0)
		return (NULL);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*buff && *buff != '\n')
		*p++ = *buff++;
	if (*buff == '\n')
		*p++ = *buff++;
	*p = 0;
	upbuff_nl(buff - len);
	return (p - len);
}

static char	*strcat_nl(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	char	*p;

	len = ft_strlen(s1) + strlen_nl(s2);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		*p++ = s1[i++];
	while (*s2 && *s2 != '\n')
		*p++ = *s2++;
	if (*s2 == '\n')
		*p++ = '\n';
	*p = 0;
	if (s1)
		free(s1);
	return (p - len);
}

static void	upbuff_nl(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
	{
		*buff = buff[i];
		buff++;
	}
	*buff = 0;
}

static size_t	strlen_nl(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len++;
	return (len);
}
