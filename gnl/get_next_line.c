/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:37 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 17:04:30 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*gnl_strjoin_char(char *dst, const char *src, char c);
static char		*gnl_newline(char *buff, char c);
static void		gnl_upbuff_char(char *buff, char c);
static size_t	gnl_strlen_char(const char *str, char c);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		rc;
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	line = gnl_newline(buff, '\n');
	if (ft_strchr(line, '\n'))
		return (line);
	rc = read(fd, buff, BUFFER_SIZE);
	while (rc > 0)
	{
		buff[rc] = 0;
		line = gnl_strjoin_char(line, buff, '\n');
		if (!line || ft_strchr(buff, '\n'))
			break ;
		rc = read(fd, buff, BUFFER_SIZE);
	}
	if (line)
		gnl_upbuff_char(buff, '\n');
	return (line);
}

static char	*gnl_newline(char *buff, char c)
{
	char	*line;

	line = 0;
	line = gnl_strjoin_char(line, buff, c);
	if (!line)
		return (NULL);
	gnl_upbuff_char(buff, '\n');
	return (line);
}

static char	*gnl_strjoin_char(char *dst, const char *src, char c)
{
	size_t	i;
	size_t	len;
	char	*p;

	len = ft_strlen(dst) + gnl_strlen_char(src, c);
	if (len == 0)
		return (NULL);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (dst && dst[i])
		*p++ = dst[i++];
	while (*src && *src != c)
		*p++ = *src++;
	if (*src == c)
		*p++ = c;
	*p = 0;
	if (dst)
		free(dst);
	return (p - len);
}

static void	gnl_upbuff_char(char *buff, char c)
{
	size_t	i;

	i = 0;
	while (buff[i] && buff[i] != c)
		i++;
	if (buff[i] == c)
		i++;
	while (buff[i])
	{
		*buff = buff[i];
		buff++;
	}
	*buff = 0;
}

static size_t	gnl_strlen_char(const char *str, char c)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (str[len] == c)
		len++;
	return (len);
}
