/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stklen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:54:49 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 17:55:36 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stklen(t_stack *stack)
{
	t_stack_unit	*curr;
	size_t			len;

	len = 0;
	if (!stack)
		return (len);
	curr = stack->top;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
