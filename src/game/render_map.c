/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:42:05 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/05 15:08:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	print_colect(t_game *game,int x, int y);
void	print_enemy(t_game *game, int x, int y);
static void print_exit(t_game *game, int x, int y);
static void win_or_lose(t_game *game);
static void	print_steps(char *steps, t_game *game);
static void	print_player(t_game *game, t_pos pos);
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

static void win_or_lose(t_game *game)
{
	if (game->end_game == 1)
		mlx_string_put(game->mlx_pointer, game->window, 175, 10, 0xF0F8FF,
			"YOU WIN!! PRESS 'R' TO PLAY AGAIN OR 'ESC' TO EXIT!");
	else if(game->end_game == -1)
	{
		mlx_string_put(game->mlx_pointer, game->window, 175, 10, 0xF0F8FF,
			"WASTED, PRESS 'R' TO TRY ANOTHER WAY!!");
		mlx_put_image_to_window(game->mlx_pointer, game->window,
			game->img.player.wasted.img, game->map.player.x * TILES,
				game->map.player.y * TILES);
	}	
}

static void	print_steps(char *steps, t_game *game)
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
void	print_colect(t_game *game,int x, int y)
{
	if (game->time_c == 100)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.item1.img, x, y);
	if (game->time_c == 700)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.item2.img, x, y);
	if (game->time_c == 1100)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.item3.img, x, y);
	game->time_c+=1;
	if(game->time_c == 1600)
		game->time_c = 10;

}

void	print_enemy(t_game *game, int x, int y)
{
	if (game->time_e == 100)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.enemy1.img, x, y);
	if (game->time_e == 300)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.enemy2.img, x, y);
	if (game->time_e == 600)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.enemy3.img, x, y);
	if (game->time_e == 800)
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.enemy4.img, x, y);
	game->time_e += 1;
	if (game->time_e == 1000)
		game->time_e = 10;
}

static void print_exit(t_game *game, int x, int y)
{
	if (game->map.check.colect == 0)	
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.exito.img, x, y);
	else
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->img.exitc.img, x, y);
}

static void	print_player(t_game *game, t_pos pos)
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
