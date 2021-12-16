/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_istack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:18:07 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:19:00 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_rot_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*base;

	if (!stack || !stack->top || !stack->base || !stack->top->last)
		return ;
	top = stack->top;
	stack->top = stack->top->last;
	base = stack->base;
	top->last = NULL;
	base->last = top;
	stack->base = top;
	return ;
}
