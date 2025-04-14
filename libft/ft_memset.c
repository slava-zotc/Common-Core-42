/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:58:43 by vzots             #+#    #+#             */
/*   Updated: 2025/01/16 16:58:45 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *destination, int value, size_t n)
{
	size_t				i;
	unsigned char		*dest;

	dest = (unsigned char *)destination;
	i = 0;
	while (i < n)
	{
		dest[i] = value;
		i++;
	}
	return (dest);
}
