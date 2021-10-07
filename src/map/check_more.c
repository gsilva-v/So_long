/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:12:04 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/05 14:46:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int argc, char *what_map)
{
	if (argc != 2)
		return (error("Wrong argument!"));
	if (check_ber(what_map, ".ber") != 1)
		return (error("Invalid map, not is '.ber'! Try another"));
	return (TRUE);
}

int	check_ber(char *what_map, char *extension)
{
	int	len_map;
	int	len_ext;
	int	comp;

	comp = 0;
	len_map = ft_strlen(what_map);
	len_ext = ft_strlen(extension);
	while (len_ext > 0)
	{
		if (extension[--len_ext] == what_map[--len_map])
			comp++;
		else
			return (FALSE);
	}
	return (TRUE);
}

void	check_last_line(char *line, t_map *map)
{
	int	i;
	int	check;

	i = 0;
	while (i < map->last_usable_col)
	{
		if (line[i] == '1')
			i++;
		else
		{
			map->validate = 0;
			break ;
		}
	}
	check = check_pec(map);
	if (check == 0)
		map->validate = 0;
}
