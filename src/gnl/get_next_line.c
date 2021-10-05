/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:04:06 by gabriel           #+#    #+#             */
/*   Updated: 2021/09/30 17:35:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readleftstr(int fd, char *left_str)
{
	char	*buffer;
	int		read_byte;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_byte = 1;
	while (!ft_strchrgnl(left_str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1 )
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		left_str = ft_strjoingnl(left_str, buffer);
	}	
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[256];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	left_str[fd] = ft_readleftstr(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_line(left_str[fd]);
	left_str[fd] = ft_newleft(left_str[fd]);
	if (line[0] == '\0')
	{
		free(left_str[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
