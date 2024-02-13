/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:16:31 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/13 14:03:34 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	print_char_and_reset(char *c, int *i, int client_pid)
{
	(void)client_pid;
	write(1, c, 1);
	if (*c == '\0')
		write(1, "\n", 1);
	*i = 0;
	*c = 0;
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 0;
	static char	c = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
		c |= (1 << i);
	else if (sig == SIGUSR2)
		c &= ~(1 << i);
	i++;
	if (i == 8)
		print_char_and_reset(&c, &i, info->si_pid);
	kill(info->si_pid, SIGUSR2);
}

static void	init_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_printf("PID of the server: %d\n", getpid());
	init_sigaction();
	while (1)
		pause();
	return (0);
}
