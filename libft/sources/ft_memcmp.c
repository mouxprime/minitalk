/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:48:19 by mianni            #+#    #+#             */
/*   Updated: 2024/05/23 17:11:18 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long int	i;
	unsigned char		*s1bis;
	unsigned char		*s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1bis[i] == s2bis[i] && (i != n - 1))
		i++;
	return (s1bis[i] - s2bis[i]);
}
