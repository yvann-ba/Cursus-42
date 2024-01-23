/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:01 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/23 11:38:40 by ybarbot          ###   ########.fr       */
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
int		check_valid_duplicates(char **tab);
int		is_sorted(int *tab, int size);
t_nlist	*array_to_list(int *arr, int size);

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