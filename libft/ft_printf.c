/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:25:17 by vzots             #+#    #+#             */
/*   Updated: 2025/02/10 16:25:46 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_handle_print(int count, va_list *args)
{
	if (count < 0)
	{
		va_end(*args);
		return (-1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;
	int		res;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res = ft_check_type(str[i], args);
		}
		else
			res = ft_print_c(str[i]);
		if (ft_handle_print(res, &args) == -1)
			return (-1);
		count += res;
		i++;
	}
	va_end (args);
	return (count);
}
