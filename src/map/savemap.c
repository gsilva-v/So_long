/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:01:01 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/01 12:59:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**save_map(char *what_map, t_map *the_map, t_game *game)
{
	int		fd;
	char	**map_str;
	int		i;

	i = 0;
	fd = open(what_map, O_RDONLY);
	if (fd == -1)
		return (null_error("invalid file"));
	map_str = alocate_map(what_map, the_map);
	if (!map_str)
	{
		free(map_str);
		return (null_error("alocation fail"));
	}
	while (i < the_map->line)
		map_str[i++] = get_next_line(fd);
	map_str[i] = NULL;
	check_last_line(map_str[i - 1], the_map);
	make_backup_map(the_map, map_str);
	if (the_map->validate == 0)
	{
		free_map(map_str, the_map);
		return (null_error("this map have any error"));
	}
	close(fd);
	return (map_str);
}
