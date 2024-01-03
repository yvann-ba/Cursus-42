/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:44:03 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/03 13:43:19 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void draw_map(t_game *game)
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
