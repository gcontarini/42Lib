#include "ft_dlist.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	len;

	len = 0;
	while (dlst)
	{
		len++;
		dlst = dlst->next;
	}
	return (len);
}
