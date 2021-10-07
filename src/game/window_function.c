/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:31:16 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/05 14:51:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_wind(t_game *game)
{
	game->mlx_pointer = mlx_init();
	game->window = mlx_new_window(game->mlx_pointer, game->map.colum * TILES,
			game->map.line * TILES, "so_long");
}

int	kill_window(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit (0);
}

int	refresh(t_game *game)
{
	if (game->reset < 10)
		game->reset += 0.0001;
	else if (game->end_game < 1)
	{
		mlx_clear_window(game->mlx_pointer, game->window);
		game->reset = 0;
	}
	render_map(game);
	return (0);
}
