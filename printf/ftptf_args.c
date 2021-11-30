/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:32:07 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/26 10:20:35 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_args(t_queue *queue)
{
	t_qunit	*curr;

	curr = queue->head;
	while (curr)
	{
		if (curr->type < 0)
		{
			clean_queue(queue);
			return (0);
		}
		curr = curr->last;
	}
	return (1);
}

t_queue	*parse_args(const char *str, char table[256])
{
	t_queue	*queue;

	queue = start_queue();
	if (!queue)
		return (memerror_queue(0));
	str = ft_strchr(str, '%');
	while (str && *str)
	{
		queue = add_queue(queue, flag_type(str, table));
		if (!queue)
			return (memerror_queue(0));
		if (queue->tail->type == NO_PERC)
			str += queue->tail->len - 1;
		str = ft_strchr(++str, '%');
	}
	pool_queue(queue);
	return (queue);
}

t_argholder	flag_type(const char *str, char table[256])
{
	t_argholder			re;
	unsigned char		uc;

	fill_re_options(&re);
	while (str[re.len])
	{
		re.type = 0;
		uc = (unsigned char) str[re.len++];
		if (table[uc] == 0)
			re.type = INVLD_PHLR;
		else if (table[uc] < NO_NUM)
			re.type = table[uc];
		else if (table[uc] < NO_HASH)
			re.op[table[uc] - NO_NUM] = parse_optn(str, &re);
		else
			re.op[table[uc] - NO_NUM] = parse_opt(str, &re);
		if (re.type != 0)
			break ;
	}
	return (re);
}

int	parse_optn(const char *str, t_argholder *re)
{
	int	i;
	int	width_flag;

	width_flag = 0;
	if (str[re->len - 1] > '0' && str[re->len - 1] <= '9')
		width_flag = -1;
	i = ft_atoi(str + re->len + width_flag);
	while (str[re->len] >= '0' && str[re->len] <= '9')
		re->len++;
	return (i);
}

int	parse_opt(const char *str, t_argholder *re)
{
	while (str[re->len - 1] >= '0' && str[re->len - 1] <= '9')
		re->len++;
	return (1);
}
