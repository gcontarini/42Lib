/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:33:30 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 14:09:17 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_queue	*start_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *) malloc(sizeof(t_queue *));
	if (!queue)
		return (memerror_queue(0));
	queue->tail = (t_qunit *) malloc(sizeof(t_qunit));
	if (!queue->tail)
		return (memerror_queue(queue));
	queue->tail->len = 0;
	queue->tail->type = 0;
	queue->tail->last = NULL;
	queue->head = queue->tail;
	return (queue);
}

t_queue	*add_queue(t_queue *queue, t_argholder args)
{
	int		i;
	t_qunit	*tmp;

	tmp = (t_qunit *) malloc(sizeof(t_qunit));
	if (!tmp)
		return (memerror_queue(queue));
	tmp->len = args.len;
	tmp->type = args.type;
	tmp->last = NULL;
	i = 0;
	while (++i < TOTOP + 1)
		tmp->op[i - 1] = args.op[i - 1];
	queue->tail->last = tmp;
	queue->tail = tmp;
	return (queue);
}

t_qunit	pool_queue(t_queue *queue)
{
	t_qunit	*tmp;
	t_qunit	qunit;

	tmp = queue->head;
	if (tmp)
	{
		qunit = *(queue->head);
		queue->head = queue->head->last;
		free(tmp);
	}
	else
		qunit.len = -1;
	return (qunit);
}

void	clean_queue(t_queue *queue)
{
	t_qunit	*tmp;

	if (queue)
	{
		tmp = queue->head;
		while (tmp)
		{
			queue->head = queue->head->last;
			free(tmp);
			tmp = queue->head;
		}
		free(queue);
	}
}
