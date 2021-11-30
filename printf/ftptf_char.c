/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:32:18 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 17:46:48 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(t_qunit qunit, va_list ap)
{
	char			*p;
	unsigned char	c;
	int				len;

	c = (unsigned char) va_arg(ap, int);
	if (qunit.op[NO_NUM - NO_NUM] > 0)
		p = buff_char_width(qunit, c);
	else if (qunit.op[NO_MINUS - NO_NUM] > 0)
		p = buff_char_minus(qunit, c);
	else
	{
		write(STDOUT_FD, &c, 1);
		return (1);
	}
	if (!p)
		return (memerror_int());
	len = qunit.op[NO_MINUS - NO_NUM];
	if (qunit.op[NO_NUM - NO_NUM] > 0)
		len = qunit.op[NO_NUM - NO_NUM];
	write(STDOUT_FD, p, len);
	free(p);
	return (len);
}

char	*buff_char_width(t_qunit qu, unsigned char c)
{
	char		*p;
	t_flagop	opt;

	opt.width = qu.op[NO_NUM - NO_NUM] - 1;
	p = (char *) malloc(opt.width + 2);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, ' ', opt.width) + opt.width;
	*p++ = c;
	*p = 0;
	return (p - opt.width - 1);
}

char	*buff_char_minus(t_qunit qu, unsigned char c)
{
	char		*p;
	t_flagop	opt;

	opt.minus = qu.op[NO_MINUS - NO_NUM] - 1;
	p = (char *) malloc(opt.minus + 2);
	if (!p)
		return (NULL);
	*p++ = c;
	p = (char *) ft_memset(p, ' ', opt.minus) + opt.minus;
	*p = 0;
	return (p - opt.minus - 1);
}
