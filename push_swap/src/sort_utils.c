/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:31:10 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/24 10:31:54 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_nlist *stack)
{
    t_nlist *current = stack;

    while (current != NULL)
    {
        ft_printf("%d\n", current->number);
        current = current->next;
    }
}