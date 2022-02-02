#include "ft_dlist.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	if (!dlst || !new)
		return ;
	new->next = *dlst;
	if (*dlst)
		(*dlst)->last = new;
	*dlst = new;
}
