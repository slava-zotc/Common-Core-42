/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:03:38 by vzots             #+#    #+#             */
/*   Updated: 2025/01/20 21:03:43 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf_1;
	unsigned char	*buf_2;
	size_t			i;

	i = 0;
	buf_1 = (unsigned char *)s1;
	buf_2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*buf_1 != *buf_2)
			return (*buf_1 - *buf_2);
		buf_1++;
		buf_2++;
		i++;
	}
	return (0);
}
