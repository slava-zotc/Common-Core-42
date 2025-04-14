/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:40:17 by vzots             #+#    #+#             */
/*   Updated: 2025/04/10 16:42:43 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	bubble_sort(int *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
				ft_swap(&sorted[j], &sorted[j + 1]);
			j++;
		}
		i++;
	}
}

static int	*arr_indexfy(int *sorted, int size, int *arr)
{
	int	*arr_indexfy;
	int	i;
	int	j;

	i = 0;
	arr_indexfy = malloc(sizeof(int) * size);
	if (!arr_indexfy)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (sorted[j] == arr[i])
			{
				arr_indexfy[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (arr_indexfy);
}

int	*normalize_input(int *arr, int size)
{
	int	*sorted;
	int	i;

	i = 0;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	bubble_sort(sorted, size);
	sorted = arr_indexfy(sorted, size, arr);
	return (sorted);
}
