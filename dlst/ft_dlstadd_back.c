#include "ft_dlist.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		last = ft_dlstlast(*dlst);
		last->next = new;
		new->last = last;
	}
	else
		*dlst = new;
}
