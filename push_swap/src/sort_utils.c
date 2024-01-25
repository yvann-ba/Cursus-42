/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:31:10 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/25 13:01:30 by ybarbot          ###   ########.fr       */
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

void smart_rotate(t_nlist **stack, int index, int size)
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
