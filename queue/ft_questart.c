#include "ft_queue.h"

t_queue2	*ft_questart(void)
{
	t_queue2	*queue;

	queue = (t_queue2 *) malloc(sizeof(t_queue2));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}
