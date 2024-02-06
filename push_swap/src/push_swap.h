/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:01 by ybarbot           #+#    #+#             */
/*   Updated: 2024/02/06 13:05:38 by ybarbot          ###   ########.fr       */
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

typedef struct s_moves
{
	int	moves_in_a;
	int	moves_in_b;
	int	total_moves;
	int	best_index;
	int	target_pos_in_a;
}	t_moves;

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
void	find_three_medians(t_nlist *stack, int size, int *medians);
void	split_into_four_chunks(t_nlist **stack_a, t_nlist **stack_b, int size);
void	process_chunk(t_nlist **stack_a, t_nlist **stack_b,
			int chunk_limit, int median);
void	process_remaining_values(t_nlist **stack_a, t_nlist **stack_b,
			int remaining);		
int		get_stack_size(t_nlist *stack);
int		is_only_whitespace(const char *str);
int		is_empty(t_nlist *stack);
void	sort_stack_a(t_nlist **stack_a, t_nlist **stack_b);
int		find_target_position(t_nlist *stack, int number);
t_moves	find_best_move(t_nlist *stack_a, t_nlist *stack_b);
t_moves	calculate_total_moves(t_nlist *stack_a, t_nlist *stack_b,
			int number, int index_in_b);
void	smart_rotate_b(t_nlist **stack_b, int index, int size);
int		has_leading_zeros(const char *str);
int check_num_duplicates(int *arr, int size);


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