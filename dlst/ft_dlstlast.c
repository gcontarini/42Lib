#include "ft_dlist.h"

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->next)
		dlst = dlst->next;
	return (dlst);
}
