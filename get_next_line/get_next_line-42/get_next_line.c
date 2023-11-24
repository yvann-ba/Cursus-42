/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:08:07 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/24 14:22:31 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_line(char **backup, char *buf)
{
	char *line_end;
	char *line;
	char *new_backup;
	size_t len;
	
	line_end = ft_strchr(buf, '\n');
	if (line_end != NULL)
	{
		len = line_end - buf;
		line = ft_strldup(buf, len);
		new_backup = ft_strdup(line_end + 1);
		free (*backup);
		*backup = new_backup;
		return (line);
	}
	else
	{
		line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			bytes_read;
	static char	*backup;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc (BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	line = NULL;
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (backup)
		{
			tmp = ft_strjoin(backup, buf);
			free(backup);
			backup = tmp;
		}
		else
			backup = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	if (bytes_read < 0)
	{
		free(buf);
		return (NULL);
	}
	line = handle_line(&backup, backup);
	
	free(buf);
	return (line);
}
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;
	void(argc);
	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));

	close(fd);
}