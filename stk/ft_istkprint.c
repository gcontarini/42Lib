/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istkprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:50:09 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 18:54:58 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"
#define TOP_LINE "/\t*******************\n"
#define CONTENT_LINE "|\tIndex: %i -> value %i\t|\n"
#define BOTTOM_LINE "\\\t*******************\n"

void	ft_istkprint(t_stack *stack)
{
	int				content;
	int				i;
	t_stack_unit	*curr;

	if (!stack || !stack->top)
		return ;
	i = 0;
	curr = stack->top;
	ft_printf(TOP_LINE);
	while (curr)
	{
		content = *((int *) curr->content);
		ft_printf(CONTENT_LINE, i++, content);
		curr = curr->next;
	}
	ft_printf(BOTTOM_LINE);
	return ;
}
