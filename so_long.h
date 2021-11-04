/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:39:32 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/04 17:09:49 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILES 50
# define PATH_W "./imgs/wall.xpm"
# define PATH_E "./imgs/empty.xpm"
# define PATH_EXO "./imgs/exit_open.xpm"
# define PATH_EXC "./imgs/exit_close.xpm"
# define PATH_PW "./imgs/player_wasted.xpm"
# define PATH_PF "./imgs/player_front.xpm"
# define PATH_PB "./imgs/player_back.xpm"
# define PATH_PR "./imgs/player_right.xpm"
# define PATH_PL "./imgs/player_left.xpm"
# define PATH_C "./imgs/collect.xpm"
# define PATH_V "./imgs/enemy.xpm"
# define ESPACE 0x20
# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b
# define Q 0x71
# define RESET 0x72
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define BUFFER_SIZE 1
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "./src/gnl/get_next_line.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_check_map
{
	int	player;
	int	colect;
	int	exit;
}	t_check;

typedef struct s_map
{
	char	**map;
	char	**backup_map;
	t_pos	player;
	t_pos	player_backup;
	t_check	check;
	int		line;
	int		colum;
	int		last_usable_col;
	int		validate;
	int		colect;
}			t_map;

typedef struct s_data
{
	void	*img;
	t_pos	size;
}	t_data;

typedef struct s_view
{
	t_data	up;
	t_data	down;
	t_data	left;
	t_data	right;
	t_data	wasted;
}	t_view;

typedef struct s_draw
{
	t_data	wall;
	t_data	empty;
	t_data	exito;
	t_data	exitc;
	t_view	player;
	t_data	item;
	t_data	enemy;
}	t_draw;

typedef struct s_game
{
	void	*mlx_pointer;
	void	*window;
	t_map	map;
	t_draw	img;
	int		end_game;
	int		steps;
	int		init_game;
	double	reset;
	int		side;
}		t_game;

/*Utils*/
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s, char *save_str);
char	*ft_itoa(int n);

/*função de erro*/
int		error(char *s);
void	*null_error(char *s);

/*funções para o mapa*/

void	verify(int isvalid, t_map *map);
int		check(char c, t_map *map, int lin, int col);
int		check_arg(int argc, char *what_map);
int		check_ber(char *what_map, char *extension);
int		check_c(char c, t_map *map, int line, int colum);
void	check_last_line(char *line, t_map *map);
int		check_pec(t_map *map);
int		check_wall(char c);
char	**save_map(char *what_map, t_map *the_map);
char	**alocate_map(char *argmap, t_map *map);
int		what_lines(char *what_map, t_map *map);
int		count_lines(int fd, int total_lines, int count_colums, t_map *map);
void	make_backup_map(t_map *map, char **map_str);
void	free_map(char **map_str, t_map *map);

/*funções para nova janela*/
int		kill_window(t_game *game);
void	open_wind(t_game *game);
int		refresh(t_game *game);

/*funções de movimentação*/
int		check_move(int keypress, t_game *game, int line, int col);
void	check_side(int keypress, t_game *game);
void	move(int keypress, t_game *game, int line, int col);
int		whatdo(int keypress, t_game *game);

/*funções para reinicio*/
void	restart_game(t_game *game);
void	wasted_player(t_game *game);
int		use_backup_map(t_map *map);

/*Funções de inicialização de mapa*/
int		init_game(t_game *game, int argc, char **argv);
void	initial_struct(t_game *game);
void	start_map(t_map *map);
char	**init_map(t_game *game, int argc, char **argv);

/*Funções de renderização*/
t_draw	start_img(void *mlx);
void	init_player(t_draw *img, void *mlx);
void	init_colect(t_draw *img, void *mlx);
void	init_exit(t_draw *img, void *mlx);
void	init_enemy(t_draw *img, void *mlx);
void	init_wall(t_draw *img, void *mlx);
void	render_map(t_game *game);
void	print_enemy(t_game *game, int x, int y);
void	win_or_lose(t_game *game);
void	print_steps(char *steps, t_game *game);
void	print_colect(t_game *game, int x, int y);
void	print_enemy(t_game *game, int x, int y);
void	print_exit(t_game *game, int x, int y);
void	print_player(t_game *game, t_pos pos);

#endif