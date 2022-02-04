/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:50:06 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:50:07 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*start;

	if (!dlst || !f)
		return (NULL);
	while (dlst)
	{
		ft_dlstadd_front(&start, ft_dlstnew(f(dlst->content)));
		if (!start || !start->content)
			ft_dlstclear(&start, del);
		dlst = dlst->next;
	}
	return (start);
}
