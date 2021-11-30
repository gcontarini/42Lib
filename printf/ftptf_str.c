/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:33:39 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/26 10:20:58 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_str(t_qunit qunit, va_list ap)
{
	char	*p;
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	if (qunit.op[NO_NUM - NO_NUM] > 0)
		p = buff_str_width(qunit, str);
	else if (qunit.op[NO_MINUS - NO_NUM] > 0)
		p = buff_str_minus(qunit, str);
	else
		p = buff_str_dot(qunit, str);
	if (!p)
		return (memerror_int());
	len = ft_strlen(p);
	write(STDOUT_FD, p, len);
	free(p);
	return (len);
}

char	*buff_str_width(t_qunit qu, char *str)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_strlen(str);
	opt.dot = qu.op[NO_DOT - NO_NUM];
	if (!str)
		opt.len = 6;
	if (opt.dot > -1 && opt.dot < opt.len)
		opt.len = opt.dot;
	opt.width = qu.op[NO_NUM - NO_NUM] - opt.len;
	if (opt.width < 0)
		opt.width = 0;
	p = (char *) malloc(opt.len + opt.width + 1);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, ' ', opt.width) + opt.width;
	if (str)
		ft_strlcpy(p, str, opt.len + 1);
	else
		ft_strlcpy(p, "(null)", opt.len + 1);
	return (p - opt.width);
}

char	*buff_str_minus(t_qunit qu, char *str)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_strlen(str);
	if (!str)
		opt.len = 6;
	opt.dot = qu.op[NO_DOT - NO_NUM];
	if (opt.dot > -1 && opt.dot < opt.len)
		opt.len = opt.dot;
	opt.minus = qu.op[NO_MINUS - NO_NUM] - opt.len;
	if (opt.minus < 0)
		opt.minus = 0;
	p = (char *) malloc(opt.len + opt.minus + 1);
	if (!p)
		return (NULL);
	if (str)
		ft_strlcpy(p, str, opt.len + 1);
	else
		ft_strlcpy(p, "(null)", opt.len + 1);
	p += opt.len;
	p = (char *) ft_memset(p, ' ', opt.minus) + opt.minus;
	*p = 0;
	return (p - opt.len - opt.minus);
}

char	*buff_str_dot(t_qunit qu, char *str)
{
	char		*p;
	t_flagop	opt;

	opt.len = ft_strlen(str);
	if (!str)
		opt.len = 6;
	opt.dot = qu.op[NO_DOT - NO_NUM];
	if (opt.dot > -1 && opt.dot < opt.len)
		opt.len = opt.dot;
	p = (char *) malloc(opt.len + 1);
	if (!p)
		return (NULL);
	if (str)
		ft_strlcpy(p, str, opt.len + 1);
	else
		ft_strlcpy(p, "(null)", opt.len + 1);
	return (p);
}
