/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:49:36 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 18:37:25 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_int_stack_unit
{
	int						i;
	struct s_int_stack_unit	*last;
}	t_isunit;

typedef struct s_int_stack
{
	t_isunit	*top;
	t_isunit	*base;
}	t_istack;

// integer stack
t_istack	*ft_start_istack(void);
t_istack	*ft_push_istack(t_istack *stack, int i);
t_istack	*ft_addbase_istack(t_istack *stk, int i);
t_istack	*ft_cpy_istack(t_istack *stk);
t_isunit	*ft_peek_istack(t_istack *stack, size_t index);
t_isunit	ft_pop_istack(t_istack *stack);
size_t		ft_len_istack(t_istack *stack);
void		ft_print_istack(t_istack *stack);
void		ft_clean_istack(t_istack *stack);
void		ft_swap_istack(t_istack *stack);
void		ft_swapi_istack(t_istack *stack, size_t index);
void		ft_rot_istack(t_istack *stack);
void		ft_rrot_istack(t_istack *stack);
void		ft_mvto_istack(t_istack *src, t_istack *dst);
t_istack	*ft_sort_istack(t_istack *stack);

#endif
