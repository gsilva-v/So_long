/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:15:27 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/05 15:06:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify(int isvalid, t_map *map)
{
	if (map->validate == 1)
		map->validate = isvalid;
}

int	check_c(char c, t_map *map, int line, int colum)
{
	if (c == 'P')
	{
		map->player.x = colum;
		map->player.y = line - 1;
		map->player_backup.x = colum;
		map->player_backup.y = line - 1;
		map->check.player += 1;
	}
	if (c == 'C')
		map->check.colect += 1;
	if (c == 'E')
		map->check.exit += 1;
	if (c == 'C' || c == 'E' || c == 'P' || c == 'V' || c == '1' || c == '0')
		return (TRUE);
	return (FALSE);
}

int	check_wall(char c)
{
	if (c == '1')
		return (TRUE);
	else
		return (error("this map don't have all walls"));
}

int	check(char c, t_map *map, int lin, int col)
{
	int	isvalid;

	isvalid = check_c(c, map, lin, col);
	if (isvalid == 0 && c != '\n')
		return (error("this map have invalid caracters"));
	if ((lin == 1 || col == 0) && c != '\n')
		return (check_wall(c));
	if (map->last_usable_col == col && c != '\n')
		return (check_wall(c));
	return (TRUE);
}

int	check_pec(t_map *map)
{
	if (map->check.player < 1)
		return (error("the map must have at least 1 player"));
	if (map->check.player > 1)
		return (error("the map must have only 1 player"));
	if (map->check.exit < 1)
		return (error("the map must have at least 1 exit"));
	if (map->check.colect < 1)
		return (error("the map must have at least 1 colectable"));
	return (TRUE);
}
