/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:41:39 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 19:16:41 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	istack2arr(t_stack *stack, int *arr, size_t len);
static void	arr2istack(int *arr, t_stack *stack, size_t len);
static int	mergesort_int(int *arr, size_t len);
static int	merge_int(int *arr, size_t len);

t_stack	*ft_istksort(t_stack *stack)
{
	int			*arr;
	size_t		len;

	if (!stack || !stack->top)
		return (NULL);
	len = ft_stklen(stack);
	arr = (int *) malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	istack2arr(stack, arr, len);
	if (!mergesort_int(arr, len))
	{
		free(arr);
		return (NULL);
	}
	arr2istack(arr, stack, len);
	free(arr);
	return (stack);
}

static void	istack2arr(t_stack *stack, int *arr, size_t len)
{
	size_t			i;
	t_stack_unit	*curr;

	i = 0;
	curr = stack->top;
	while (curr && i < len)
	{
		arr[i++] = *((int *) curr->content);
		curr = curr->next;
	}
	return ;
}

static void	arr2istack(int *arr, t_stack *stack, size_t len)
{
	size_t			i;
	t_stack_unit	*curr;

	i = 0;
	curr = stack->top;
	while (curr && i < len)
	{
		*((int *) curr->content) = arr[i++];
		curr = curr->next;
	}
	return ;
}

static int	mergesort_int(int *arr, size_t len)
{
	if (len <= 1)
		return (1);
	mergesort_int(arr, len / 2);
	if (len % 2 == 0)
		mergesort_int(arr + (len / 2), (len / 2));
	else
		mergesort_int(arr + (len / 2), (len / 2) + 1);
	if (!merge_int(arr, len))
		return (0);
	return (1);
}

static int	merge_int(int *arr, size_t len)
{
	int		*merged;
	size_t	i;
	size_t	j;

	merged = (int *) malloc(len * sizeof(int));
	if (!merged)
		return (0);
	i = 0;
	j = len / 2;
	while (i < len / 2 && j < len)
	{
		if (arr[i] < arr[j])
			*merged++ = arr[i++];
		else
			*merged++ = arr[j++];
	}
	while (i < len / 2)
		*merged++ = arr[i++];
	while (j < len)
		*merged++ = arr[j++];
	ft_memcpy(arr, merged - j, len * sizeof(int));
	free(merged - j);
	return (1);
}
