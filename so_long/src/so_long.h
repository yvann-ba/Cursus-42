/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:11:32 by yvann             #+#    #+#             */
/*   Updated: 2024/01/09 09:31:54 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define KEY_ESC 0xff1b

# include <stdio.h>
# include <stdlib.h>
# include "../libs/Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libs/mlx/mlx.h"

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

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

int		return_error(char *message);
void	*return_error_null(char *message);

void	draw_map(t_game *game);
void	draw_sprite(t_game *game, char c, int x, int y);
void	load_sprites(t_game *game);


int		init_graphics(t_game *game);
void	free_map(char **map, int height);
char	**get_map(char *argv_one, t_game *game);
int		is_map_valid(char **map, int height, int width);
t_pos	research_char(char **tab, t_pos start, char c, int height);
int		is_backtrack_exit_collectibles_valid(char **map, int height, int width);
int		research_exit_collectibles(char **map, t_pos player, \
char c, int height);
int		is_backtrack_exit_collectibles_valid(char **map, int height, int width);
char	**copy_map(char **original_map, int height, int width);
int		count_elements(char **map, int height, int width, char element);

int close_window(t_game *game);
int key_press(int keycode, t_game *game);

#endif