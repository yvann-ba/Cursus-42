/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:31:10 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/02 15:33:03 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_empty(t_nlist *stack)
{
	return (stack == NULL);
}

int	get_stack_size(t_nlist *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	smart_rotate_b(t_nlist **stack_b, int index, int size)
{
	if (size > 1)
	{
		if (index <= size / 2)
		{
			while (index > 0)
			{
				rb(stack_b);
				index--;
			}
		}
		else
		{
			index = size - index;
			while (index > 0)
			{
				rrb(stack_b);
				index--;
			}
		}
	}
}
