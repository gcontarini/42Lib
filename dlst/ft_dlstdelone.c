#include "ft_dlist.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (!dlst || !del)
		return ;
	if (dlst->content)
		del(dlst->content);
	free(dlst);
}
