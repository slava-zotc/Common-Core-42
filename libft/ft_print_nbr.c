/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:28 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:23:33 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_handle_negativ(int *n)
{
	int	count;

	count = 0;
	if (*n < 0)
	{
		if (ft_print_c('-') == -1)
			return (-1);
		count++;
		if (*n == INT_MIN)
		{
			if (ft_print_c('2') == -1)
				return (-1);
			count++;
			*n = -147483648;
		}
		*n = -*n;
	}
	return (count);
}

int	ft_print_nbr(int n)
{
	int	count;
	int	div;

	div = 1;
	count = ft_handle_negativ(&n);
	if (count < 0)
		return (-1);
	while (n / div >= 10)
		div *= 10;
	while (div > 0)
	{
		if (ft_print_c((n / div) + '0') == -1)
			return (-1);
		count++;
		n %= div;
		div /= 10;
	}
	return (count);
}
