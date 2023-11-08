/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:00:53 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/08 08:42:52 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"   

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	is_present;

	if (little[0] == '\0' || len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && i + j < len)
		{
			if (little[j] != big[j + i])
			{
				is_present = 0;
				break ;
			}
			is_present = 1;
			j++;
		}
		if (is_present == 1 && little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
