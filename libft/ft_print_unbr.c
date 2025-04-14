/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:24:53 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:25:05 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_unbr( unsigned int n)
{
	int	count;
	int	div;

	count = 0;
	div = 1;
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
