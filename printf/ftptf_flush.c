/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:32:25 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 14:07:36 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flush_str(const char **str)
{
	int	len;

	len = 0;
	while ((*str)[len] != '%' && (*str)[len] != 0)
		len++;
	write(STDOUT_FD, *str, len);
	*str = *str + len;
	return (len);
}

int	flush_var(const char **s, t_queue *q, va_list ap, int (**ptable)())
{
	int			len;
	t_qunit		qunit;

	if (!**s)
		return (0);
	len = 0;
	if (q->head && errno == 0)
	{
		qunit = pool_queue(q);
		if (qunit.type == NO_PERC)
			len = write_percent(qunit);
		else
			len = ptable[qunit.type](qunit, ap);
		*s = *s + qunit.len;
	}
	return (len);
}

char	*take_op_sign(char *p, t_qunit qu, int n)
{
	if (n < 0)
		*p++ = '-';
	else if (qu.op[NO_PLUS - NO_NUM] > 0)
		*p++ = '+';
	else if (qu.op[NO_SPACE - NO_NUM] > 0)
		*p++ = ' ';
	return (p);
}
