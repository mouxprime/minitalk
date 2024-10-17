/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:32:25 by mianni            #+#    #+#             */
/*   Updated: 2024/05/23 14:52:30 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*t;
	unsigned char		cbis;

	t = (unsigned char *)s;
	cbis = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (t[i] == cbis && n > i)
			return ((void *)(&t[i]));
		i++;
	}
	return (NULL);
}
