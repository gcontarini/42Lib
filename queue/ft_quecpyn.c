#include "ft_queue.h"

t_queue2	*ft_quecpyn(t_queue2 *queue, void *(*cpy)(void *), size_t n, void (*del)(void *))
{
	t_queue2	*new_que;
	t_queue_unit	*curr;
	void		*p;

	new_que = ft_questart();
	if (!new_que)
		return (NULL);
	curr = queue->rear;
	while (curr && n--)
	{
		p = cpy(curr->content);
		if (!p || !ft_enque(new_que, p))
		{
			ft_queclean(new_que, del);
			return (NULL);
		}
		curr = curr->next;
	}
	return (new_que);
}
