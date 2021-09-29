#include "so_long.h"

void open_wind(t_game *game)
{  

    game->mlx_pointer = mlx_init();
    game->window = mlx_new_window(game->mlx_pointer, game->map.colum * TILES,     
             game->map.line * TILES, "so_long");
   
}
