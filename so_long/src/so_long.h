/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:11:32 by yvann             #+#    #+#             */
/*   Updated: 2024/01/04 11:53:32 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct s_map_info {
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
}	t_map_info;

int			return_error(char *message);
void		*return_error_null(char *message);

void		draw_map(t_game *game);
void		draw_sprite(t_game *game, char c, int x, int y);

void		load_sprites(t_game *game);
void		free_map(char **map, int height);
char		**get_map(char *argv_one, t_game *game);
int			is_map_valid(char **map, int height, int width);

int backtrack_conditions(t_map_info *map_info, char **map, int num_rows, int num_cols);
void	find_start_and_exit(t_map_info *map_info, char **map,
int width, int height);
int backtrack_to_exit(t_map_info *map_info, char **map, int num_rows, int num_cols); 




#endif