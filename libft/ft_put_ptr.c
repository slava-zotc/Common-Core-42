/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:25:57 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:26:44 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_put_ptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr < 16)
	{
		if (ptr < 10)
			count += ft_print_c((ptr + '0'));
		else
			count += ft_print_c(((ptr - 10) + 'a'));
	}
	else
	{
		count += ft_put_ptr((ptr / 16));
		count += ft_put_ptr((ptr % 16));
	}
	if (count < 0)
		return (-1);
	return (count);
}
