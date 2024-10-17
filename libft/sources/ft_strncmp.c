/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:05:18 by mianni            #+#    #+#             */
/*   Updated: 2024/05/21 16:52:50 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	s1bis = ((unsigned char *)s1);
	s2bis = ((unsigned char *)s2);
	i = 0;
	if (n == 0)
		return (0);
	while (s1bis[i] == s2bis[i] && (i != n - 1) && s1bis[i] && s2bis[i])
		i++;
	return (s1bis[i] - s2bis[i]);
}
/*
int	main(void)
{
	const char s1[] = "Salut";
	const char s2[] = "Salut";
	size_t n = 10;
	ft_strncmp(s1, s2, n);
	printf("%d", ft_strncmp(s1, s2, n));
}*/
