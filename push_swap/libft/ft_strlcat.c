/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:48:01 by vzots             #+#    #+#             */
/*   Updated: 2025/01/20 18:48:10 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= s_len)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (s_len + i) < (dstsize - 1))
	{
		dst[s_len + i] = src[i];
		i++;
	}
	dst[s_len + i] = '\0';
	return (ft_strlen(src) + s_len);
}
