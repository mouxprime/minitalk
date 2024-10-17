/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:03:47 by mianni            #+#    #+#             */
/*   Updated: 2024/08/13 19:26:05 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/sources/libft.h"

static void	gerer_signal2(int signal, siginfo_t *infos, void *context)
{
	static int				compteur = 0;
	static pid_t			pid_client = 0;
	static unsigned char	caractere = 0;

	(void)context;
	if (!pid_client)
		pid_client = infos->si_pid;
	caractere |= (signal == SIGUSR2);
	if (++compteur == 8)
	{
		compteur = 0;
		if (!caractere)
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
			return ;
		}
		ft_putchar_fd(caractere, 1);
		caractere = 0;
		kill(pid_client, SIGUSR1);
	}
	else
		caractere <<= 1;
}

int	main(void)
{
	struct sigaction	action_signal;

	ft_putstr_fd("PID du serveur : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	action_signal.sa_sigaction = gerer_signal2;
	action_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action_signal, 0);
	sigaction(SIGUSR2, &action_signal, 0);
	while (1)
		pause();
	return (0);
}
