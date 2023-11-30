/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:09:56 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/29 09:31:25 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_line(char **backup)
{
	char	*line;
	char	*line_end;
	char	*new_backup;

	line = create_new_line(backup);
	line_end = ft_strchr(*backup, '\n');
	if (line_end != NULL && *(line_end + 1) != '\0')
	{
		new_backup = ft_strdup(line_end + 1);
		free(*backup);
		*backup = new_backup;
	}
	else
	{
		free(*backup);
		*backup = NULL;
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*full_s;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	full_s = malloc ((i + j + 1) * sizeof(char));
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
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strndup(char *s, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	while (s[i] && i < len)
		i++;
	s2 = malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		s2[j] = s[j];
		j++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*s2;

	i = 0;
	while (s[i])
		i++;
	s2 = malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
