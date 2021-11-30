/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_jptab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:32:44 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 14:08:02 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_table(char table[256])
{
	table['X'] = NO_UPHEX;
	table['d'] = NO_DIG;
	table['i'] = NO_INT;
	table['u'] = NO_UINT;
	table['x'] = NO_LOWHEX;
	table['%'] = NO_PERC;
	table['p'] = NO_PTRADDR;
	table['c'] = NO_CHAR;
	table['s'] = NO_STR;
	table['1'] = NO_NUM;
	table['2'] = NO_NUM;
	table['3'] = NO_NUM;
	table['4'] = NO_NUM;
	table['5'] = NO_NUM;
	table['6'] = NO_NUM;
	table['7'] = NO_NUM;
	table['8'] = NO_NUM;
	table['9'] = NO_NUM;
	table['-'] = NO_MINUS;
	table['0'] = NO_ZERO;
	table['.'] = NO_DOT;
	table['#'] = NO_HASH;
	table[' '] = NO_SPACE;
	table['+'] = NO_PLUS;
}

void	fill_fptable(int (*fptable[PH])(t_qunit, va_list))
{
	fptable[0] = NULL;
	fptable[NO_UPHEX] = write_uphex;
	fptable[NO_DIG] = write_int;
	fptable[NO_INT] = write_int;
	fptable[NO_UINT] = write_uint;
	fptable[NO_LOWHEX] = write_lowhex;
	fptable[NO_PERC] = NULL;
	fptable[NO_PTRADDR] = write_ptraddr;
	fptable[NO_CHAR] = write_char;
	fptable[NO_STR] = write_str;
}

void	fill_re_options(t_argholder *re)
{
	int	i;

	re->type = -1;
	re->len = 1;
	i = 0;
	while (i < TOTOP)
		re->op[i++] = -1;
}
