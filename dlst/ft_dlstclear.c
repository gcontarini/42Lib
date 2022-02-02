#include "ft_dlist.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*tmp;

	if (!dlst || !del)
		return ;
	while (*dlst)
	{
		tmp = *dlst;
		*dlst = (*dlst)->next;
		ft_dlstdelone(tmp, del);
	}
}
