/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:18 by yvann             #+#    #+#             */
/*   Updated: 2024/01/16 11:18:48 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (buf == NULL)
		exit(0);
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

static void	get_dimensions(char **map, t_game *game)
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
	game->height = i;
	game->width = j;
}

char	**ftc_split(char const *s, char c);

char	**get_map(char *argv_one, t_game *game)
{
	char			**map;
	int				fd;
	char			*buf;

	if (check_file_extension(argv_one) == 1)
	{
		return_error("Invalid file extension");
		return (NULL);
	}
	fd = open(argv_one, O_RDONLY);
	if (fd == -1)
		return (return_error_null ("Failed to open file"));
	buf = read_file_to_buffer(fd);
	map = ft_split(buf, '\n');
	free(buf);
	if (!map)
		exit(0);
	get_dimensions(map, game);
	if (is_map_valid(map, game->height, game->width, game) == 1)
	{
		free_map(map, game->height);
		return (NULL);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		return_error("Invalid number of arguments");
		return (1);
	}
	game.map = get_map(argv[1], &game);
	if (game.map == NULL)
		return (1);
	init_graphics(&game);
	return (0);
}
