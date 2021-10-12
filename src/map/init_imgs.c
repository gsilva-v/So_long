/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:59:19 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/11 14:42:52 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_draw *img, void *mlx)
{
	img->player.up.img = mlx_xpm_file_to_image(mlx, PATH_PB,
			&img->player.up.size.x, &img->player.up.size.y);
	img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PF,
			&img->player.down.size.x, &img->player.down.size.y);
	img->player.left.img = mlx_xpm_file_to_image(mlx, PATH_PL,
			&img->player.left.size.x, &img->player.left.size.y);
	img->player.right.img = mlx_xpm_file_to_image(mlx, PATH_PR,
			&img->player.right.size.x, &img->player.right.size.y);
	img->player.wasted.img = mlx_xpm_file_to_image(mlx, PATH_PW,
			&img->player.wasted.size.x, &img->player.wasted.size.y);
}

void	init_colect(t_draw *img, void *mlx)
{
	img->item.img = mlx_xpm_file_to_image(mlx, PATH_C, &img->item.size.x,
			&img->item.size.y);
}

void	init_wall(t_draw *img, void *mlx)
{
	img->wall.img = mlx_xpm_file_to_image(mlx, PATH_W,
			&img->wall.size.x, &img->wall.size.y);
	img->empty.img = mlx_xpm_file_to_image(mlx, PATH_E, &img->empty.size.x,
			&img->empty.size.y);
}

void	init_enemy(t_draw *img, void *mlx)
{
	img->enemy.img = mlx_xpm_file_to_image(mlx, PATH_V, &img->enemy.size.x,
			&img->enemy.size.y);
}

void	init_exit(t_draw *img, void *mlx)
{
	img->exito.img = mlx_xpm_file_to_image(mlx, PATH_EXO, &img->exito.size.x,
			&img->exito.size.y);
	img->exitc.img = mlx_xpm_file_to_image(mlx, PATH_EXC, &img->exitc.size.x,
			&img->exitc.size.y);
}
