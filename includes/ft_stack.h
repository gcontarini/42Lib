/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:49:36 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:35:11 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

typedef t_list	t_stack_unit;

typedef struct s_stack
{
	t_stack_unit	*top;
	t_stack_unit	*base;
}	t_stack;

// stack
t_stack			*ft_stkstart(void);
t_stack			*ft_stkpush(t_stack *stack, void *p);
t_stack			*ft_stkrpush(t_stack *stack, void *p);
t_stack			*ft_stkcpy(t_stack *stack, void *(*cpy)(), void (*del)());
t_stack			*ft_stkcpyn(t_stack *s, void *(c)(), size_t n, void (*d)());
t_stack_unit	*ft_stkget(t_stack *stack, size_t n);
t_stack_unit	ft_stkpop(t_stack *stack);
size_t			ft_stklen(t_stack *stack);
void			ft_stkclean(t_stack *stack, void (*del)(void *));
int				ft_stkswap(t_stack *stack);
int				ft_stkswapn(t_stack *stack, size_t n);
int				ft_stkrot(t_stack *stack);
int				ft_stkrrot(t_stack *stack);
int				ft_stkposh(t_stack *src, t_stack *dst);

// integer stack
t_stack			*ft_istksort(t_stack *stack);
void			ft_istkprint(t_stack *stack);
void			ft_istkclean(t_stack *stack);
int				ft_istkpeek(t_stack *stack, size_t n);

#endif
