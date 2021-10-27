/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:31:16 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/25 13:57:10 by gsilva-v         ###   ########.fr       */
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
	mlx_destroy_image(game->mlx_pointer, game->img.wall.img);
	mlx_destroy_image(game->mlx_pointer, game->img.exito.img);
	mlx_destroy_image(game->mlx_pointer, game->img.exitc.img);
	mlx_destroy_image(game->mlx_pointer, game->img.player.up.img);
	mlx_destroy_image(game->mlx_pointer, game->img.player.down.img);
	mlx_destroy_image(game->mlx_pointer, game->img.player.wasted.img);
	mlx_destroy_image(game->mlx_pointer, game->img.player.right.img);
	mlx_destroy_image(game->mlx_pointer, game->img.player.left.img);
	mlx_destroy_image(game->mlx_pointer, game->img.item.img);
	mlx_destroy_image(game->mlx_pointer, game->img.enemy.img);
	free(game->mlx_pointer);
	exit (0);
	return (0);
}

int	refresh(t_game *game)
{
	if (game->reset < 20)
		game->reset += 0.0001;
	else if (game->end_game < 1)
	{
		mlx_clear_window(game->mlx_pointer, game->window);
		game->reset = 0;
	}
	render_map(game);
	return (0);
}
