#include "ft_queue.h"

void	ft_queclean(t_queue2 *queue, void (*del)(void *))
{
	if (!queue)
		return ;
	ft_dlstclear(&(queue->rear), del);
	free(queue);
	return ;
}
