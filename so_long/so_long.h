/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:11:32 by yvann             #+#    #+#             */
/*   Updated: 2023/12/21 14:39:47 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "libs/Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_dimensions
{
	int	width;
	int	height;
}	t_dimensions;

int		return_error(char *message);
void	free_map(char **map, int height);
int		get_map(int argc, char **argv);
int		is_map_valid(char **map, int height, int width);

#endif