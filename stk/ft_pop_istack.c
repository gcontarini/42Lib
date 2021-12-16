/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_istack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:16:35 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:17:27 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_isunit	ft_pop_istack(t_istack *stack)
{
	t_isunit	*tmp;
	t_isunit	pop;

	pop.last = NULL;
	if (!stack || !stack->top)
		return (pop);
	pop = *(stack->top);
	tmp = stack->top;
	stack->top = stack->top->last;
	if (tmp)
		free(tmp);
	return (pop);
}
