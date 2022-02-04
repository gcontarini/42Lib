/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:26:08 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:26:10 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_queue_unit	*ft_queget(t_queue2 *queue, size_t n)
{
	t_queue_unit	*curr;

	if (!queue || !queue->front)
		return (NULL);
	curr = queue->front;
	while (curr && n-- > 0)
		curr = curr->last;
	return (curr);
}
