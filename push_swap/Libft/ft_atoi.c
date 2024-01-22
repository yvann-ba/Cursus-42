/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:54:06 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/22 11:38:26 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

// int	ft_atoi(const char *str)
// {
// 	size_t	i;
// 	int		is_neg;
// 	int		nb;

// 	i = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	is_neg = 0;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			is_neg++;
// 		i++;
// 	}
// 	nb = 0;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nb = (nb * 10) + str[i] - '0';
// 		i++;
// 	}

// }
int ft_atoi_convert(const char *str, int is_neg, int *error)
{
    long long nb;
    size_t i;

    nb = 0;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + (str[i] - '0');
        if ((is_neg && -nb < INT_MIN) || (!is_neg && nb > INT_MAX))
        {
            *error = 1;
            return (0);
        }
        i++;
    }
	if (is_neg == 1)
		return (-nb);
	return (nb);
}

int ft_atoi(const char *str, int *error)
{
    size_t i;
    int is_neg;

    *error = 0;
    i = 0;
    is_neg = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            is_neg = 1;
        i++;
    }
    return (ft_atoi_convert(&str[i], is_neg, error));
}
