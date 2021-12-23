/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkcpyn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:07:09 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 19:19:41 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_stkcpyn(t_stack *stack, size_t n, void (*del)(void *))
{
	t_stack			*new_stk;
	t_stack_unit	*curr;

	new_stk = ft_stkstart();
	if (!new_stk)
		return (NULL);
	curr = stack->top;
	while (curr && n--)
	{
		if (!ft_stkrpush(new_stk, curr->content))
		{
			ft_stkclean(new_stk, del);
			return (NULL);
		}
		curr = curr->next;
	}
	return (new_stk);
}
