/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:49:36 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/30 19:42:24 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct s_int_stack_unit
{
	int						i;
	struct s_int_stack_unit	*next;
	struct s_int_stack_unit	*last;
}	t_isunit;

typedef struct s_int_stack
{
	t_isunit	*top;
	t_isunit	*base;
}	t_istack;

//ft_stack
t_istack	*ft_start_istack(void);
void		ft_prepare_istack(t_istack *stack);
void		ft_print_istack(t_istack *stack);
void		ft_clean_istack(t_istack *stack);
//ft_stack_methods
t_istack	*ft_push_istack(t_istack *stack, int i);
t_isunit	ft_pop_istack(t_istack *stack);
t_isunit	ft_peek_istack(t_istack *stack);
//ft_stack_moves
void		ft_swap_istack(t_istack *stack);
void		ft_rot_istack(t_istack *stack);
void		ft_rrot_istack(t_istack *stack);

#endif
