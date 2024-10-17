/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:55:10 by mianni            #+#    #+#             */
/*   Updated: 2024/05/21 11:01:03 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*sbis;
	unsigned char	cbis;

	sbis = (unsigned char *)s;
	cbis = (unsigned char)c;
	i = -1;
	while (sbis[++i])
		if (sbis[i] == cbis)
			return ((char *)s + i);
	if (cbis == '\0')
		return ((char *)s + i);
	return (NULL);
}
