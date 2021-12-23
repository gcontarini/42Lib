/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:34:35 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 17:43:08 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_stkpush(t_stack *stack, void *p)
{
	t_stack_unit	*tmp;

	if (!stack)
		return (NULL);
	tmp = (t_stack_unit *) malloc(sizeof(t_stack_unit));
	if (!tmp)
		return (NULL);
	tmp->content = p;
	if (stack->top)
	{
		tmp->next = stack->top;
		stack->top = tmp;
		return (stack);
	}
	tmp->next = NULL;
	stack->top = tmp;
	if (!stack->base)
		stack->base = tmp;
	return (stack);
}
