#include "ft_printf.h"
#include "ft_stack.h"

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
	if (stack->top)
		stack->top->next = NULL;
	if (tmp)
		free(tmp);
	return (pop);
}

void	ft_swap_istack(t_istack *stack)
{
	t_isunit	*top;
	t_isunit	*l1;

	if (!stack || !stack->top)
		return ;
	top = stack->top;
	if (!top->last)
		return ;
	l1 = top->last;
	top->next = l1;
	top->last = l1->last;
	l1->next = NULL;
	l1->last = top;
	stack->top = l1;
	if (!top->last)
		stack->base = top;
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

void	ft_mvto_istack(t_istack *src, t_istack *dst)
{
	t_isunit	*tmp;

	if (!dst || !src || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->last;
	if (src->top)
		src->top->next = NULL;
	else
		src->base = NULL;
	if (dst->top)
	{
		dst->top->next = tmp;
		tmp->last = dst->top;
		dst->top = tmp;
		return ;
	}
	dst->top = tmp;
	dst->base = tmp;
	tmp->last = NULL;
	return ;
}
