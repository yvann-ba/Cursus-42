/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:13:06 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/24 12:50:03 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int *nb_tab;
    int tab_len;

	nb_tab = NULL;
    tab_len = parsing(argc, argv, &nb_tab);
    if (tab_len != 0)
    {
        execute_push_swap(nb_tab, tab_len);
    }
	else
		free(nb_tab);
    return (0);
}

int execute_push_swap(int *nb_tab, int tab_len)
{
    t_nlist *stack_a;
    t_nlist *stack_b;

    stack_a = array_to_list(nb_tab, tab_len);
	free(nb_tab);
    if (stack_a == NULL)
    {
        ft_putendl_fd("Error");
        return (0);
    }
    stack_b = NULL;
    if (tab_len == 3)
	{
    	sort_three(&stack_a);
		print_stack(stack_a);
	}
    //else if (tab_len == 5)
    //{
	   //sort_five(&stack_a, &stack_b);
	   //print_stack(stack_a);
	//}
    //else
    //    sort(&stack_a, &stack_b, tab_len);
    ft_nlstclear(&stack_a);
    ft_nlstclear(&stack_b);
	return (1);
}
