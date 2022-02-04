/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:49:38 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:49:39 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
