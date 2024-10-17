/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:05:54 by mianni            #+#    #+#             */
/*   Updated: 2024/05/30 17:59:11 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lsttemp;

	lsttemp = *lst;
	while (lsttemp)
	{
		tmp = (lsttemp)->next;
		ft_lstdelone((lsttemp), del);
		lsttemp = tmp;
	}
	*lst = NULL;
}
