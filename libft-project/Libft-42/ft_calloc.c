/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:54:15 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/09 15:00:09 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	full_size;
	size_t size_max;
	void	*tab;

	size_max = 0xFFFFFFFFFFFFFFFF;	
	if (nmemb == 0 || size == 0)
    	nmemb = size = 1;
	if (size && nmemb > size_max / size)
		return (NULL);
	else
		full_size = nmemb * size;
	tab = malloc(full_size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, full_size);
	return (tab);
}
