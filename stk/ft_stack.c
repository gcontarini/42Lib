/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:49:25 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/30 19:42:17 by gcontari         ###   ########.fr       */
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
	stack->top = (t_isunit *) malloc(sizeof(t_isunit));
	if (!stack->top)
		return (NULL);
	stack->top->i = 0;
	stack->top->next = NULL;
	stack->top->last = NULL;
	stack->base = stack->top;
	return (stack);
}

t_istack	*ft_push_istack(t_istack *stack, int i)
{
	t_isunit	*tmp;

	if (!stack || !stack->top)
		return (NULL);
	tmp = (t_isunit *) malloc(sizeof(t_isunit));
	if (!tmp)
		return (NULL);
	tmp->i = i;
	tmp->next = NULL;
	tmp->last = stack->top;
	stack->top->next = tmp;
	stack->top = tmp;
	return (stack);
}

t_isunit	ft_pop_istack(t_istack *stack)
{
	t_isunit	*tmp;
	t_isunit	pop;

	pop.next = NULL;
	pop.last = NULL;
	if (!stack || !stack->top)
		return (pop);
	pop = *(stack->top);
	tmp = stack->top;
	stack->top = stack->top->last;
	stack->top->next = NULL;
	if (tmp)
		free(tmp);
	return (pop);
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

void	ft_prepare_istack(t_istack *stack)
{
	t_isunit	*tmp;

	if (!stack || !stack->base)
		return ;
	tmp = stack->base;
	stack->base = stack->base->next;
	stack->base->last = NULL;
	free(tmp);
	return ;
}

void	ft_clean_istack(t_istack *stack)
{
	t_isunit	*curr;

	if (!stack || !stack->top)
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

void	ft_swap_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*l1;

	if (!stack || !stack->top)
		return ;
	top = stack->top;
	l1 = NULL;
	if (top->last)
		l1 = top->last;
	if (!l1)
		return ;
	top->next = l1;
	top->last = l1->last;
	if (l1->last)
		l1->last->next = top;
	l1->last = top;
	l1->next = NULL;
	stack->top = l1;
	return ;
}

void	ft_rot_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*base;

	if (!stack || !stack->top || !stack->base || !stack->top->last)
		return ;
	top = stack->top;
	stack->top = stack->top->last;
	stack->top->next = NULL;
	base = stack->base;
	top->next = base;
	top->last = NULL;
	base->last = top;
	stack->base = top;
	return ;
}

void	ft_rrot_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*base;

	if (!stack || !stack->top || !stack->base || !stack->top->last)
		return ;
	top = stack->top;
	top->next = stack->base;
	stack->top = stack->base;
	base = stack->base;
	base->last = top;
	base->next->last = NULL;
	stack->base = base->next;
	base->next = NULL;
	return ;
}
