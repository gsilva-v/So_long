/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:42:05 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/04 09:53:07 by gabriel          ###   ########.fr       */
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

void	what_print(t_game *game, int line, int col)
{
	t_pos	pos;
	int		x;
	int		y;

	x = col * TILES;
	y = line * TILES;
	pos.x = col * TILES;
	pos.y = line * TILES;
	if (game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.wall.img, x, y);
	else if (game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.empty.img, x, y);
	else if (game->map.map[line][col] == 'P')
		print_player(game, pos);
}	

void	print_another(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == 'E')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.exit.img, x, y);
	else if (game->map.map[line][col] == 'C')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.item.img, x, y);
	else if (game->map.map[line][col] == 'V')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.enemy.img, x, y);
}

void	render_map(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (line < game->map.line)
	{
		col = 0;
		while (col < game->map.colum)
		{
			what_print(game, line, col);
			print_another(game, line, col);
			col++;
		}
		line++;
		if (game->end_game == 1)
			mlx_string_put(game->mlx_pointer, game->window, 175, 160, 0xF0F8FF,
			"YOU WIN!! PRESS 'R' TO PLAY AGAIN OR 'ESC' TO EXIT!");
	}
}
