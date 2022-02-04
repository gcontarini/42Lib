/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:25:07 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:25:09 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_queue2	*ft_enque(t_queue2 *queue, void *p)
{
	t_queue_unit	*tmp;

	if (!queue)
		return (NULL);
	tmp = (t_queue_unit *) malloc(sizeof(t_queue_unit));
	if (!tmp)
		return (NULL);
	tmp->content = p;
	tmp->last = NULL;
	if (queue->rear)
	{
		tmp->next = queue->rear;
		queue->rear->last = tmp;
		queue->rear = tmp;
		return (queue);
	}
	tmp->next = NULL;
	queue->rear = tmp;
	queue->front = tmp;
	return (queue);
}
