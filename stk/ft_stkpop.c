/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:52:14 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 19:21:51 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_unit	ft_stkpop(t_stack *stack)
{
	t_stack_unit	*tmp;
	t_stack_unit	pop;

	pop.content = NULL;
	pop.next = NULL;
	if (!stack || !stack->top)
		return (pop);
	pop = *(stack->top);
	tmp = stack->top;
	stack->top = stack->top->next;
	if (!stack->top)
		stack->base = NULL;
	free(tmp);
	return (pop);
}
