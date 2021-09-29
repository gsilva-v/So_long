#include "../so_long.h"

void initial_struct(t_game *game)
{
    game->end_game = 0;
    game->init_game = 0;
    game->steps = 0;
    game->side = 0;
    game->reset = 0;
}

int main(int argc, char **argv)
{
    t_game game;

    initial_struct(&game);
    if(init_game(&game, argc, argv) != 1)
        return(0);
    mlx_loop(game.mlx_pointer);
    return (0);
}