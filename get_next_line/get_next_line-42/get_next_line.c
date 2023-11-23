/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:08:07 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/23 14:27:24 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_line(char *stash)
{
	if (ft_strchr(stash, '\n') != 0)
	
		return (stash);
}

char	*get_next_line(int fd)
{
	void		*buf;
	char		*stash;
	static char	*backup;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf == NULL)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	stash = ft_strjoin(stash, (char)buf);

	return (stash);
}
