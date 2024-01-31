/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:01:27 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/31 13:52:20 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_best_move(t_nlist *stack_a, t_nlist *stack_b)
{
    int index = 0;
    int best_index = 0;
    int min_moves = INT_MAX;
    int current_moves;
    t_nlist *current = stack_b;

    while (current)
    {
        current_moves = calculate_total_moves(stack_a, stack_b, current->number, index);
        ft_printf("Index: %d, Number: %d, Moves: %d\n", index, current->number, current_moves);

        if (current_moves < min_moves)
        {
            min_moves = current_moves;
            best_index = index;
        }
        index++;
        current = current->next;
    }
    return best_index;
}

int calculate_total_moves(t_nlist *stack_a, t_nlist *stack_b, int number, int index_in_b)
{
    int moves_in_a = 0;
    int moves_in_b;
    int target_pos_in_a;
    int stack_a_size;

    moves_in_b = index_in_b < get_stack_size(stack_b) / 2 ? index_in_b : get_stack_size(stack_b) - index_in_b;

    target_pos_in_a = find_target_position(stack_a, number);
    stack_a_size = get_stack_size(stack_a);

    if (target_pos_in_a <= stack_a_size / 2)
        moves_in_a = target_pos_in_a;
    else
        moves_in_a = stack_a_size - target_pos_in_a;
    ft_printf("Number: %d, Target position in A: %d, Moves in A: %d, Moves in B: %d\n", number, target_pos_in_a, moves_in_a, moves_in_b);
    return moves_in_a + moves_in_b;
}


void sort_stack_a(t_nlist **stack_a, t_nlist **stack_b)
{
    while (!is_empty(*stack_b))
    {
        int best_move_index = find_best_move(*stack_a, *stack_b);
        smart_rotate(stack_b, best_move_index, get_stack_size(*stack_b));
        pa(stack_b, stack_a);
        ft_printf("Stack A after PA:\n");
        print_stack(*stack_a);
        ft_printf("Stack B after PA:\n");
        print_stack(*stack_b);
    }
}

int find_target_position(t_nlist *stack_a, int number)
{
    int position = 0;
    int stack_a_size = get_stack_size(stack_a);

    if (is_empty(stack_a) || number < stack_a->number)
        return 0;

    while (stack_a->next != NULL)
    {
        if (number > stack_a->number && number < stack_a->next->number)
        {
            return position + 1;
        }
        stack_a = stack_a->next;
        position++;
    }

    return stack_a_size - 1;
}

void	smart_rotate(t_nlist **stack, int index, int size)
{
	if (size > 1)
	{
		if (index < size / 2)
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
