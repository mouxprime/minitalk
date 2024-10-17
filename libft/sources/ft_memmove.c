/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:54:13 by mianni            #+#    #+#             */
/*   Updated: 2024/05/23 17:37:46 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*destbis;
	char			*srcbis;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	destbis = ((char *)dest);
	srcbis = ((char *)src);
	if (n == 0)
		return (destbis);
	if (destbis > srcbis)
	{
		while (n-- > 0)
			destbis[n] = srcbis[n];
	}
	else
	{
		while (i < n)
		{
			destbis[i] = srcbis[i];
			i++;
		}
	}
	return (destbis);
}
