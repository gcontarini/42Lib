#include "ft_queue.h"

void	ft_iqueclean(t_queue2 *queue)
{
	if (!queue)
		return ;
	ft_queclean(queue, free);
	return ;
}
