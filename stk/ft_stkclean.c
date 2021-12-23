/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkclean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:15:19 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 19:00:51 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stkclean(t_stack *stack, void (*del)(void *))
{
	if (!stack)
		return ;
	ft_lstclear(&(stack->top), del);
	free(stack);
	return ;
}
