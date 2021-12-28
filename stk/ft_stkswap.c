/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:56:53 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:08:06 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkswap(t_stack *stack)
{
	t_stack_unit	*top;
	t_stack_unit	*l1;

	if (!stack || !stack->top)
		return (0);
	top = stack->top;
	if (!top->next)
		return (0);
	l1 = top->next;
	top->next = l1->next;
	l1->next = top;
	stack->top = l1;
	if (!top->next)
		stack->base = top;
	return (1);
}
