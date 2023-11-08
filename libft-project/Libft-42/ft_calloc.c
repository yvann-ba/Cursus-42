/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:54:15 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/08 11:21:58 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	full_size;
	void	*tab;

	full_size = nmemb * size;
	tab = malloc(full_size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, full_size);
	return (tab);
}
