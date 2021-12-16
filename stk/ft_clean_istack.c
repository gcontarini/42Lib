/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_istack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:15:19 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:15:49 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_clean_istack(t_istack *stack)
{
	t_isunit	*curr;

	if (!stack)
		return ;
	curr = stack->top;
	while (curr)
	{
		stack->top = stack->top->last;
		free(curr);
		curr = stack->top;
	}
	free(stack);
	return ;
}
