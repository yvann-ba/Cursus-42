/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:50:44 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/25 13:36:59 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_nlist **stack_a)
{
	t_nlist	*tmp;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		ft_printf("sa\n");
	}
}

void	sb(t_nlist **stack_b)
{
	t_nlist	*tmp;

	if (stack_b && *stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		ft_printf("sb\n");
	}
}

void	ss(t_nlist **stack_a, t_nlist **stack_b)
{
	t_nlist	*tmp;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}

	ft_printf("ss\n");
}

void	pa(t_nlist **stack_a, t_nlist **stack_b)
{
	t_nlist	*tmp;

	if (stack_b && *stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		ft_printf("pa\n");
	}
}

void	pb(t_nlist **stack_a, t_nlist **stack_b)
{
	t_nlist	*tmp;

	if (stack_a && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		ft_printf("pb\n");
	}
}
