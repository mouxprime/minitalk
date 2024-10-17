/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:42:36 by mianni            #+#    #+#             */
/*   Updated: 2024/05/23 12:43:26 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(int nb)
{
	unsigned int	i;

	i = 1;
	if (nb < 0)
	{
		i += 1;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_reverse_tab(char *tab)
{
	size_t	j;
	size_t	i;
	size_t	len;
	char	swap;

	j = 0;
	len = ft_strlen(tab) - 1;
	i = 0;
	if (tab[0] == '-')
		i++;
	while (i < len)
	{
		swap = tab[i];
		tab[i] = tab[len];
		tab[len] = swap;
		i++;
		len--;
	}
	return (tab);
}

static char	*ft_convert(int n, char *tab)
{
	size_t	j;

	j = 0;
	if (n < 0)
	{
		tab[j] = '-';
		j++;
		n *= -1;
	}
	while (n != 0)
	{
		tab[j] = n % 10 + 48;
		n = n / 10;
		j++;
	}
	tab[j] = '\0';
	return (ft_reverse_tab(tab));
}

static char	*ft_is_special(long int n)
{
	char	*tab;

	tab = NULL;
	if (n < -2147483647 || n == 0)
	{
		if (n == -2147483648)
		{
			tab = malloc(12 * sizeof(char));
			if (tab == NULL)
				return (NULL);
			ft_strlcpy(tab, "-2147483648", 12);
			tab[12] = '\0';
		}
		else
		{
			tab = malloc(2 * sizeof(char));
			if (tab == NULL)
				return (NULL);
			ft_strlcpy(tab, "0", 2);
			tab[2] = '\0';
		}
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*tab;

	tab = NULL;
	i = ft_intlen(n);
	if (n == 0 || n <= -2147483647)
		return (ft_is_special(n));
	else
		tab = malloc(ft_intlen(n) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	ft_convert(n, tab);
	i = ft_strlen(tab);
	tab[i] = '\0';
	return (tab);
}
