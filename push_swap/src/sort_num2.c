/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:05:04 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/30 14:04:02 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void split_into_chunks(t_nlist **stack_a, t_nlist **stack_b, int size) 
{
	int median;
	int pushed_count;

	pushed_count = 0;
	median = find_median(*stack_a, size);
	while (pushed_count < size / 2)
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

int find_median(t_nlist *stack, int size)
{
	int *arr;
	int median;
	int i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (stack && i < size) {
		arr[i++] = stack->number;
		stack = stack->next;
	}
	sort_array(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

int is_sorted_desc(t_nlist *stack)
{
    while (stack && stack->next)
    {
        if (stack->number < stack->next->number)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void sort_stack_b(t_nlist **stack_b)
{
    int top; 
	int	next;

    while (!is_sorted_desc(*stack_b))
    {
        top = (*stack_b)->number;
        next = (*stack_b)->next->number;
        
        if (top < next)
            sb(stack_b);
        else if (should_rotate_b(*stack_b, find_max(*stack_b)))
            rb(stack_b);
        else if (should_reverse_rotate_b(*stack_b, find_max(*stack_b)))
            rrb(stack_b);
    }
}

int should_rotate_b(t_nlist *stack_b, int max)
{
    if (!stack_b || !stack_b->next)
        return (0);
    int top = stack_b->number;
    if (top != max) {
        t_nlist *temp = stack_b->next;
        while (temp) {
            if (temp->number == max) {
                return (1);
            }
            temp = temp->next;
        }
    }
    return (0);
}

int should_reverse_rotate_b(t_nlist *stack_b, int max) 
{
    if (!stack_b || !stack_b->next)
        return (0);
    t_nlist *temp = stack_b;
    while (temp->next)
        temp = temp->next;
    int bottom = temp->number;
    if (bottom == max) {
        temp = stack_b;
        while (temp && temp->number != max) 
		{
            if (temp->number < max) 
                return (1);
            temp = temp->next;
        }
    }
    return (0);
}

int find_max(t_nlist *stack)
{
    int max;

    max = stack->number;
    while (stack)
    {
        if (stack->number > max)
            max = stack->number;
        stack = stack->next;
    }
    return (max);
}
