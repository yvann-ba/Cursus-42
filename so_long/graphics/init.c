/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:37:45 by ybarbot           #+#    #+#             */
/*   Updated: 2023/12/22 13:48:50 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.img = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", 
		&width, &height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
		&width, &height);
	game->empty.img = mlx_xpm_file_to_image(game->mlx, "sprites/empty.xpm",
		&width, &height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, 
		"sprites/collectible.xpm", &width, &height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", 
		&width, &height);
	if (!game->player.img || !game->wall.img || !game->empty.img \
		|| !game->collectible.img || !game->exit.img)
		return_error("Error while loading sprites");
}