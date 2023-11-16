/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:03:56 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/16 10:35:04 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_check_character_occurence(char *base)
{
	int		j;
	int		i;
	char	ascii_table[127];

	j = 0;
	while (j != 127)
	{
		ascii_table[j] = 0;
		i = 0;
		while (base[i])
		{
			if (j == base[i])
				ascii_table[j]++;
			i++;
		}
		j++;
	}
	j = 0;
	while (ascii_table[j])
	{
		if (ascii_table[j] > 1)
			return (0);
		j++;
	}
	return (1);
}

int	static	ft_check_parameters(char *base)
{
	int	i;

	if (base[0] == '\0' || base[1] == '\0' )
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int static	ft_unsigned_nbr(unsigned int nbr, char *base)
{
	int		i;
	int		digit;

	i = 0;
	while (base[i])
		i++;
	digit = nbr / i;
	nbr = nbr / i;
	if (nbr)
		ft_unsigned_nbr(nbr, base);
	write(1, &base[digit], 1);

}

int	ft_putlnbr_base(int nbr, char *base)
{
	unsigned int	p;
	int				counter;

	counter = 0;
	if (ft_check_parameters(base) && ft_check_character_occurence(base))
	{
		if (nbr < 0)
		{
			write (1, "-", 1);
			counter++;
			p = -nbr;
		}
		else
			p = nbr;
		counter += ft_unsigned_nbr(p, base);
	}
	return (counter);
}
