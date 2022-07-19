/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:25:15 by llawrenc          #+#    #+#             */
/*   Updated: 2022/01/03 15:10:06 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signal)
{
	static unsigned long	counter;

	if (signal == SIGUSR1)
		++counter;
	else
	{
		ft_putstr_fd("Received:\t", 1);
		ft_putnbr_fd(counter >> 3, 1);
		ft_putstr_fd("\n", 1);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	unsigned int		pid;
	int					i;
	struct sigaction	act;

	i = -1;
	if (argc != 3)
	{
		write(2, "Enter the PID and text.\n", 24);
		return (-1);
	}
	act.sa_handler = sig_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		write(2, "Error in signal processing.\n", 28);
	output_sent_char(argv[2]);
	pid = ft_atoi(argv[1]);
	while (argv[2][++i])
		send_signal(pid, argv[2][i]);
	send_signal(pid, 0);
	return (0);
}
