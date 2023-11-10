/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:08:41 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/10 13:24:13 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (set == NULL || s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_char_in_set(s1[end], set))
		end--;
	if (end < start)
		return (malloc(0));
	s_trim = malloc((end - start) + 1);
	if (s_trim == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		s_trim[i] = s1[start];
		i++;
		start++;
	}
	s_trim[i] = '\0';
	return (s_trim);
}

