/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:53:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/11 14:45:23 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_side(int keypress, t_game *game)
{
	if (keypress == W)
		game->side = W;
	if (keypress == D)
		game->side = D;
	if (keypress == A)
		game->side = A;
	if (keypress == S)
		game->side = S;
}

int	check_move(int keypress, t_game *game, int line, int col)
{
	if (game->map.map[line][col] == '1')
		return (ERROR);
	if (game->map.map[line][col] == 'E' && game->map.check.colect == 0)
		game->end_game = 1;
	if (game->map.map[line][col] == 'E')
		return (ERROR);
	if (game->end_game)
		return (ERROR);
	if (game->map.map[line][col] == 'V')
	{	
		wasted_player(game);
		return (ERROR);
	}
	if (keypress == W || keypress == S || keypress == D || keypress == A)
		return (TRUE);
	else
		return (ERROR);
}

void	move(int keypress, t_game *game, int line, int col)
{
	int	x;
	int	y;
	int	valid_move;

	x = game->map.player.x;
	y = game->map.player.y;
	valid_move = check_move(keypress, game, line, col);
	check_side(keypress, game);
	if (valid_move > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->map.check.colect--;
		game->map.map[y][x] = '0';
		game->map.map[line][col] = 'P';
		game->map.player.y = line;
		game->map.player.x = col;
		game->steps++;
	}
}

int	whatdo(int keypress, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keypress == ESC || keypress == Q)
		kill_window(game);
	if (keypress == W)
		line--;
	if (keypress == A)
		col--;
	if (keypress == S)
		line++;
	if (keypress == D)
		col++;
	if (keypress == RESET)
		restart_game(game);
	if (!game->end_game)
		move(keypress, game, line, col);
	return (TRUE);
}
