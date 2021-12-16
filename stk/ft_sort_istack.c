/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_istack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:50:06 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/16 18:39:48 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	istack2arr(t_istack *stack, int *arr, size_t len);
static void	arr2istack(int *arr, t_istack *stack, size_t len);
static void	mergesort_int(int *arr, size_t len);
static void	merge_int(int *arr, size_t len);

t_istack	*ft_sort_istack(t_istack *stack)
{
	int			*arr;
	size_t		len;

	if (!stack || !stack->top)
		return (NULL);
	len = ft_len_istack(stack);
	arr = (int *) malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	istack2arr(stack, arr, len);
	mergesort_int(arr, len);
	arr2istack(arr, stack, len);
	free(arr);
	return (stack);
}

static void	istack2arr(t_istack *stack, int *arr, size_t len)
{
	size_t		i;
	t_isunit	*curr;

	i = 0;
	curr = stack->top;
	while (curr && i < len)
	{
		arr[i++] = curr->i;
		curr = curr->last;
	}
	return ;
}

static void	arr2istack(int *arr, t_istack *stack, size_t len)
{
	size_t		i;
	t_isunit	*curr;

	i = 0;
	curr = stack->top;
	while (curr && i < len)
	{
		curr->i = arr[i++];
		curr = curr->last;
	}
	return ;
}

static void	mergesort_int(int *arr, size_t len)
{
	if (len <= 1)
		return ;
	mergesort_int(arr, len / 2);
	if (len % 2 == 0)
		mergesort_int(arr + (len / 2), (len / 2));
	else
		mergesort_int(arr + (len / 2), (len / 2) + 1);
	merge_int(arr, len);
}

static void	merge_int(int *arr, size_t len)
{
	int		merged[10000];
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = len / 2;
	k = 0;
	while (i < len / 2 && j < len)
	{
		if (arr[i] < arr[j])
			merged[k++] = arr[i++];
		else
			merged[k++] = arr[j++];
	}
	while (i < len / 2)
		merged[k++] = arr[i++];
	while (j < len)
		merged[k++] = arr[j++];
	k = 0;
	i = 0;
	while (k < len)
		arr[i++] = merged[k++];
}
