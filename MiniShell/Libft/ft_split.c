/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:18:45 by yvann             #+#    #+#             */
/*   Updated: 2023/12/14 10:17:51 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, n + 1);
	str[n] = '\0';
	return (str);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free_split(char **tab, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_split_words(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			if (!tab[k])
				return (NULL);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	if (!ft_split_words(s, c, tab))
	{
		ft_free_split(tab, ft_count_words(s, c));
		return (NULL);
	}
	return (tab);
}
