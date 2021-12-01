/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:49:25 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/01 16:11:29 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"

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

t_istack	*ft_push_istack(t_istack *stack, int i)
{
	t_isunit	*tmp;

	if (!stack)
		return (NULL);
	tmp = (t_isunit *) malloc(sizeof(t_isunit));
	if (!tmp)
		return (NULL);
	tmp->i = i;
	tmp->next = NULL;
	if (stack->top)
	{
		tmp->last = stack->top;
		stack->top->next = tmp;
		stack->top = tmp;
		return (stack);
	}
	tmp->last = NULL;
	stack->top = tmp;
	stack->base = tmp;
	return (stack);
}

t_isunit	ft_peek_istack(t_istack *stack)
{
	t_isunit	peeked;

	peeked.next = NULL;
	peeked.last = NULL;
	if (!stack || !stack->top)
		return (peeked);
	peeked = *(stack->top);
	return (peeked);
}

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

void	ft_clean_istack(t_istack *stack)
{
	t_isunit	*curr;

	if (!stack)
		return ;
	curr = stack->top;
	while (curr)
	{
		stack->top = stack->top->last;
		free(curr);
		curr = stack->top;
	}
	free(stack);
	return ;
}
