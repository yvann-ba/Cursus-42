/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:32:06 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/06 11:25:09 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == '-' || c == '+');
}

int	ft_check_valid_number(const char *str)
{
	int	i;
	int	has_sign;

	i = 0;
	has_sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		has_sign = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (i > has_sign);
}
