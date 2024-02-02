/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:50:27 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/02 17:07:30 by ybarbot          ###   ########.fr       */
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
			if (ft_check_valid_number(&current_str[j]) == 0)
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

t_nlist	*array_to_list(int *arr, int size)
{
	t_nlist	*head;
	t_nlist	*new_node;
	int		i;

	head = NULL;
	i = 0;
	while (i < size)
	{
		new_node = ft_nlstnew(arr[i]);
		if (!new_node)
		{
			ft_nlstclear(&head);
			return (NULL);
		}
		ft_nlstadd_back(&head, new_node);
		i++;
	}
	return (head);
}

void	rrr(t_nlist **stack_a, t_nlist **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

int	is_only_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != '\v' && str[i] != '\f'
			&& str[i] != '\r')
			return (0);
		i++;
	}
	return (i > 0);
}
