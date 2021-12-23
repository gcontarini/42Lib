/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:29:50 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:36:11 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkrot(t_stack *stack)
{
	t_stack_unit	*top;
	t_stack_unit	*base;

	if (!stack || !stack->top || !stack->base || !stack->top->next)
		return (0);
	top = stack->top;
	stack->top = stack->top->next;
	base = stack->base;
	top->next = NULL;
	base->next = top;
	stack->base = top;
	return (1);
}
