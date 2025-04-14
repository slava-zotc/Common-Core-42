/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:05:55 by vzots             #+#    #+#             */
/*   Updated: 2025/01/20 20:05:59 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*st;
	size_t			i;

	i = 0;
	st = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (st[i] == ch)
			return ((void *)st + i);
		i++;
	}
	return (NULL);
}
