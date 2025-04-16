/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:34:24 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 19:05:42 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	count_str_argv(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_valid_sign(char *argv, int j)
{
	return ((argv[j] == '-' || argv[j] == '+')
		&& (j == 0 || argv[j - 1] == ' ')
		&& ft_isdigit(argv[j + 1]));
}

static int	parse_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_ower(const char *str)
{
	size_t			i;
	int				sign;
	long			res;
	long			prev;

	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = parse_sign(str, &i);
	while (ft_isdigit(str[i]) != 0)
	{
		prev = res;
		res = (str[i] - '0') + (res * 10);
		if (res / 10 != prev)
			print_error();
		i++;
	}
	res *= sign;
	if ((int)res != res)
		print_error();
	return ((int)res);
}
