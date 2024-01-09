/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:44:03 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/09 11:07:28 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player.img = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", \
		&width, &height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", \
		&width, &height);
	game->empty.img = mlx_xpm_file_to_image(game->mlx, "sprites/empty.xpm", \
		&width, &height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, \
		"sprites/collectible.xpm", &width, &height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", \
		&width, &height);
	if (!game->player.img || !game->wall.img || !game->empty.img \
		|| !game->collectible.img || !game->exit.img)
		return_error("Error while loading sprites");
}

void	draw_sprite(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->wall.img, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->empty.img, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->collectible.img, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->exit.img, x * 64, y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player.img, x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_sprite(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (cleanup(game), return_error("Error initializing mlx"));
	game->win = mlx_new_window(game->mlx, 64 * game->width, \
	64 * game->height, "so_long");
	if (!game->win)
		return (cleanup(game), return_error("Error creating window"));
	load_sprites(game);
	draw_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop(game->mlx);
	return (0);
}
