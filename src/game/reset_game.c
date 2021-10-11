/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:43 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/05 16:22:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wasted_player(t_game *game)
{
	game->end_game = -1;
	game->steps = 0;

}

void	restart_game(t_game *game)
{
	use_backup_map(&game->map);
	game->map.player.x = game->map.player_backup.x;
	game->map.player.y = game->map.player_backup.y;
	game->end_game = 0;
	game->steps = 0;
	game->side = D;
	game->time_c = 0;
	game->time_e = 0;

}

int	use_backup_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->line)
		free(map->map[i++]);
	free(map->map);
	i = 0;
	map->map = malloc (sizeof(char *) * map->line + 1);
	if (!map->map)
	{
		free (map->map);
		return (FALSE);
	}
	while (i < map->line)
	{
		map->map[i] = ft_strdup(map->backup_map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->check.colect = map->colect;
	return (TRUE);
}
