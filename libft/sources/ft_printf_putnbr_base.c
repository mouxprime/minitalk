/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:37:38 by mianni            #+#    #+#             */
/*   Updated: 2024/07/10 15:13:50 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_count_base(size_t nbr, const char type)
{
	size_t	compteur;

	compteur = 0;
	if (type == 'p')
		compteur += 2;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		compteur++;
	}
	return (compteur);
}

size_t	ft_putnbr_base_printf(size_t nbr, const char type)
{
	size_t	result;

	if (nbr / 16 != 0)
	{
		ft_putnbr_base_printf(nbr / 16, type);
	}
	result = nbr % 16;
	if (result < 10)
		ft_putchar_printf(result + '0');
	else
	{
		if (type == 'x' || type == 'p')
			ft_putchar_printf((result - 10) + 'a');
		else if (type == 'X')
			ft_putchar_printf((result - 10) + 'A');
	}
	return (result);
}

size_t	ft_print_hex_printf(size_t nbr, const char type)
{
	if (type == 'p' && nbr != 0)
		write(1, "0x", 2);
	if (type == 'p' && nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (nbr == 0)
	{
		return (write(1, "0", 1));
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar_printf('-');
			nbr *= -1;
		}
		ft_putnbr_base_printf(nbr, type);
	}
	return (ft_count_base(nbr, type));
}
