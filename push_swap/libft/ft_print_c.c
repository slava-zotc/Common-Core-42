/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:22:45 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:22:50 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
/*
int main()
{
	int count = 0;
	int	i = 0;
	char	*test = "qwerty";
	while (test[i])
	{
		count += ft_print_c(test[i]);
		i++;
	}
	printf("\ncount = %d", count);
	return 0;
}
*/
