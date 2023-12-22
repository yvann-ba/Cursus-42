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
	game->player.img = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->player.width, &game->player.height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &game->wall.width, &game->wall.height);
	game->empty.img = mlx_xpm_file_to_image(game->mlx, "sprites/empty.xpm", &game->empty.width, &game->empty.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, "sprites/collectible.xpm", &game->collectible.width, &game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &game->exit.width, &game->exit.height);
	if (!game->player.img || !game->wall.img || !game->empty.img || !game->collectible.img || !game->exit.img)
		return_error("Error while loading sprites");
}