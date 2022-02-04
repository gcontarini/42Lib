/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:48:57 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:48:59 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
