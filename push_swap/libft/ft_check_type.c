/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:22:24 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:22:38 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_check_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (char)ft_print_c(va_arg(args, int));
	if (type == 's')
		count += ft_print_str(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_print_nbr(va_arg(args, int));
	if (type == 'p')
		count += ft_print_ptr(va_arg(args, uintptr_t));
	if (type == 'u')
		count += ft_print_unbr(va_arg(args, unsigned int));
	if (type == 'x')
		count += (char)ft_print_hex(va_arg(args, int), 1);
	if (type == 'X')
		count += (char)ft_print_hex(va_arg(args, int), 0);
	if (type == '%')
		return (write(1, "%", 1));
	return (count);
}
