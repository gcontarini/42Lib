/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi_istack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:37:43 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 11:26:08 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_swapi_istack(t_istack *stack, size_t index)
{
	size_t		len;
	t_isunit	*top;
	t_isunit	*curr;
	t_isunit	*l1;

	len = ft_len_istack(stack);
	if (len < 2 || index >= len || index == 0)
		return ;
	top = ft_peek_istack(stack, index - 1);
	curr = top->last;
	if (top->last && top->last->last)
		top->last = top->last->last;
	l1 = curr->last;
	if (l1)
	{
		curr->last = l1->last;
		l1->last = curr;
	}
	if (!curr->last)
		stack->base = curr;
	return ;
}
