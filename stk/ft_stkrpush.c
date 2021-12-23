/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkrpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:38:45 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 17:42:36 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_stkrpush(t_stack *stack, void *p)
{
	t_stack_unit	*tmp;

	if (!stack)
		return (NULL);
	tmp = (t_stack_unit *) malloc(sizeof(t_stack_unit));
	if (!tmp)
		return (NULL);
	tmp->content = p;
	tmp->next = NULL;
	if (stack->base)
	{
		stack->base->next = tmp;
		stack->base = tmp;
		return (stack);
	}
	stack->base = tmp;
	if (!stack->top)
		stack->top = tmp;
	return (stack);
}
