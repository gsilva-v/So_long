/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:15:27 by gabriel           #+#    #+#             */
/*   Updated: 2021/09/29 08:15:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify(int isvalid, t_map *map)
{
	if (map->validate == 1)
		map->validate = isvalid;
}

int check_c(char c, t_map *map, int line, int colum)
{
	if(c == 'P')
	{
		map->player.x = colum - 1;
		map->player.y = line;
		map->player_backup.x = colum - 1;
		map->player_backup.y = line;
		map->check.player += 1;
	}
    if(c == 'C')
		map->check.colect += 1;
    if(c == 'E')
		map->check.exit += 1;
    if(c == 'C' || c == 'E' || c == 'P' || c == 'V')
		return (1);
    return (0);
}

int	check_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int check(char c, t_map *map, int lin, int col)
{
	int isvalid = 1;
	
	// isvalid = check_c(c, map, lin, col);
	// if (isvalid == 0)
	// 	return (0);//alguma mensagem de erro que ainda nao criei
	// if (lin == 1 || col == 0)
	// 	isvalid = check_wall(c);
	// if (map->last_usable_col == col)
	// 	isvalid = check_wall(c);
	return (isvalid);
}

int check_cpe(t_map *map)
{
// 	if (map->check.player < 1)
// 		return(0);
// 	if (map->check.exit < 1)
// 		return(0);
// 	if (map->check.colect < 1)
// 		return(0);
	return (1);
}