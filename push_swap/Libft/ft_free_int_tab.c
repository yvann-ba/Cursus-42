/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:53:35 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/23 09:47:37 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_tab(int **tab, int size)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}
