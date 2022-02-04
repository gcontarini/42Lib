/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quelen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:26:18 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:38:11 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

size_t	ft_quelen(t_queue2 *queue)
{
	t_queue_unit	*curr;
	size_t			len;

	len = 0;
	if (!queue)
		return (len);
	curr = queue->rear;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
