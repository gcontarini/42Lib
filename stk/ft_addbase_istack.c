/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addbase_istack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:33:48 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 11:42:56 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_istack	*ft_addbase_istack(t_istack *stk, int i)
{
	t_isunit	*new;

	if (!stk)
		return (NULL);
	new = (t_isunit *) malloc(sizeof(t_isunit));
	if (!new)
		return (NULL);
	new->i = i;
	new->last = NULL;
	if (stk->base)
	{
		stk->base->last = new;
		stk->base = new;
		return (stk);
	}
	stk->base = new;
	if (!stk->top)
		stk->top = new;
	return (stk);
}
