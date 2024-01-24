/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:24:52 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/24 12:49:49 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_nlist **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->number;
    second = (*stack_a)->next->number;
    third = (*stack_a)->next->next->number;

    if (first > second && second > third)
    {
        sa(stack_a);  // [3, 2, 1] -> [2, 3, 1]
        rra(stack_a); // [2, 3, 1] -> [1, 2, 3]
    }
    else if (first > second && first < third)
        sa(stack_a);  // [2, 1, 3] -> [1, 2, 3]
    else if (first > third && second < third)
        ra(stack_a);  // [3, 1, 2] -> [1, 2, 3]
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);  // [1, 3, 2] -> [3, 1, 2]
        ra(stack_a);  // [3, 1, 2] -> [1, 2, 3]
    }
    else if (first < third && second > third)
        rra(stack_a); // [2, 3, 1] -> [1, 2, 3]
	else if (first < second && first > third)
        rra(stack_a); // [2, 1, 3] -> [1, 2, 3]
}

// void sort_five(t_nlist **stack_a, t_nlist **stack_b)
// {
//     int min_index;

//     min_index = find_smallest(*stack_a);
//     while (min_index--)
//         ra(stack_a);
//     pb(stack_a, stack_b);
//     min_index = find_smallest(*stack_a);
//     while (min_index--)
//         ra(stack_a);
//     pb(stack_a, stack_b);

//     sort_three(stack_a);

//     pa(stack_a, stack_b);
//     pa(stack_a, stack_b);
// }

// int find_smallest(t_nlist *stack)
// {
//     int min_index = 0;
//     int min_value;
//     int i = 0;

//     if (stack == NULL)
//         return (-1);

//     min_value = stack->number;
//     stack = stack->next;

//     while (stack)
//     {
//         i++;
//         if (stack->number < min_value)
//         {
//             min_value = stack->number;
//             min_index = i;
//         }
//         stack = stack->next;
//     }
//     return (min_index);
// }