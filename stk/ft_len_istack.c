/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_istack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:30:18 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:57:05 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_len_istack(t_istack *stack)
{
	t_isunit	*curr;
	size_t		len;

	len = 0;
	if (!stack)
		return (len);
	curr = stack->top;
	while (curr)
	{
		len++;
		curr = curr->last;
	}
	return (len);
}
