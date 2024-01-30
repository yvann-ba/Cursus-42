/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:01 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/30 13:43:34 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

int		return_error(char *str);
int		parsing(int argc, char **argv, int **nb_tab);
int		execute_push_swap(int *nb_tab, int tab_len);
int		check_valid_duplicates(char **tab);
int		is_sorted(int *tab, int size);
t_nlist	*array_to_list(int *arr, int size);
void	sort_two(t_nlist **stack_a);
void	sort_three(t_nlist **stack_a);
void	sort_four(t_nlist **stack_a, t_nlist **stack_b, int size);
void	sort_five(t_nlist **stack_a, t_nlist **stack_b, int size);
void	sort(t_nlist **stack_a, t_nlist **stack_b, int tab_len);
void	print_stack(t_nlist *stack);
int		find_smallest(t_nlist *stack);
void	smart_rotate(t_nlist **stack, int index, int size);
void	sort_array(int *arr, int size);
int		find_median(t_nlist *stack, int size);
void	split_into_chunks(t_nlist **stack_a, t_nlist **stack_b, int size);
int		is_sorted_desc(t_nlist *stack);
void	sort_stack_b(t_nlist **stack_b);
int should_rotate_b(t_nlist *stack_b, int max);
int should_reverse_rotate_b(t_nlist *stack_b, int max);
int find_max(t_nlist *stack);

void	sa(t_nlist **stack_a);
void	sb(t_nlist **stack_b);
void	ss(t_nlist **stack_a, t_nlist **stack_b);
void	pa(t_nlist **stack_a, t_nlist **stack_b);
void	pb(t_nlist **stack_a, t_nlist **stack_b);
void	ra(t_nlist **stack_a);
void	rb(t_nlist **stack_b);
void	rr(t_nlist **stack_a, t_nlist **stack_b);
void	rra(t_nlist **stack_a);
void	rrb(t_nlist **stack_b);
void	rrr(t_nlist **stack_a, t_nlist **stack_b);

#endif