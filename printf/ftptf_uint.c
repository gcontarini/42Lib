/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:33:50 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/27 19:38:31 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_uint(t_qunit qu, va_list ap)
{
	char				*p;
	unsigned int		nbr;
	int					len;

	nbr = va_arg(ap, unsigned int);
	if (qu.op[NO_NUM - NO_NUM] > 0)
		p = buff_uint_width(qu, nbr);
	else if (qu.op[NO_MINUS - NO_NUM] > 0)
		p = buff_uint_minus(qu, nbr);
	else if (qu.op[NO_ZERO - NO_NUM] > 0)
	{
		qu.op[NO_NUM - NO_NUM] = qu.op[NO_ZERO - NO_NUM];
		if (qu.op[NO_DOT - NO_NUM] < 0)
			p = buff_uint_zero(qu, nbr);
		else
			p = buff_uint_width(qu, nbr);
	}
	else
		p = buff_uint_dot(qu, nbr);
	if (!p)
		return (memerror_int());
	len = ft_strlen(p);
	write(STDOUT_FD, p, len);
	free(p);
	return (len);
}

char	*buff_uint_width(t_qunit qu, unsigned int n)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_uintlen(n);
	opt.dot = qu.op[NO_DOT - NO_NUM] - opt.len;
	if (opt.dot < 0)
		opt.dot = 0;
	opt.width = qu.op[NO_NUM - NO_NUM] - opt.dot - opt.len;
	if (opt.width < 0)
		opt.width = 0;
	p = (char *) malloc(opt.len + opt.dot + opt.width + 1);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, ' ', opt.width) + opt.width;
	p = (char *) ft_memset(p, '0', opt.dot) + opt.dot;
	p = ft_utoa_mem(p, n);
	*p = 0;
	return (p - opt.len - opt.width - opt.dot);
}

char	*buff_uint_minus(t_qunit qu, unsigned int n)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_uintlen(n);
	opt.dot = qu.op[NO_DOT - NO_NUM] - opt.len;
	if (opt.dot < 0)
		opt.dot = 0;
	opt.minus = qu.op[NO_MINUS - NO_NUM] - opt.len - opt.dot;
	if (opt.minus < 0)
		opt.minus = 0;
	p = (char *) malloc(opt.len + opt.minus + opt.dot + 1);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, '0', opt.dot) + opt.dot;
	p = ft_utoa_mem(p, n);
	p = (char *) ft_memset(p, ' ', opt.minus) + opt.minus;
	*p = 0;
	return (p - opt.dot - opt.minus - opt.len);
}

char	*buff_uint_zero(t_qunit qu, unsigned int n)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_uintlen(n);
	opt.zero = qu.op[NO_ZERO - NO_NUM] - opt.len;
	if (opt.zero < 0)
		opt.zero = 0;
	p = (char *) malloc(opt.len + opt.zero + 1);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, '0', opt.zero) + opt.zero;
	p = ft_utoa_mem(p, n);
	*p = 0;
	return (p - opt.len - opt.zero);
}

char	*buff_uint_dot(t_qunit qu, unsigned int n)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_uintlen(n);
	opt.dot = qu.op[NO_DOT - NO_NUM] - opt.len;
	if (opt.dot < 0)
	opt.dot = 0;
	p = (char *) malloc(opt.len + opt.dot + 1);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, '0', opt.dot) + opt.dot;
	p = ft_utoa_mem(p, n);
	*p = 0;
	return (p - opt.len - opt.dot);
}
