/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:18 by yvann             #+#    #+#             */
/*   Updated: 2023/12/22 13:31:52 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (1);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (1);
	return (0);
}

static char	*read_file_to_buffer(int fd)
{
	char	*line;
	char	*buf;
	char	*tmp;

	buf = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		buf = tmp;
		line = get_next_line(fd);
		if (buf == NULL)
			return (NULL);
	}
	return (buf);
}

static void	get_dimensions(char **map, t_dimensions *dim)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	dim->height = i;
	dim->width = j;
}

char **get_map(char *argv_one)
{
	char			**map;
	t_dimensions	dim;
	int				fd;
	char			*buf;

	if (check_file_extension(argv_one) == 1)
		return(return_error_null("Invalid file extension"));
	fd = open(argv_one, O_RDONLY);
	if (fd == -1)
		return(return_error_null("Failed to open file"));
	buf = read_file_to_buffer(fd);
	map = ft_split(buf, '\n');
	free(buf);
	get_dimensions(map, &dim);
	if (is_map_valid(map, dim.height, dim.width) == 1)
	{
		free_map(map, dim.height);
		return(NULL);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	//char **map;
	if (argc != 2)
		return (return_error("Invalid number of arguments"));
	//map = 
	get_map(argv[1]);
	

	

	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);

	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							 &img.endian);
								 
	// my_mlx_pixel_put(&img, 1000, 5, 0x00FF0000);
	
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	
}