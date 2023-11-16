/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_ubase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:24 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/16 16:14:01 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_character_occurence(char *base)
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

static int	ft_check_parameters(char *base)
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

static int	unsigned_nbr(unsigned int nbr, char *base)
{
	unsigned int		i;
	unsigned int		digit;

	i = 0;
	while (base[i])
		i++;
	digit = nbr / i;
	nbr = nbr / i;
	if (nbr)
		unsigned_nbr(nbr, base);
	write(1, &base[digit], 1);
}

unsigned ft_putlnbr_ubase(unsigned int nbr, char *base)
{
	unsigned counter;

	counter = 0;
	if (ft_check_parameters(base) && ft_check_character_occurence(base))
	{
		counter = unsigned_nbr(nbr, base);
	}
	return (counter);
}
