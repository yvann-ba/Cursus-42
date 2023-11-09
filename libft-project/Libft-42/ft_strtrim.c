/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:08:41 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/09 10:25:51 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s_trim;

	i = 0;
	while (s1[i++])
	{
		j = 0;
		while (set[j++])
		{
			if (s1[i] = set[j])
		}
	}
}
#include <stdio.h>
int main()
{
	char const *s1 = "yvannlala";
	char const *set = 'a';

	printf("%s", ft_strtrim(s1, set));
}
