/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:12:37 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/04 12:02:42 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_start_and_exit(t_map_info *map_info, char **map,
int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
			{
				map_info->start_x = x;
				map_info->start_y = y;
			}
			if (map[y][x] == 'E')
			{
				map_info->exit_x = x;
				map_info->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

int	backtrack_top(t_map_info *map_info, char **map, int num_rows, int num_cols)
{
	int	result;

	map_info->start_x -= 1;
	result = backtrack_to_exit(map_info, map, num_rows, num_cols);
	map_info->start_x += 1;
	return (result);
}
int	backtrack_bottom(t_map_info *map_info, char **map, int num_rows, int num_cols)
{
	int	result;

	map_info->start_x += 1;
	result = backtrack_to_exit(map_info, map, num_rows, num_cols);
	map_info->start_x -= 1;
	return (result);
}
int	backtrack_left(t_map_info *map_info, char **map, int num_rows, int num_cols)
{
	int	result;

	map_info->start_y -= 1;
	result = backtrack_to_exit(map_info, map, num_rows, num_cols);
	map_info->start_y += 1;
	return (result);
}
 
int	backtrack_right(t_map_info *map_info, char **map, int num_rows, int num_cols)
{
	int	result;

	map_info->start_y += 1;
	result = backtrack_to_exit(map_info, map, num_rows, num_cols);
	map_info->start_y -= 1;
	return (result);
}

int backtrack_to_exit(t_map_info *map_info, char **map, int num_rows, int num_cols) 
{
    int result;

    map[map_info->start_x][map_info->start_y] = '#';

    result = backtrack_top(map_info, map, num_rows, num_cols) || 
             backtrack_bottom(map_info, map, num_rows, num_cols) || 
             backtrack_left(map_info, map, num_rows, num_cols) || 
             backtrack_right(map_info, map, num_rows, num_cols);

    map[map_info->start_x][map_info->start_y] = '0';
    return result;
}

int backtrack_conditions(t_map_info *map_info, char **map, int num_rows, int num_cols) 
{
    if (map_info->start_x == map_info->exit_x && map_info->start_y == map_info->exit_y)
        return 1;
    if (map_info->start_x < 0 || map_info->start_x >= num_rows || 
        map_info->start_y < 0 || map_info->start_y >= num_cols || 
        map[map_info->start_x][map_info->start_y] == '1' || 
        map[map_info->start_x][map_info->start_y] == '#')
        return 0;

    return backtrack_to_exit(map_info, map, num_rows, num_cols);
}


