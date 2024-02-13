/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:16:25 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/13 14:05:25 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_srv_ready = 1;

void	confirm_reception(int signum)
{
	(void)signum;
	g_srv_ready = 1;
}

void	init_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &confirm_reception;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(2, "Error: sigaction failed.\n", 25);
}

void	send_bit(int pid, int bit)
{
	int	timeout;

	if (bit == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error sending SIGUSR1, check the PID\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error sending SIGUSR2, check the PID\n");
			exit(EXIT_FAILURE);
		}
	}
	g_srv_ready = 0;
	timeout = 0;
	while (!g_srv_ready && timeout < 50)
	{
		usleep(50);
		timeout++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			send_bit(pid, (message[i] >> j) & 1);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		send_bit(pid, 0);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Usage: ./client (PID) (message)\n");
		return (1);
	}
	init_signal_handler();
	send_message(ft_atoi(av[1]), av[2]);
	return (0);
}
