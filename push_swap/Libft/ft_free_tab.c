/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:05:20 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/19 13:02:39 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(void **tab, int height)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < height)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		
		i++;
	}
	free(tab);
	tab = NULL;
}
