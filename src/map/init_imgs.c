#include "so_long.h"

void init_player(t_draw *img, void *mlx)
{
    img->player.up.img = mlx_xpm_file_to_image(mlx, PATH_PB, &img->player.up.size.x, &img->player.up.size.y);
    img->player.up.pixels = mlx_get_data_addr(img->player.up.img, &img->player.up.bytes_per_pixel, &img->player.up.line_size, &img->player.up.endian);
    img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PF, &img->player.down.size.x, &img->player.down.size.y);
    img->player.down.pixels = mlx_get_data_addr(img->player.down.img, &img->player.down.bytes_per_pixel, &img->player.down.line_size, &img->player.down.endian);
    img->player.left.img = mlx_xpm_file_to_image(mlx, PATH_PL, &img->player.left.size.x, &img->player.left.size.y);
    img->player.left.pixels = mlx_get_data_addr(img->player.left.img, &img->player.left.bytes_per_pixel, &img->player.left.line_size, &img->player.left.endian);
    img->player.right.img = mlx_xpm_file_to_image(mlx, PATH_PR, &img->player.right.size.x, &img->player.right.size.y);
    img->player.right.pixels = mlx_get_data_addr(img->player.right.img,&img->player.right.bytes_per_pixel, &img->player.right.line_size, &img->player.right.endian);
}

void init_colect(t_draw *img, void *mlx)
{
    img->item.img = mlx_xpm_file_to_image(mlx, PATH_C, &img->item.size.x, &img->item.size.y);
    img->item.pixels = mlx_get_data_addr(img->item.img, &img->item.bytes_per_pixel, &img->item.line_size, &img->item.endian);
}

void init_wall(t_draw *img, t_game *game)
{
    // img->wall.img = mlx_xpm_file_to_image(mlx, PATH_W,
    //         &img->wall.size.x, &img->wall.size.y);
    // img->wall.pixels = mlx_get_data_addr(img->wall.img,
    //         &img->wall.bytes_per_pixel, &img->wall.line_size,
    //         &img->wall.endian);
    img->empty.img = mlx_xpm_file_to_image(game->mlx_pointer, PATH_E, &img->empty.size.x,
            &img->empty.size.y);
    
    printf ("\n\n\nchegou aqui\n\n\n%d x \n%d y\n",img->empty.size.x, img->empty.size.y);
    
    img->empty.pixels = mlx_get_data_addr(img->empty.img,
            &img->empty.bytes_per_pixel, &img->empty.line_size, 
            &img->empty.endian);
}

void init_enemy(t_draw *img, void *mlx)
{
    img->enemy.img = mlx_xpm_file_to_image(mlx, PATH_V, &img->enemy.size.x, &img->enemy.size.y);
    img->enemy.pixels = mlx_get_data_addr(img->enemy.img, &img->enemy.bytes_per_pixel, &img->enemy.line_size, &img->enemy.endian);
}

void init_exit(t_draw *img, void *mlx)
{
    img->exit.img = mlx_xpm_file_to_image(mlx, PATH_EX, &img->exit.size.x, &img->exit.size.y);
    img->exit.pixels = mlx_get_data_addr(img->exit.img, &img->exit.bytes_per_pixel, &img->exit.line_size, &img->exit.endian);
}