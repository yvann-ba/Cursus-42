/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:08:50 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/08 14:41:43 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (dst[i])
		i++;
	if (size <= i)
		return (size + ft_strlen((char *)src));
	j = 0;
	if (size > 0)
	{
		while (src[j] && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (i + ft_strlen((char *)src));
}
