/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:50:27 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/23 09:46:16 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_duplicates(char **tab)
{
	int		i;
	int		j;
	char	*current_str;

	i = 0;
	while (tab[i])
	{
		current_str = tab[i];
		j = 0;
		while (current_str[j])
		{
			if (!ft_isdigit(current_str[j]))
				return (0);
			j++;
		}
		j = 0;
		while (tab[j])
		{
			if (j != i && ft_strcmp(tab[i], tab[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
