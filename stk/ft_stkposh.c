/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkposh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:56 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:35:06 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkposh(t_stack *src, t_stack *dst)
{
	t_stack_unit	*tmp;

	if (!dst || !src || !src->top)
		return (0);
	tmp = src->top;
	src->top = src->top->next;
	if (!src->top)
		src->base = NULL;
	if (dst->top)
	{
		tmp->next = dst->top;
		dst->top = tmp;
		return (1);
	}
	dst->top = tmp;
	dst->base = tmp;
	tmp->next = NULL;
	return (1);
}
