/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:33:13 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 14:08:44 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_percent(t_qunit qunit)
{
	int		len;
	char	*p;

	if (qunit.op[NO_NUM - NO_NUM] > 0)
		p = buff_perc_width(qunit);
	else if (qunit.op[NO_MINUS - NO_NUM] > 0)
		p = buff_perc_minus(qunit);
	else if (qunit.op[NO_ZERO - NO_NUM] > 0)
		p = buff_perc_zero(qunit);
	else
	{
		write(STDOUT_FD, "%", 1);
		return (1);
	}
	if (!p)
		return (memerror_int());
	len = ft_strlen(p);
	write(STDOUT_FD, p, len);
	free(p);
	return (len);
}

char	*buff_perc_width(t_qunit qu)
{
	char		*p;
	t_flagop	opt;

	opt.width = qu.op[NO_NUM - NO_NUM] - 1;
	p = (char *) malloc(opt.width + 2);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, ' ', opt.width) + opt.width;
	*p++ = '%';
	*p = 0;
	return (p - opt.width - 1);
}

char	*buff_perc_minus(t_qunit qu)
{
	char		*p;
	t_flagop	opt;

	opt.minus = qu.op[NO_MINUS - NO_NUM] - 1;
	p = (char *) malloc(opt.minus + 2);
	if (!p)
		return (NULL);
	*p++ = '%';
	p = (char *) ft_memset(p, ' ', opt.minus) + opt.minus;
	*p = 0;
	return (p - opt.minus - 1);
}

char	*buff_perc_zero(t_qunit qu)
{
	char		*p;
	t_flagop	opt;

	opt.zero = qu.op[NO_ZERO - NO_NUM] - 1;
	p = (char *) malloc(opt.zero + 2);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, ' ', opt.zero) + opt.zero;
	*p++ = '%';
	*p = 0;
	return (p - opt.zero - 1);
}
