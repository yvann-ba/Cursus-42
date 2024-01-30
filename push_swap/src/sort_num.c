/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:24:52 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/30 11:05:36 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_nlist **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		sa(stack_a);
	}
}

void	sort_three(t_nlist **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first < third)
		sa(stack_a);
	else if (first > third && second < third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < third && second > third)
		rra(stack_a);
	else if (first < second && first > third)
		rra(stack_a);
}

void	sort_four(t_nlist **stack_a, t_nlist **stack_b, int size)
{
	int	min_index;

	min_index = find_smallest(*stack_a);
	smart_rotate(stack_a, min_index, size);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_nlist **stack_a, t_nlist **stack_b, int size)
{
	int	min_index;

	min_index = find_smallest(*stack_a);
	smart_rotate(stack_a, min_index, size--);
	pb(stack_a, stack_b);
	min_index = find_smallest(*stack_a);
	smart_rotate(stack_a, min_index, size--);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	find_smallest(t_nlist *stack)
{
	int	min_index;
	int	min_value;
	int	i;

	i = 0;
	min_index = 0;
	if (stack == NULL)
		return (-1);
	min_value = stack->number;
	stack = stack->next;
	while (stack)
	{
		i++;
		if (stack->number < min_value)
		{
			min_value = stack->number;
			min_index = i;
		}
		stack = stack->next;
	}
	return (min_index);
}
