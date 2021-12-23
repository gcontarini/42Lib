/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkswapn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:58:40 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:05:35 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkswapn(t_stack *stack, size_t n)
{
	size_t			len;
	t_stack_unit	*top;
	t_stack_unit	*curr;
	t_stack_unit	*l1;

	len = ft_stklen(stack);
	if (len < 2 || n >= len)
		return (0);
	if (n == 0)
		return (ft_stkswap(stack));
	top = ft_stkget(stack, n - 1);
	curr = top->next;
	if (top->next && top->next->next)
		top->next = top->next->next;
	l1 = curr->next;
	if (l1)
	{
		curr->next = l1->next;
		l1->next = curr;
	}
	if (!curr->next)
		stack->base = curr;
	return (1);
}
