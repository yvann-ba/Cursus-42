/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:43:53 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/06 09:39:16 by ybarbot          ###   ########.fr       */
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
