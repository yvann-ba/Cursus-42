/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:13:06 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/06 13:06:17 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nb_tab;
	int	tab_len;
	int	i;

	i = 1;
	nb_tab = NULL;
	while (i < argc)
	{
		if (argv[i] == NULL || ft_strlen(argv[i]) == 0
			|| is_only_whitespace(argv[i]))
		{
			ft_putendl_fd("Error");
			return (0);
		}
		i++;
	}
	tab_len = parsing(argc, argv, &nb_tab);
	if (tab_len != 0)
	{
		execute_push_swap(nb_tab, tab_len);
	}
	else
		free(nb_tab);
	return (0);
}

int check_num_duplicates(int *arr, int size) 
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
	{
        j = i + 1;
        while (j < size) 
		{
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static	void	sort_stack_based_on_size(t_nlist **stack_a,
			t_nlist **stack_b, int tab_len)
{
	if (tab_len == 2)
		sort_two(stack_a);
	else if (tab_len == 3)
		sort_three(stack_a);
	else if (tab_len == 4)
		sort_four(stack_a, stack_b, tab_len);
	else if (tab_len == 5)
		sort_five(stack_a, stack_b, tab_len);
	else
	{
		split_into_four_chunks(stack_a, stack_b, tab_len);
		sort_three(stack_a);
		sort_stack_a(stack_a, stack_b);
	}
}

int	execute_push_swap(int *nb_tab, int tab_len)
{
	t_nlist	*stack_a;
	t_nlist	*stack_b;

	stack_a = array_to_list(nb_tab, tab_len);
	free(nb_tab);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error");
		return (0);
	}
	stack_b = NULL;
	sort_stack_based_on_size(&stack_a, &stack_b, tab_len);
	ft_nlstclear(&stack_a);
	ft_nlstclear(&stack_b);
	return (1);
}
