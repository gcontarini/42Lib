/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_istack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:12:55 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:34:04 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_istack	*ft_push_istack(t_istack *stack, int i)
{
	t_isunit	*tmp;

	if (!stack)
		return (NULL);
	tmp = (t_isunit *) malloc(sizeof(t_isunit));
	if (!tmp)
		return (NULL);
	tmp->i = i;
	if (stack->top)
	{
		tmp->last = stack->top;
		stack->top = tmp;
		return (stack);
	}
	tmp->last = NULL;
	stack->top = tmp;
	stack->base = tmp;
	return (stack);
}
