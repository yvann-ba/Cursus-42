/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:18 by yvann             #+#    #+#             */
/*   Updated: 2023/12/15 13:29:58 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_dimensions calculate_dimensions(int fd)
{
    t_dimensions dim = {0, 0};
    char ch;
    int w;
    int res;

    w = 0;
    res = read(fd, &ch, 1);
    while (res > 0)
    {
        if (ch == '\n')
        {
            dim.height++;
            if (w > dim.width)
                dim.width = w;
            w = 0;
        }
        else
            w++;
    }
    return dim;
}

int	fill_map(int fd, char **map, int height, int width)
{
	char	ch;
	int		x;
	int		y;
	int		res;

	x = 0;
	y = 0;
	res = read(fd, &ch, 1);
	while ((res) > 0 && y < height)
	{
		if (ch == '\n')
		{
			map[y][x] = '\0';
			y++;
			x = 0;
		}
		else if (x < width)
		{
			map[y][x] = ch;
			x++;
		}
	}
	return (res >= 0);
}


char	**allocate_map(int height, int width)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * height);
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
		{
			while (i--)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static char **open_and_create_map(const char *file_path, t_dimensions *dim)
{
    int fd;
    char **map;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (NULL);
    }
    *dim = calculate_dimensions(fd);
    close(fd);
    map = allocate_map(dim->height, dim->width);
    return (map);
}


char **read_map_from_file(const char *file_path, t_dimensions *dim)
{
    int fd;
    char **map;

    map = open_and_create_map(file_path, dim);
    if (!map)
        return (NULL);

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error reopening file");
        free_map(map, dim->height); 
        return (NULL);
    }
    if (!fill_map(fd, map, dim->height, dim->width)) 
	{
        close(fd);
        free_map(map, dim->height); 
        return (NULL);
    }
    close(fd);
    return (map);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Usage: ./so_long map_file.ber\n", 31);
        return (1);
    }

    t_dimensions dim;
    char **map = read_map_from_file(argv[1], &dim);
    if (!map)
    {
        return (1);
    }
    if (is_map_valid(map, dim.height, dim.width) == 0)
        ft_printf("map valid");
    else
        ft_printf("map not valid");

    free_map(map, dim.height);

    return (0);
}
