/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:53:51 by yvann             #+#    #+#             */
/*   Updated: 2023/12/14 14:12:42 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"

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
	if (count_elements(map, height, width, 'E') != 1 \
	|| count_elements(map, height, width, 'C') < 1 \
	|| count_elements(map, height, width, 'P') != 1)
	{
		ft_printf("Error\nInvalid map: incorrect E, C or P\n");
		return (1);
	}
	if (check_upper_lower_walls(map, width, height) == 1 \
	|| check_side_walls(map, height, width) == 1)
	{
		ft_printf("Error\nInvalid map: Missing walls\n");
		return (1);
	}
	return (0);
}



