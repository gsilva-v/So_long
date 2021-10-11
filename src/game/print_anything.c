/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anything.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:01:50 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/11 14:05:46 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player(t_game *game, t_pos pos)
{
	if (game->side == W)
		mlx_put_image_to_window(game->mlx_pointer, game->window,
			game->img.player.up.img, pos.x, pos.y);
	else if (game->side == S)
		mlx_put_image_to_window(game->mlx_pointer, game->window,
			game->img.player.down.img, pos.x, pos.y);
	else if (game->side == D)
		mlx_put_image_to_window(game->mlx_pointer, game->window,
			game->img.player.right.img, pos.x, pos.y);
	else if (game->side == A)
		mlx_put_image_to_window(game->mlx_pointer, game->window,
			game->img.player.left.img, pos.x, pos.y);
}

void print_exit(t_game *game, int x, int y)
{
	if (game->map.check.colect == 0)	
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.exito.img, x, y);
	else
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.exitc.img, x, y);
}
void	print_colect(t_game *game,int x, int y)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->window, game->img.item.img, x, y);
}

void	print_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->window, game->img.enemy.img, x, y);
}

void	print_steps(char *steps, t_game *game)
{
		mlx_string_put(game->mlx_pointer, game->window, 550, 10, 0xF0F8FF,
			"ART BY MATRODRI");
		steps = ft_itoa(game->steps);
		mlx_string_put(game->mlx_pointer, game->window, 10, 10, 0xF0F8FF,
			"Current steps: " );
		mlx_string_put(game->mlx_pointer, game->window, 100, 10, 0xF0F8FF,
			steps);
		free(steps);
}