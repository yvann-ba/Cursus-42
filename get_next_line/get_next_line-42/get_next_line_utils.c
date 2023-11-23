/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:09:56 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/23 14:06:54 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*full_s;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	full_s = malloc (((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (full_s == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		full_s[i] = s1[i];
	j = -1;
	while (s2[++j])
		full_s[i++] = s2[j];
	full_s[i] = '\0';
	return (full_s);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
