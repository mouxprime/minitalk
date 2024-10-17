/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:55:25 by mianni            #+#    #+#             */
/*   Updated: 2024/05/21 17:13:14 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	unsigned long int	srclen;
	unsigned long int	destlen;
	unsigned long int	i;

	srclen = 0;
	destlen = 0;
	i = 0;
	while (src[srclen] != '\0')
		srclen++;
	while (dest[destlen] != '\0')
		destlen++;
	if (count <= destlen)
		return (srclen + count);
	while (src[i] && (count - destlen - 1 > i))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
/*
int	main(void)
{
	char	dest[] = "Maxime ";
	char	src[] = "1234567890";
	unsigned long int	count;
	unsigned long int	i;

	count = 14;
	i = 0;
	ft_strlcat(dest, src, count);
	while (dest[i] != '\0')
	{
		write(1, &dest[i], 1);
		i++;
	}
}*/
