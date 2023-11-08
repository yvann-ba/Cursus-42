/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:54:06 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/08 09:56:11 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		neg_count;
	int		nb;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	neg_count = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg_count++;
		i++;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
			nb = (nb * 10) + str[i] - '0';
			i++;
	}
	if (neg_count % 2 == 1)
		return (-nb);
	return (nb);
}
