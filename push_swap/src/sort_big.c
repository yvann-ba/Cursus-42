/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:01:27 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/02 15:33:15 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	find_best_move(t_nlist *stack_a, t_nlist *stack_b)
{
	int		index;
	t_nlist	*current;
	t_moves	best_moves;
	t_moves	current_moves;

	index = 0;
	best_moves.best_index = 0;
	best_moves.total_moves = INT_MAX;
	current = stack_b;
	while (current != NULL)
	{
		current_moves = calculate_total_moves(stack_a, stack_b,
				current->number, index);
		if (current_moves.total_moves < best_moves.total_moves)
			best_moves = current_moves;
		index++;
		current = current->next;
	}
	return (best_moves);
}

t_moves	calculate_total_moves(t_nlist *stack_a, t_nlist *stack_b,
			int number, int index_in_b)
{
	int		stack_a_size;
	int		stack_b_size;
	t_moves	moves;

	stack_a_size = get_stack_size(stack_a);
	stack_b_size = get_stack_size(stack_b);
	moves.best_index = index_in_b;
	moves.target_pos_in_a = find_target_position(stack_a, number);
	if (index_in_b <= stack_b_size / 2)
		moves.moves_in_b = index_in_b;
	else
		moves.moves_in_b = stack_b_size - index_in_b;
	if (moves.target_pos_in_a <= stack_a_size / 2)
		moves.moves_in_a = moves.target_pos_in_a;
	else
		moves.moves_in_a = stack_a_size - moves.target_pos_in_a;
	moves.total_moves = moves.moves_in_a + moves.moves_in_b;
	return (moves);
}

void	sort_stack_a(t_nlist **stack_a, t_nlist **stack_b)
{
	int		smallest;
	t_moves	moves;

	while (!is_empty(*stack_b))
	{
		moves = find_best_move(*stack_a, *stack_b);
		if (moves.moves_in_a > 0)
			smart_rotate(stack_a, moves.target_pos_in_a,
				get_stack_size(*stack_a));
		if (moves.moves_in_b > 0)
			smart_rotate_b(stack_b, moves.best_index, get_stack_size(*stack_b));
		pa(stack_a, stack_b);
	}
	smallest = find_smallest(*stack_a);
	while (smallest != 0)
	{
		ra(stack_a);
		smallest--;
	}
}

int	find_target_position(t_nlist *stack_a, int number)
{
	int		position;
	int		target_pos;
	int		target_value;
	t_nlist	*current;

	position = 0;
	target_pos = -1;
	target_value = INT_MAX;
	current = stack_a;
	while (current != NULL)
	{
		if (current->number > number && current->number < target_value)
		{
			target_pos = position;
			target_value = current->number;
		}
		current = current->next;
		position++;
	}
	if (target_pos == -1)
		target_pos = find_smallest(stack_a);
	return (target_pos);
}

void	smart_rotate(t_nlist **stack, int index, int size)
{
	if (size > 1)
	{
		if (index <= size / 2)
		{
			while (index > 0)
			{
				ra(stack);
				index--;
			}
		}
		else
		{
			index = size - index;
			while (index > 0)
			{
				rra(stack);
				index--;
			}
		}
	}
}
