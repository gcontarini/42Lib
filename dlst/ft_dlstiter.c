#include "ft_dlist.h"

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	if (!f)
		return ;
	while (dlst)
	{
		if (dlst->content)
			f(dlst->content);
		dlst = dlst->next;
	}
}
