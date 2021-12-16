/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_istack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:17:35 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:37:08 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_swap_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*l1;

	if (!stack || !stack->top)
		return ;
	top = stack->top;
	if (!top->last)
		return ;
	l1 = top->last;
	top->last = l1->last;
	l1->last = top;
	stack->top = l1;
	if (!top->last)
		stack->base = top;
	return ;
}
