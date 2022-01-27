/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:01:01 by gabriel           #+#    #+#             */
/*   Updated: 2022/01/10 14:08:53 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->line)
	{
		free(map_str[i]);
		free(map->backup_map[i]);
		i++;
	}
	free(map_str);
	free(map->backup_map);
	map_str = NULL;
	map->backup_map = NULL;
}

void	make_backup_map(t_map *map, char **map_str)
{
	int	i;

	map->backup_map = malloc(sizeof(char *) * (map->line + 1));
	if (!map->backup_map)
	{
		free(map->backup_map);
		return ;
	}
	i = 0;
	while (i < map->line)
	{
		map->backup_map[i] = ft_strdup(map_str[i], map->backup_map[i]);
		i++;
	}
	map->backup_map[i] = NULL;
	map->colect = map->check.colect;
}

char	**save_map(char *what_map, t_map *the_map)
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
		return (null_error("alocation fail"));
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
