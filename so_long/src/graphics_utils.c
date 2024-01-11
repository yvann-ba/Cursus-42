/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:06:05 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/11 13:23:23 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        close_window(game);
    else if (keycode == KEY_UP)
        move_player_up(game);
    else if (keycode == KEY_DOWN)
        move_player_down(game);
    else if (keycode == KEY_LEFT)
        move_player_left(game);
    else if (keycode == KEY_RIGHT)
        move_player_right(game);
    return (0);
}

void	cleanup(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->empty.img);
	mlx_destroy_image(game->mlx, game->collectible.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, game->height);
}
