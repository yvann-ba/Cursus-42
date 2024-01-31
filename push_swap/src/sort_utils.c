/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:31:10 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/31 11:17:02 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_nlist *stack)
{
	t_nlist	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->number);
		current = current->next;
	}
}

void	smart_rotate(t_nlist **stack, int index, int size)
{
	if (size > 1)
	{
		if (index < size / 2)
		{
			while (index--)
				ra(stack);
		}
		else
		{
			while (index++ < size)
				rra(stack);
		}
	}
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
