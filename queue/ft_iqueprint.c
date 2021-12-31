#include "ft_queue.h"
#include "ft_printf.h"
#define REAR "->|"
#define CONTENT " %i"
#define FRONT " |->\n"

void	ft_iqueprint(t_queue2 *queue)
{
	int		content;
	t_queue_unit	*curr;

	if (!queue || !queue->rear)
		return ;
	curr = queue->rear;
	ft_printf(REAR);
	while (curr)
	{
		content = *((int *) curr->content);
		ft_printf(CONTENT, content);
		curr = curr->next;
	}
	ft_printf(FRONT);
	return ;
}
