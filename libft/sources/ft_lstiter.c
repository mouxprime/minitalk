/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:57:40 by mianni            #+#    #+#             */
/*   Updated: 2024/05/30 18:07:09 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lsttmp;
	t_list	*tmp;

	lsttmp = lst;
	while (lsttmp)
	{
		tmp = (lsttmp)->next;
		f(lsttmp->content);
		lsttmp = tmp;
	}
}
