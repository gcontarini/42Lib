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
t_queue2			*ft_questart(void);
t_queue2			*ft_enque(t_queue2 *queue, void *p);
t_queue2			*ft_quecpy(t_queue2 *queue, void *(*cpy)(void *), void (*del)(void *));
t_queue2			*ft_quecpyn(t_queue2 *queue, void *(cpy)(void *), size_t n, void (*del)(void *));
t_queue_unit	*ft_queget(t_queue2 *queue, size_t n);
t_queue_unit	ft_deque(t_queue2 *queue);
size_t			ft_quelen(t_queue2 *queue);
void			ft_queclean(t_queue2 *queue, void (*del)(void *));

// integer queue
void			ft_iqueprint(t_queue2 *queue);
void			ft_iqueclean(t_queue2 *queue);

#endif
