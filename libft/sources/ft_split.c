/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:41:28 by mianni            #+#    #+#             */
/*   Updated: 2024/05/30 19:14:05 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(char const *s, char c, int o)
{
	int	j;

	j = 0;
	while (s[o] != c && s[o] != '\0')
	{
		j++;
		o++;
	}
	return (j);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] && s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c) && s[i] != '\0')
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_index_sub(char const *s, char c, int o)
{
	while (s[o])
	{
		if (o == 0 && s[o] != c)
			return (o);
		if (s[o] == c && s[o + 1] && s[o + 1] != c)
			return (o + 1);
		o++;
	}
	if (s[o - 1] == c)
		return (-1);
	return (o);
}

static char	**ft_free(char **dest, int q)
{
	if (dest[q] == NULL)
	{
		while (--q >= 0)
			free(dest[q]);
		free(dest);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		size;
	int		q;
	int		o;
	char	**dest;

	o = 0;
	size = ft_count(s, c);
	dest = malloc((size + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	dest[size] = NULL;
	q = 0;
	while (q < size)
	{
		o = ft_index_sub(s, c, o);
		i = ft_get_len(s, c, o);
		dest[q] = ft_substr(s, o, i);
		if (dest[q] == NULL)
			return (ft_free(dest, q));
		q++;
		o += i;
	}
	return (dest);
}
