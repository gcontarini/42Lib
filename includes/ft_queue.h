/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:31:05 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:40:36 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stddef.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_dlist.h"

typedef t_dlist	t_queue_unit;

typedef struct s_queue2
{
	t_queue_unit	*front;
	t_queue_unit	*rear;
}	t_queue2;

// queue
t_queue2		*ft_questart(void);
t_queue2		*ft_enque(t_queue2 *queue, void *p);
t_queue2		*ft_quecpy(t_queue2 *queue, void *(*cpy)(), void (*del)());
t_queue2		*ft_quecpyn(t_queue2 *q, void *(cpy)(), size_t n,
					void (*del)());
t_queue_unit	*ft_queget(t_queue2 *queue, size_t n);
t_queue_unit	ft_deque(t_queue2 *queue);
size_t			ft_quelen(t_queue2 *queue);
void			ft_queclean(t_queue2 *queue, void (*del)());

// integer queue
void			ft_iqueprint(t_queue2 *queue);
void			ft_iqueclean(t_queue2 *queue);

#endif
