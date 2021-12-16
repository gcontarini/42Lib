/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_istack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:12:12 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:12:42 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_istack	*ft_start_istack(void)
{
	t_istack	*stack;

	stack = (t_istack *) malloc(sizeof(t_istack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->base = NULL;
	return (stack);
}
