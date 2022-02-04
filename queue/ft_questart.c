/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_questart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:26:29 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:26:30 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_queue2	*ft_questart(void)
{
	t_queue2	*queue;

	queue = (t_queue2 *) malloc(sizeof(t_queue2));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}
