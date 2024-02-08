/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:16:25 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/06 15:07:34 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			bit = (message[i] >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Usage: ./client [PID] [MESSAGE]\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_message(pid, av[2]);
	return (0);
}
