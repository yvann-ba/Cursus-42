/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:02:13 by yvann             #+#    #+#             */
/*   Updated: 2024/02/06 10:45:02 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_new_line(char **backup)
{
	char	*line_end;
	char	*line;

	line_end = ft_strchr(*backup, '\n');
	if (line_end != NULL)
	{
		line = ft_strndup(*backup, line_end - *backup + 1);
	}
	else
	{
		line = ft_strdup(*backup);
	}
	return (line);
}

int	update_backup(char **backup, char *buf)
{
	char	*tmp;

	if (*backup)
		tmp = ft_strjoin(*backup, buf);
	else
		tmp = ft_strdup(buf);
	if (!tmp)
		return (-1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int	read_loop(int fd, char **backup, char *buf)
{
	int		bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (update_backup(backup, buf) == -1)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (bytes_read);
}

char	*read_from_fd(int fd, char **backup)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read_loop(fd, backup, buf);
	free(buf);
	if (bytes_read <= 0 && (!*backup || **backup == '\0'))
		return (NULL);
	return (*backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_from_fd(fd, &backup[fd]))
	{
		if (!backup[fd])
			return (NULL);
		line = handle_line(&backup[fd]);
		return (line);
	}
	line = handle_line(&backup[fd]);
	return (line);
}

