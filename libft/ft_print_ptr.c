/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:43 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:24:22 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_ptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	count += ft_print_str("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(ptr);
	return (count);
}
