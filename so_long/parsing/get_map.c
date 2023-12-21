/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:18 by yvann             #+#    #+#             */
/*   Updated: 2023/12/21 14:37:45 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (1);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (1);
	return (0);
}

static char	*read_file_to_buffer(int fd)
{
	char	*line;
	char	*buf;
	char	*tmp;

	buf = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		buf = tmp;
		line = get_next_line(fd);
		if (buf == NULL)
			return (NULL);
	}
	return (buf);
}

static void	get_dimensions(char **map, t_dimensions *dim)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	dim->height = i;
	dim->width = j;
}

int	get_map(int argc, char **argv)
{
	char			**map;
	t_dimensions	dim;
	int				fd;
	char			*buf;

	if (argc != 2)
		return (return_error("Invalid number of arguments"));
	else
	{
		if (check_file_extension(argv[1]) == 1)
			return (return_error("Invalid file extension"));
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (return_error("Failed to open file"));
		buf = read_file_to_buffer(fd);
		map = ft_split(buf, '\n');
		free(buf);
		get_dimensions(map, &dim);
		if (is_map_valid(map, dim.height, dim.width) == 0)
			ft_printf("map valid");
		else
			return (return_error("Invalid map"));
	}
	return (0);
}
