/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:30:05 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 18:55:52 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				plen;

	plen = 0;
	va_start(ap, str);
	plen = ft_vprintf(str, ap);
	va_end(ap);
	return (plen);
}

int	ft_vprintf(const char *str, va_list ap)
{
	static char	table[256];
	static int	(*ptable[PH])(t_qunit, va_list);
	int			plen;
	t_queue		*queue;

	errno = 0;
	fill_table(table);
	fill_fptable(ptable);
	queue = parse_args(str, table);
	if (!queue)
		return (-1);
	if (check_args(queue) == 0)
		return (-1);
	plen = 0;
	while (*str && errno == 0)
	{
		plen += flush_str(&str);
		plen += flush_var(&str, queue, ap, ptable);
	}
	clean_queue(queue);
	if (errno == 0)
		return (plen);
	return (errno);
}
