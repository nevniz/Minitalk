/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:06:03 by llawrenc          #+#    #+#             */
/*   Updated: 2022/01/03 15:35:29 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	output_pid(int pid)
{
	ft_putstr_fd("The server is running. Its PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
}

void	output_sent_char(char *str)
{
	ft_putstr_fd("\nSent:\t\t", 1);
	ft_putnbr_fd(ft_strlen(str), 1);
	ft_putstr_fd("\n", 1);
}

void	send_signal(int pid, unsigned char ch)
{
	uint8_t	i;

	i = 128;
	while (i)
	{
		if (ch & i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i >>= 1;
		pause();
		usleep(100);
	}
}

static void	final_signal(pid_t client_pid)
{
	kill(client_pid, SIGUSR2);
	write(1, "\n", 1);
	return ;
}

void	output_str(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	ch;
	static int				i;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != siginfo->si_pid)
	{
		client_pid = siginfo->si_pid;
		i = 0;
	}
	ch <<= 1;
	ch |= (signal == SIGUSR2);
	if (++i == 8)
	{
		if (!ch)
			final_signal(client_pid);
		write(1, &ch, 1);
		i = 0;
		ch = 0;
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}
