/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:11:32 by yvann             #+#    #+#             */
/*   Updated: 2023/12/22 11:11:32 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "libs/Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_dimensions
{
	int	width;
	int	height;
}	t_dimensions;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int			return_error(char *message);
void		*return_error_null(char *message);

void		free_map(char **map, int height);
char		**get_map(char *argv_one);
int			is_map_valid(char **map, int height, int width);

#endif