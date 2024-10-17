/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:27:16 by mianni            #+#    #+#             */
/*   Updated: 2024/05/23 17:57:47 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	unsigned char	*tab;
	size_t			i;
	size_t			mallocsize;

	i = 0;
	if (len != 0 && size > __SIZE_MAX__ / len)
		return (NULL);
	mallocsize = len * size;
	tab = malloc(mallocsize);
	if (tab == NULL)
		return (NULL);
	while (i < mallocsize)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}
