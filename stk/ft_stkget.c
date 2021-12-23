/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:13:56 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 19:20:08 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_unit	*ft_stkget(t_stack *stack, size_t n)
{
	t_stack_unit	*curr;

	if (!stack || !stack->top)
		return (NULL);
	curr = stack->top;
	while (curr && n-- > 0)
		curr = curr->next;
	return (curr);
}
