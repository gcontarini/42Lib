/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrot_istack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:19:12 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/17 15:17:23 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_rrot_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*curr;

	if (!stack || !stack->top || !stack->base || !stack->top->last)
		return ;
	top = stack->top;
	curr = top;
	while (curr->last->last)
		curr = curr->last;
	curr->last = NULL;
	stack->top = stack->base;
	stack->base->last = top;
	stack->base = curr;
	return ;
}
