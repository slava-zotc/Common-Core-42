/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:26:02 by vzots             #+#    #+#             */
/*   Updated: 2025/01/27 14:26:11 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_digit(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len_n;

	len_n = ft_count_digit(n);
	result = (char *)ft_calloc((len_n + 1), sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result[--len_n] = '8';
			n /= 10;
		}
		n = -n;
		result[0] = '-';
	}
	while (len_n >= 1 && n != 0)
	{
		result[--len_n] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
