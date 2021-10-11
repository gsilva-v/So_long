/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:28:58 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/11 14:11:29 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_draw	start_img(void *mlx)
{
	t_draw	img;

	init_colect(&img, mlx);
	init_player(&img, mlx);
	init_enemy(&img, mlx);
	init_exit(&img, mlx);
	init_wall(&img, mlx);
	return (img);
}

void	start_map(t_map *map)
{
	map->colum = 0;
	map->line = 0;
	map->validate = 1;
	map->last_usable_col = 0;
	map->check.colect = 0;
	map->check.exit = 0;
	map->check.player = 0;
	map->colect = 0;
}

char	**init_map(t_game *game, int argc, char **argv)
{
	char	**map;

	if (!check_arg(argc, argv[1]))
		return (FALSE);
	map = save_map(argv[1], &game->map);
	if (!map)
		return (FALSE);
	return (map);
}

int	init_game(t_game *game, int argc, char **argv)
{
	t_map	map;

	start_map(&map);
	game->map = map;
	game->map.map = init_map(game, argc, argv);
	if (game->map.map == NULL)
		return (ERROR);
	open_wind(game);
	game->img = start_img(game->mlx_pointer);
	game->side = S;
	render_map(game);
	game->init_game = 1;
	return (TRUE);
}
