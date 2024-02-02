/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:03:02 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/02 15:07:44 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_into_four_chunks(t_nlist **stack_a, t_nlist **stack_b, int size)
{
	int	medians[3];
	int	chunk_limit;
	int	i;

	find_three_medians(*stack_a, size, medians);
	chunk_limit = (size - 3) / 4;
	i = 0;
	while (i < 3)
	{
		process_chunk(stack_a, stack_b, chunk_limit, medians[i]);
		i++;
	}
	process_remaining_values(stack_a, stack_b, size - (chunk_limit * 3) - 3);
}

void	process_chunk(t_nlist **stack_a, t_nlist **stack_b,
int chunk_limit, int median)
{
	int	pushed_count;

	pushed_count = 0;
	while (pushed_count < chunk_limit)
	{
		if ((*stack_a)->number <= median)
		{
			pb(stack_a, stack_b);
			pushed_count++;
		}
		else
			ra(stack_a);
	}
}

void	process_remaining_values(t_nlist **stack_a,
t_nlist **stack_b, int remaining)
{
	while (remaining > 0)
	{
		pb(stack_a, stack_b);
		remaining--;
	}
}

void	find_three_medians(t_nlist *stack, int size, int *medians)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	while (stack && i < size)
	{
		arr[i] = stack->number;
		i++;
		stack = stack->next;
	}
	sort_array(arr, size);
	medians[0] = arr[size / 4];
	medians[1] = arr[size / 2];
	medians[2] = arr[(3 * size) / 4];
	free(arr);
}
