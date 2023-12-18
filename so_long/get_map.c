/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:18 by yvann             #+#    #+#             */
/*   Updated: 2023/12/15 13:29:58 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_dimensions(int fd, int *height, int *max_width)
{
	char	ch;
	int		h;
	int		w;

	h = 1;
	w = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			h++;
			if (w > *max_width)
				*max_width = w;
			w = 0;
		}
		else
			w++;
	}
	*height = h;
}

int	fill_map(int fd, char **map, int height, int width)
{
	char	ch;
	int		x;
	int		y;
	int		res;

	x = 0;
	y = 0;
	res = read(fd, &ch, 1);
	while ((res) > 0 && y < height)
	{
		if (ch == '\n')
		{
			map[y][x] = '\0';
			y++;
			x = 0;
		}
		else if (x < width)
		{
			map[y][x] = ch;
			x++;
		}
	}
	return (res >= 0);
}


char	**allocate_map(int height, int width)
{
	char	**map;
	int		i;

	*map = malloc(sizeof(char *) * height);
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
		{
			while (i--)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static char	**open_and_create_map(const char *file_path, int *h, int *max_width)
{
	int		fd;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	calculate_dimensions(fd, h, max_width);
	close(fd);
	map = allocate_map(*h, *max_width);
	return (map);
}

char	**read_map_from_file(const char *file_path, int *height, int *width)
{
	int		fd;
	char	**map;

	map = open_and_create_map(file_path, height, width);
	if (!map)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error reopening file");
		free_map(map, *height);
		return (NULL);
	}
	if (!fill_map(fd, map, *height, *width))
	{
		close(fd);
		free_map(map, *height);
		return (NULL);
	}
	close(fd);
	return (map);
}
