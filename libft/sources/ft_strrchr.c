/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:55:56 by mianni            #+#    #+#             */
/*   Updated: 2024/05/21 18:00:10 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*sbis;
	unsigned char	cbis;

	sbis = (unsigned char *)s;
	cbis = (unsigned char)c;
	i = 0;
	while (sbis[i] != '\0')
		i++;
	while (i != -1)
	{
		if (sbis[i] == cbis)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char s[] = "Born9jo9rrrur";
	int c = 'r';
	ft_strrchr(s, c);
	printf("%s", ft_strrchr(s, c));
}*/
