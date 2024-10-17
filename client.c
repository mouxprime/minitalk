/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:03:43 by mianni            #+#    #+#             */
/*   Updated: 2024/08/13 19:37:19 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/sources/libft.h"

static void	gerer_signal(int signal, siginfo_t *infos, void *context)
{
	static int	compteur = 0;

	(void)context;
	(void)infos;
	if (signal == SIGUSR1)
		++compteur;
	else
	{
		ft_putnbr_fd(compteur, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	envoyer_message(int server_pid, char *str)
{
	int		i;
	char	c;
	int		j;

	j = 0;
	while (str[j])
	{
		i = 8;
		c = str[j];
		while (i--)
		{
			if (c >> i & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(1000);
		}
		j++;
	}
	i = 8;
	while (i--)
	{
		kill(server_pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action_signal;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Envoyé  : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Reçu    : ", 1);
	action_signal.sa_sigaction = gerer_signal;
	action_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action_signal, 0);
	sigaction(SIGUSR2, &action_signal, 0);
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 4194304)
	{
		ft_printf("error -> PID incorrect.\n");
		return (1);
	}
	envoyer_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
