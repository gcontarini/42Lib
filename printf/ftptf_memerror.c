/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftptf_memerror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:33:04 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/24 14:08:33 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	memerror_int(void)
{
	errno = ENOMEM;
	return (-1);
}

t_queue	*memerror_queue(t_queue *queue)
{
	errno = ENOMEM;
	clean_queue(queue);
	return (NULL);
}
