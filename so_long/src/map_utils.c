/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:05 by yvann             #+#    #+#             */
/*   Updated: 2024/01/05 10:37:54 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_error(char *message)
{
	ft_printf("Error : %s\n", message);
	return (1);
}

void	*return_error_null(char *message)
{
	ft_printf("Error : %s\n", message);
	return (NULL);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **original_map, int height, int width)
{
	int		y;
	char	**new_map;

	new_map = (char **)ft_calloc(height, sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	y = 0;
	while (y < height)
	{
		new_map[y] = (char *)ft_calloc(width + 1, sizeof(char));
		if (new_map[y] == NULL)
		{
			while (--y >= 0)
				free(new_map[y]);
			free(new_map);
			return (NULL);
		}
		ft_strcpy(new_map[y], original_map[y]);
		y++;
	}
	return (new_map);
}

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
