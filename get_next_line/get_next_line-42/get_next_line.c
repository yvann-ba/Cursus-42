/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:08:07 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/22 13:13:07 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	void *buf;
	static char *stash;
	
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while(i != '\n')
	{
		if (read(fd, buf, BUFFER_SIZE ) == 0)
			break;
		j = 0;
		stash[i] = buf [i]
	}
	return (stash);
}
