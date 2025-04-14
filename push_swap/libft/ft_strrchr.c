/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:27:06 by vzots             #+#    #+#             */
/*   Updated: 2025/01/20 19:27:32 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*symb;

	symb = NULL;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			symb = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (symb);
}
