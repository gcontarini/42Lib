/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:24:57 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:24:59 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_printf.h"

t_queue_unit	ft_deque(t_queue2 *queue)
{
	t_queue_unit	*tmp;
	t_queue_unit	deque;

	deque.content = NULL;
	deque.next = NULL;
	deque.last = NULL;
	if (!queue || !queue->front)
		return (deque);
	deque = *(queue->front);
	tmp = queue->front;
	if (queue->front->last)
	{
		queue->front = queue->front->last;
		queue->front->next = NULL;
	}
	else
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	free(tmp);
	return (deque);
}
