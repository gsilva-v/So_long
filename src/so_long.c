/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:44:11 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/11 14:38:11 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initial_struct(t_game *game)
{
	game->end_game = 0;
	game->init_game = 0;
	game->steps = 0;
	game->side = 0;
	game->reset = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	initial_struct(&game);
	if (init_game(&game, argc, argv) != 1)
		return (FALSE);
	mlx_hook(game.window, 17, 0L, kill_window, (void *)&game);
	mlx_hook(game.window, 2, 1L << 0, whatdo, (void *)&game);
	mlx_loop_hook(game.mlx_pointer, refresh, &game);
	mlx_loop(game.mlx_pointer);
	return (0);
}
