/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_backtrack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:42:52 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/12 00:34:13 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_go_position(char **map, t_pos player, t_pos dest);

static char	**clean_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
	return (map);
}

t_pos	research_char(char **map, t_pos start, char c, int height)
{
	t_pos	find;
	int		x;
	int		y;

	find.y = -1;
	find.x = -1;
	y = start.y;
	while (y < height && map[y] != NULL)
	{
		x = start.x;
		while (map[y][x] != '\0' && x < (int)ft_strlen(map[y]))
		{
			if (map[y][x] == c)
			{
				find.y = y;
				find.x = x;
				return (find);
			}
			x++;
		}
		y++;
		start.x = 0;
	}
	return (find);
}

static int	can_go_position(char **map, t_pos player, t_pos dest)
{
	if ((player.x == dest.x) && (player.y == dest.y))
	{
		map[player.y][player.x] = '#';
		return (1);
	}
	if (player.x < 0 || player.y < 0 || map[player.y] == NULL
		|| map[player.y][player.x] == '\0'
			|| map[player.y][player.x] == 'X'
			|| map[player.y][player.x] == '1'
			|| map[player.y][player.x] == 'E')
		return (0);
	map[player.y][player.x] = 'X';
	return (can_go_position(map, (t_pos){player.x - 1, player.y}, dest) != -1
		|| can_go_position(map, (t_pos){player.x + 1, player.y}, dest) != -1
		|| can_go_position(map, (t_pos){player.x, player.y - 1}, dest) != -1
		|| can_go_position(map, (t_pos){player.x, player.y + 1}, dest) != -1);
}

int	research_exit_collectibles(char **cpy_map, t_pos player, char c, int height)
{
	t_pos	start;
	t_pos	destination;

	start.y = 0;
	start.x = 0;
	while (1)
	{
		destination = research_char(cpy_map, start, c, height);
		if (destination.x == -1 && destination.y == -1)
			break ;
		if (can_go_position(cpy_map, player, destination) == -1)
			return (-1);
		cpy_map = clean_map(cpy_map);
		start.x = destination.x + 1;
		start.y = destination.y;
	}
	free_map(cpy_map, height);
	return (1);
}
