/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:09:50 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/12 19:00:12 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd, int total_lines, int count_colums, t_map *map)
{
	int		read_bytes;
	char	buffer;

	while (TRUE)
	{
		read_bytes = read (fd, &buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (FALSE);
		verify(check(buffer, map, total_lines, count_colums), map);
		if (buffer == '\n')
			total_lines++;
		if (buffer != '\n' && read_bytes > 0)
			count_colums++;
		if (map->last_usable_col == 0 && buffer == '\n')
			map->last_usable_col = count_colums - 1;
		if (map->last_usable_col != count_colums - 1
			&& (buffer == '\n' || read_bytes == 0))
			return (error("This map have less colum in some lines"));
		else if (buffer == '\n')
			count_colums = 0;
		if (read_bytes == 0)
			break ;
	}
	map->colum = map->last_usable_col + 1;
	return (total_lines);
}

int	what_lines(char *what_map, t_map *map)
{
	int	fd;
	int	init_col;
	int	lines;

	fd = open(what_map, O_RDONLY);
	if (fd == -1)
		return (error("invalid file"));
	lines = 1;
	init_col = 0;
	lines = count_lines(fd, lines, init_col, map);
	if (lines <= 0)
		return (error("this map is not valid!"));
	close (fd);
	return (lines);
}

char	**alocate_map(char *argmap, t_map *map)
{
	char	**map_str;

	map->line = what_lines(argmap, map);
	if (map->line <= 0)
		return (null_error("invalid map!"));
	if (map->validate <= 0)
		return (null_error("invalid map!"));
	if (map->line == map->colum)
		return (null_error("invalid map! Not is a rectangular"));
	map_str = malloc(sizeof(char *) * (map->line + 1));
	if (!map_str)
	{
		free(map_str);
		return (null_error("alocation is fault!"));
	}
	return (map_str);
}
