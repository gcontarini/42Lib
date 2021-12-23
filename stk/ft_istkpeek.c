/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istkpeek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:47:41 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:49:37 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_istkpeek(t_stack *stack, size_t n)
{
	t_stack_unit	*curr;

	curr = ft_stkget(stack, n);
	return (*((int *) curr->content));
}
