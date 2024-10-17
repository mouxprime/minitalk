/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:40:06 by mianni            #+#    #+#             */
/*   Updated: 2024/05/23 16:58:46 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_forbidden(char str, const char *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (str == set[k])
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*s1bis;

	s1bis = (char *)(s1);
	start = 0;
	end = ft_strlen(s1);
	while (s1bis[start])
	{
		if (ft_forbidden(s1bis[start], set) == 1)
			start++;
		else
			break ;
	}
	while (start < end)
	{
		if (ft_forbidden(s1bis[end - 1], set) == 1)
			end--;
		else
			break ;
	}
	return (ft_substr(s1, start, (end - start)));
}
