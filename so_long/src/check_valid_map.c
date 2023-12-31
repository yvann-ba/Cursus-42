/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:53:51 by yvann             #+#    #+#             */
/*   Updated: 2024/01/07 10:54:40 by ybarbot          ###   ########.fr       */
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
	is_backtrack_exit_collectibles_valid(map, height, width);
	return (0);
}
