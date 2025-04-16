/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:29:35 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 19:33:28 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static	void	free_stack(t_stack *a)
{
	t_stack	*tmp;
	
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		count_number;
	int		*indexed;
	int		*arr;

	count_number = 0;
	if (argc == 1)
		exit(1);
	arr = validator(argv, argc, &count_number);
	indexed = normalize_input(arr, count_number);
	init_and_fill_stack(&a, &b, indexed, count_number);
	chunk_sort(&a, &b, count_number);
	free(arr);
	free(indexed);
	free_stack(a);
	return (0);
}
