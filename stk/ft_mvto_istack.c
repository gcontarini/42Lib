/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvto_istack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:20:01 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:24:57 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_mvto_istack(t_istack *src, t_istack *dst)
{
	t_isunit	*tmp;

	if (!dst || !src || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->last;
	if (!src->top)
		src->base = NULL;
	if (dst->top)
	{
		tmp->last = dst->top;
		dst->top = tmp;
		return ;
	}
	dst->top = tmp;
	dst->base = tmp;
	tmp->last = NULL;
	return ;
}
