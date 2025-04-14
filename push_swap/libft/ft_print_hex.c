/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:12 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:23:16 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_hex_digit(unsigned int num)
{
	int	div;

	div = 1;
	while (num / div >= 16)
	{
		div *= 16;
	}
	return (div);
}

int	ft_print_hex(unsigned int n, int char_case)
{
	int	count;
	int	digit;
	int	count_digit;

	if (char_case == 1)
		char_case = 32;
	count_digit = ft_count_hex_digit(n);
	count = 0;
	while (count_digit > 0)
	{
		digit = (n / count_digit) % 16;
		if (digit < 10)
		{
			if (ft_print_c((digit + '0')) == -1)
				return (-1);
		}
		else
			if (ft_print_c(((digit - 10) + 'A' + char_case)) == -1)
				return (-1);
		count++;
		count_digit /= 16;
	}
	return (count);
}
/*
int main()
{
	int count = 0;
	int	i = 0;
	int	test = -1;
	
	count += ft_print_hex(test, 1);
	printf("\nexpend = %x", test);
	printf("\ncount = %d", count);
	return 0;
}
*/
