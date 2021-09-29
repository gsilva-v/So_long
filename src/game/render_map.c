#include "so_long.h"
void print_player(t_game *game, t_pos pos)
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
void what_print(t_game *game, int line, int col)
{
	t_pos pos;
	int x;
	int y;

	x = col * TILES;
	y = line * TILES;
	pos.x = x;
	pos.y = y;
	printf("\n\n\n\n%d x \n\n%d y\n\n\n\n\n", x, y);
	if (game->map.map[line][col] == 'P')
		print_player(game, pos);

	if (game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->mlx_pointer, game->window, game->img.empty.img, x, y);

	printf ("\nchegou aqui\n\n\n");

	if (game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window, game->img.wall.img, x, y);
	
	if (game->map.map[line][col] == 'E')
		mlx_put_image_to_window(game->mlx_pointer, game->window, game->img.exit.img, x, y);
	
	if (game->map.map[line][col] == 'C')
		mlx_put_image_to_window(game->mlx_pointer, game->window, game->img.item.img, x, y);
	
	if (game->map.map[line][col] == 'V')
		mlx_put_image_to_window(game->mlx_pointer, game->window, game->img.enemy.img, x, y);
}

void render_map(t_game *game)
{
    int line;
    int col;

    line = 0;
    while (line < game->map.line)
    {
        col = 0;
        while (col < game->map.colum)
		{
			what_print(game, game->map.line, game->map.colum);	
			col++;
		}
        line++;
    }
}