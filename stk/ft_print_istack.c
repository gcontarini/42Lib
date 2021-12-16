/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_istack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:14:35 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 10:15:08 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"

void	ft_print_istack(t_istack *stack)
{
	int			i;
	t_isunit	*curr;

	if (!stack || !stack->top)
		return ;
	i = 0;
	curr = stack->top;
	ft_printf("/\t*******************\n");
	while (curr)
	{
		ft_printf("|\tIndex: %i -> value %i\t|\n", i++, curr->i);
		curr = curr->last;
	}
	ft_printf("\\\t*******************\n");
	return ;
}
