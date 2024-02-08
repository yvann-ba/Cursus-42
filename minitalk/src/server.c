/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:16:31 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/08 09:04:47 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 0;
	static char	c = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

//chricri
int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: ");
	ft_putnbr_fd(getpid(), 1);
	ft_printf("\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
