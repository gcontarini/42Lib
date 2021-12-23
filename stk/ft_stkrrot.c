/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkrrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:31:35 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:35:33 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkrrot(t_stack *stack)
{
	t_stack_unit	*top;
	t_stack_unit	*curr;

	if (!stack || !stack->top || !stack->base || !stack->top->next)
		return (0);
	top = stack->top;
	curr = top;
	while (curr->next->next)
		curr = curr->next;
	curr->next = NULL;
	stack->top = stack->base;
	stack->base->next = top;
	stack->base = curr;
	return (1);
}
