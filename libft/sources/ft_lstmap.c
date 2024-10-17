/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:56:04 by mianni            #+#    #+#             */
/*   Updated: 2024/05/30 20:34:38 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstbis;
	t_list	*new_block;
	t_list	*new_list;

	lstbis = lst;
	new_list = NULL;
	while (lstbis)
	{
		new_block = ft_lstnew(lstbis->content);
		if (new_block == NULL)
		{
			del(new_block);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_block->content = f(new_block->content);
		ft_lstadd_back(&new_list, new_block);
		lstbis = lstbis->next;
	}
	return (new_list);
}
