/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:12:08 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/09 09:35:27 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		s2 = malloc(1 * sizeof(char));
		if (s2 == NULL)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}