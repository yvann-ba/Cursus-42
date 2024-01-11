/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:06:05 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/11 10:26:52 by ybarbot          ###   ########.fr       */
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
        game->move_up = 1;
    else if (keycode == KEY_DOWN)
        game->move_down = 1;
    else if (keycode == KEY_LEFT)
        game->move_left = 1;
    else if (keycode == KEY_RIGHT)
        game->move_right = 1;
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
