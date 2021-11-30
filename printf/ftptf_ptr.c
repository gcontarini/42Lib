/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:33:22 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/27 19:10:26 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_ptraddr(t_qunit qunit, va_list ap)
{
	size_t			len;
	char			*str;
	unsigned long	p;

	p = va_arg(ap, unsigned long);
	if (qunit.op[NO_NUM - NO_NUM] > 0)
		str = buff_ptr_width(qunit, p);
	else if (qunit.op[NO_MINUS - NO_NUM] > 0)
		str = buff_ptr_minus(qunit, p);
	else
		str = buff_ptr(p);
	if (!str)
		return (memerror_int());
	len = ft_strlen(str);
	write(STDOUT_FD, str, len);
	free(str);
	return (len);
}

char	*buff_ptr_width(t_qunit qu, unsigned long ptr)
{
	char		base[16 + 1];
	char		*p;
	t_flagop	opt;

	ft_strlcpy(base, "0123456789abcdef", 17);
	opt.len = ft_ulonglen_base(ptr, 16) + 2;
	opt.width = qu.op[NO_NUM - NO_NUM] - opt.len;
	if (opt.width < 0)
		opt.width = 0;
	p = (char *) malloc(opt.len + opt.width + 1);
	if (!p)
		return (NULL);
	p = (char *) ft_memset(p, ' ', opt.width) + opt.width;
	ft_strlcpy(p, "0x", 3);
	p += 2;
	p = ft_ultoa_membase(p, ptr, base);
	*p = 0;
	return (p - opt.len - opt.width);
}

char	*buff_ptr_minus(t_qunit qu, unsigned long ptr)
{
	char		base[16 + 1];
	char		*p;
	t_flagop	opt;

	ft_strlcpy(base, "0123456789abcdef", 17);
	opt.len = ft_ulonglen_base(ptr, 16) + 2;
	opt.minus = qu.op[NO_MINUS - NO_NUM] - opt.len;
	if (opt.minus < 0)
		opt.minus = 0;
	p = (char *) malloc(opt.len + opt.minus + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, "0x", 3);
	p += 2;
	p = ft_ultoa_membase(p, ptr, base);
	p = (char *) ft_memset(p, ' ', opt.minus) + opt.minus;
	*p = 0;
	return (p - opt.len - opt.minus);
}

char	*buff_ptr(unsigned long ptr)
{
	char		base[16 + 1];
	char		*p;
	t_flagop	opt;

	ft_strlcpy(base, "0123456789abcdef", 17);
	opt.len = ft_ulonglen_base(ptr, 16) + 2;
	p = (char *) malloc(opt.len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, "0x", 3);
	p += 2;
	p = ft_ultoa_membase(p, ptr, base);
	*p = 0;
	return (p - opt.len);
}
