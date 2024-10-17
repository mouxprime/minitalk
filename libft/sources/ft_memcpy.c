/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:54:05 by mianni            #+#    #+#             */
/*   Updated: 2024/05/21 10:00:01 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t i)
{
	unsigned int	j;
	unsigned char	*destbis;
	unsigned char	*srcbis;

	if (dest == NULL && src == NULL)
		return (NULL);
	destbis = ((unsigned char *)dest);
	srcbis = ((unsigned char *)src);
	j = 0;
	while (j < i)
	{
		destbis[j] = srcbis[j];
		j++;
	}
	return (destbis);
}
