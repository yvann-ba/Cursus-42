/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_backtrack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:42:52 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/07 10:42:54 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_go_position(char **tab, t_pos player, t_pos dest);

static int	is_obstacle(char **tab, t_pos player)
{
	if (tab[player.y][player.x] == '1')
		return (1);
	else
		return (0);
}

t_pos	research_char(char **tab, t_pos start, char c, int height)
{
	t_pos	find;
	int		x;
	int		y;

	find.y = -1;
	find.x = -1;
	y = start.y;
	while (y < height && tab[y] != NULL)
	{
		x = start.x;
		while (tab[y][x] != '\0' && x < (int)ft_strlen(tab[y]))
		{
			if (tab[y][x] == c)
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

static int	can_go_position(char **tab, t_pos player, t_pos dest)
{
	if (player.x < 0 || player.y < 0 || tab[player.y] == NULL
		|| tab[player.y][player.x] == '\0'
			|| tab[player.y][player.x] == 'X')
		return (-1);
	if (is_obstacle(tab, player))
		return (-1);
	if ((player.x == dest.x) && (player.y == dest.y))
	{
		tab[player.y][player.x] = '#';
		return (1);
	}
	tab[player.y][player.x] = 'X';
	if (can_go_position(tab, (t_pos){player.x - 1, player.y}, dest) != -1
		|| can_go_position(tab, (t_pos){player.x + 1, player.y}, dest) != -1
		|| can_go_position(tab, (t_pos){player.x, player.y - 1}, dest) != -1
		|| can_go_position(tab, (t_pos){player.x, player.y + 1}, dest) != -1)
	{
		tab[player.y][player.x] = 'I';
		return (1);
	}
	tab[player.y][player.x] = '0';
	return (-1);
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
		start.x = destination.x + 1;
		start.y = destination.y;
	}
	return (1);
}
