/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_istack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:31:03 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 11:48:02 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_istack	*ft_cpy_istack(t_istack *stk)
{
	t_istack	*new_stk;
	t_isunit	*curr;

	new_stk = ft_start_istack();
	if (!new_stk)
		return (NULL);
	curr = stk->top;
	while (curr)
	{
		if (!ft_addbase_istack(new_stk, curr->i))
		{
			ft_clean_istack(new_stk);
			return (NULL);
		}
		curr = curr->last;
	}
	return (new_stk);
}
