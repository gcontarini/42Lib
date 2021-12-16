/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_istack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:13:56 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 11:12:47 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_isunit	*ft_peek_istack(t_istack *stack, size_t index)
{
	t_isunit	*curr;

	if (!stack || !stack->top)
		return (NULL);
	curr = stack->top;
	while (curr && index != 0 && index-- > 0)
		curr = curr->last;
	return (curr);
}
