/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:42:05 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/25 13:56:12 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	what_print(t_game *game, int line, int col);

void	render_map(t_game *game)
{
	int		line;
	int		col;
	char	*steps;

	steps = NULL;
	line = 0;
	while (line < game->map.line)
	{
		col = -1;
		while (col++ < game->map.colum)
			what_print(game, line, col);
		line++;
		if (game->end_game != 0)
			win_or_lose(game);
		print_steps(steps, game);
	}
}

void	win_or_lose(t_game *game)
{
	if (game->end_game == 1)
		mlx_string_put(game->mlx_pointer, game->window, 175, 10, 0xF0F8FF,
			"YOU WIN!! PRESS 'R' TO PLAY AGAIN OR 'ESC' TO EXIT!");
	else if (game->end_game == -1)
	{
		game->side = S;
		mlx_string_put(game->mlx_pointer, game->window, 175, 10, 0xF0F8FF,
			"WASTED, PRESS 'R' TO TRY ANOTHER WAY!!");
		mlx_put_image_to_window(game->mlx_pointer, game->window,
			game->img.player.wasted.img, game->map.player.x * TILES,
			game->map.player.y * TILES);
	}	
}

static void	what_print(t_game *game, int line, int col)
{
	t_pos	pos;
	int		x;
	int		y;

	x = col * TILES;
	y = line * TILES;
	pos.x = x;
	pos.y = y;
	if (game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.wall.img, x, y);
	else if (game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.empty.img, x, y);
	else if (game->map.map[line][col] == 'P')
		print_player(game, pos);
	else if (game->map.map[line][col] == 'E')
		print_exit(game, x, y);
	else if (game->map.map[line][col] == 'C')
		print_colect(game, x, y);
	else if (game->map.map[line][col] == 'V')
		print_enemy(game, x, y);
}	
