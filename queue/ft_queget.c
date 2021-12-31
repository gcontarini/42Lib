#include "ft_queue.h"

t_queue_unit	*ft_queget(t_queue2 *queue, size_t n)
{
	t_queue_unit	*curr;

	if (!queue || !queue->front)
		return (NULL);
	curr = queue->front;
	while (curr && n-- > 0)
		curr = curr->last;
	return (curr);
}
