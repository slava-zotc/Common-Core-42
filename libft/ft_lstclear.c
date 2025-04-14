/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:23:32 by vzots             #+#    #+#             */
/*   Updated: 2025/01/29 16:23:39 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*head;

	head = *lst;
	while (head)
	{
		tmp = head->next;
		(*del)(head -> content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
