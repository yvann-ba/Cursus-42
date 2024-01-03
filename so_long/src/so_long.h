/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:11:32 by yvann             #+#    #+#             */
/*   Updated: 2024/01/03 13:43:49 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../libs/Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_sprite
{
	void	*img;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	player;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	collectible;
	t_sprite	exit;
	char		**map;
	int			width;
	int			height;
	void		*img;
}	t_game;

int			return_error(char *message);
void		*return_error_null(char *message);

void		draw_map(t_game *game);
void		load_sprites(t_game *game);
void		free_map(char **map, int height);
char		**get_map(char *argv_one, t_game *game);
int			is_map_valid(char **map, int height, int width);

#endif