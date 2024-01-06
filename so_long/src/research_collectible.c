/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:43:53 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/06 11:01:57 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player_position(t_collectible *collectibles, char **map, int width, int height)
{
	int x;
	int y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
			{
				collectibles->start_x = x;
				collectibles->start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void fill_collectibles_positions(t_collectible *collectibles, char **map, int width, int height)
{
	int x;
	int y;
	int i;
	
	i = 0;
	collectibles->position = malloc(sizeof(t_point) * count_elements(map, height, width, 'C'));
	if (collectibles->position == NULL)
		return ;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C')
			{
				collectibles->position[i].x = x;
				collectibles->position[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	backtrack_top(t_collectible *collectibles, char **map, int num_rows, int num_cols)
{
	int	result;

	result = 0;
	if (collectibles->start_y > 0)
	{
		collectibles->start_y -= 1;
		result = backtrack_to_exit(collectibles, map, num_rows, num_cols);
		collectibles->start_y += 1;
	}
	return (result);
}

int	backtrack_bottom(t_collectible *collectibles, char **map, int num_rows,
int num_cols)
{
	int	result;

	result = 0;
	if (collectibles->start_y < num_rows - 1)
	{
		collectibles->start_y += 1;
		result = backtrack_to_exit(collectibles, map, num_rows, num_cols);
		collectibles->start_y -= 1;
	}
	return (result);
}

int	backtrack_right(t_collectible *collectibles, char **map, int num_rows,
int num_cols)
{
	int	result;

	result = 0;
	if (collectibles->start_x < num_cols - 1)
	{
		collectibles->start_x += 1;
		result = backtrack_to_exit(collectibles, map, num_rows, num_cols);
		collectibles->start_x -= 1;
	}
	return (result);
}

int	backtrack_left(t_collectible *collectibles, char **map, int num_rows, int num_cols)
{
	int	result;

	result = 0;
	if (collectibles->start_x > 0)
	{
		collectibles->start_x -= 1;
		result = backtrack_to_exit(collectibles, map, num_rows, num_cols);
		collectibles->start_x += 1;
	}
	return (result);
}


int	backtrack_to_collectibles(t_collectible *collectibles, char **map, int num_rows,
int num_cols)
{
	int	result;

	if (collectibles->start_x == collectibles->exit_x
		&& collectibles->start_y == collectibles->exit_y)
		return (1);
	if (collectibles->start_x < 0 || collectibles->start_x >= num_cols
		|| collectibles->start_y < 0 || collectibles->start_y >= num_rows
		|| map[collectibles->start_y][collectibles->start_x] == '1'
		|| map[collectibles->start_y][collectibles->start_x] == '#')
		return (0);
	result = 0;
	map[collectibles->start_y][collectibles->start_x] = '#';
	result = backtrack_top(collectibles, map, num_rows, num_cols)
		|| backtrack_bottom(collectibles, map, num_rows, num_cols)
		|| backtrack_left(collectibles, map, num_rows, num_cols)
		|| backtrack_right(collectibles, map, num_rows, num_cols);
	map[collectibles->start_y][collectibles->start_x] = '0';
	return (result);
}
