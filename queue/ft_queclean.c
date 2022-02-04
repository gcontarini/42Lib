/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:24:44 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:24:46 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queclean(t_queue2 *queue, void (*del)(void *))
{
	if (!queue)
		return ;
	ft_dlstclear(&(queue->rear), del);
	free(queue);
	return ;
}
