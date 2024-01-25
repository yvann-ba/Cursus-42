/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:22 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/25 13:38:57 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_nlist **stack_a)
{
	t_nlist	*first;
	t_nlist	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		last = ft_nlstlast(*stack_a);
		last->next = first;
		first->next = NULL;
		ft_printf("ra\n");
	}
}

void	rb(t_nlist **stack_b)
{
	t_nlist	*first;
	t_nlist	*last;

	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		last = ft_nlstlast(*stack_b);
		last->next = first;
		first->next = NULL;
		ft_printf("rb\n");
	}
}

void	rr(t_nlist **stack_a, t_nlist **stack_b)
{
	t_nlist	*first;
	t_nlist	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		last = ft_nlstlast(*stack_a);
		last->next = first;
		first->next = NULL;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		last = ft_nlstlast(*stack_b);
		last->next = first;
		first->next = NULL;
	}

	ft_printf("rr\n");
}

void	rra(t_nlist **stack_a)
{
	t_nlist	*last;
	t_nlist	*before_last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		if (before_last)
			before_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		ft_printf("rra\n");
	}
}

void	rrb(t_nlist **stack_b)
{
	t_nlist	*last;
	t_nlist	*before_last;

	if (stack_b && *stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		if (before_last)
			before_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	ft_printf("rrb\n");
}
