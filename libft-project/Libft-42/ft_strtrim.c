/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:08:41 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/10 12:26:22 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (s1[end] && char_in_set(s1[end], set))
		end--;
	s_trim = malloc((end - start) + 1);
	if (s_trim == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		s_trim[i] = s1[start];
		i++;
		start++;
	}
	s_trim[i] = '\0';
}

