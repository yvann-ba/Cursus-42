/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:53:51 by yvann             #+#    #+#             */
/*   Updated: 2024/01/05 13:51:06 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_elements(char **map, int height, int width, char element)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	check_elements(char **map, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (!(map[y][x] == '0' || map[y][x] == '1' || map[y][x] == 'C' \
			|| map[y][x] == 'E' || map[y][x] == 'P'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_upper_lower_walls(char **map, int width, int height)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

static int	check_side_walls(char **map, int height, int width)
{
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	is_map_valid(char **map, int height, int width)
{
	if (height < 3 || width < 3)
		return (return_error("Invalid map: Too small"));
	if (height == width)
		return (return_error("Invalid map: The map must be rectangular"));
	if (check_elements(map, height, width) == 1)
		return (return_error("Invalid map: Invalid element"));
	if (count_elements(map, height, width, 'E') != 1 \
	|| count_elements(map, height, width, 'C') < 1 \
	|| count_elements(map, height, width, 'P') != 1)
		return (return_error("Invalid map: Missing or too many elements"));
	if (check_upper_lower_walls(map, width, height) == 1 \
	|| check_side_walls(map, height, width) == 1)
		return (return_error("Invalid map: Missing walls"));
	is_backtrack_exit_valid(map, height, width);
	is_backtrack_collectible_valid(map, height, width);
	return (0);
}

int is_backtrack_exit_valid(char **map, int height, int width)
{
	t_map_info	map_info_exit;
	char		**map_copy;

	map_copy = copy_map(map, height, width);
	if (map_copy == NULL)
		return (return_error("Error: Unable to create map copy exit"));
	find_start_and_exit(&map_info_exit, map_copy, width, height);
	if (!backtrack_to_exit(&map_info_exit, map_copy, height, width))
		return (return_error("Invalid map: No path to exit"));
	free_map(map_copy, height);
	return (0);
}

int is_backtrack_collectible_valid(char **map, int height, int width)
{
	t_collectible	*collectibles;
	char			**map_copy;

	map_copy = copy_map(map, height, width);
	if (map_copy == NULL)
		return (return_error("Error: Unable to create map copy collectible"));
		
	find_player_position(&collectibles, map, width, height);
	
	find_collectibles_positions(&collectibles, map, width, height);
	// if (!backtrack_to_collectible(&collectibles, map_copy, height, width))
	// 	return (return_error("Invalid map: No path to collectible"));
	free_map(map_copy, height);
	return (0);
}
