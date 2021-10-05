/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:12:04 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/04 09:57:39 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int argc, char *what_map)
{
	if (argc != 2)
		return (error("Wrong argument!"));
	if (check_ber(what_map, ".ber") <= 0)
		return (error("Invalid map, not is '.ber'! Try another"));
	return (TRUE);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->line)
	{
		free(map_str[i]);
		free(map->backup_map[i]);
		i++;
	}
	free(map_str);
	free(map->backup_map);
}

void	make_backup_map(t_map *map, char **map_str)
{
	int	i;

	i = 0;
	map->backup_map = malloc(sizeof(char *) * map->line + 1);
	if (!map->backup_map)
	{
		free(map->backup_map);
		return ;
	}
	while (i < map->line)
	{
		map->backup_map[i] = ft_strdup(map_str[i]);
		i++;
	}	
	map->backup_map[i] = NULL;
	map->colect = map->check.colect;
}
