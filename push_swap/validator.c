/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:43:40 by vzots             #+#    #+#             */
/*   Updated: 2025/04/10 16:47:22 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	is_digit_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (isvalid_minus(argv[i], j))
			{
				j++;
				continue ;
			}
			if (!(ft_isdigit(argv[i][j])))
				print_error();
			j++;
		}
		i++;
	}
}

int	is_valid_int(char **split_argv, int *arr, int index)
{
	int	i;

	i = 0;
	while (split_argv[i])
	{
		if (split_argv[i][0] == '\0')
			print_error();
		arr[i + index] = ft_atoi_ower(split_argv[i]);
		i++;
	}
	return (i);
}

void	check_copy_int(int *arr, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < index)
	{
		j = i + 1;
		while (j < index)
		{
			if (arr[i] == arr[j])
				print_error();
			j++;
		}
		i++;
	}
}

int	process_split_loop(int argc, char **argv, int mode, int *arr)
{
	int		i;
	char	**split_argv;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv || split_argv[0] == NULL)
			print_error();
		if (mode == 0)
			total += count_str_argv(split_argv);
		else
			total += is_valid_int(split_argv, arr, total);
		free_split(split_argv);
		i++;
	}
	return (total);
}

int	*validator(char **argv, int argc, int *count_number)
{
	int		*arr;

	is_digit_argv(argc, argv);
	*count_number = process_split_loop(argc, argv, 0, NULL);
	arr = malloc(sizeof(int) * (*count_number));
	if (!arr)
		ft_perror_exit("Malloc fail");
	*count_number = 0;
	*count_number = process_split_loop(argc, argv, 1, arr);
	check_copy_int(arr, *count_number);
	return (arr);
}
