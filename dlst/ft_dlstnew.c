#include "ft_dlist.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = (t_dlist *) malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->last = NULL;
	return (new);
}
