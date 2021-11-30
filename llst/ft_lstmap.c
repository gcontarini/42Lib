/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_lstmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:55:57 by gcontari          #+#    #+#             */
/*   Updated: 2021/10/18 11:56:00 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*curr;

	if (!lst || !f)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	curr = start;
	lst = lst->next;
	while (lst && curr)
	{
		curr->next = ft_lstnew(f(lst->content));
		if (!curr->next)
			ft_lstclear(&start, del);
		lst = lst->next;
		curr = curr->next;
	}
	return (start);
}
