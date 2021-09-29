#include "so_long.h"

int check_last_line(char *line, t_map *map)
{
	int i;
	int check;

	i = 0;
	while (i < map->last_usable_col)
	{
		if (line[i] =='1')
			i++;
		else
		{
			map->validate = 0;
			break;
		}
	}
	check = check_cpe(map);
	return(check);
}

int count_lines(int fd, int total_lines, int count_colums, t_map *map)
{
    int read_bytes;
    char buffer;
	
    while (true)
    {
		read_bytes = read (fd, &buffer, 1);
		if (read_bytes == -1)
			return (0);
		verify(1, map);//check(buffer, map, total_lines, count_colums) colocar no lugar do 1
		if (buffer == '\n')
			total_lines++;
		if (buffer != '\n' && read_bytes > 0)
			count_colums++;
		if (map->last_usable_col == 0 && buffer == '\n')
		{
			map->last_usable_col = count_colums - 1;
			map->colum = count_colums;
		}
		if (map->last_usable_col != count_colums -1 && (buffer == '\n' || read_bytes == 0))
			return (0);
		else if (buffer == '\n')
			count_colums = 0;
		if (read_bytes == 0)
			break; 
    }
	map->colum = map->last_usable_col + 1;
    return (total_lines);
}

int what_lines(char *what_map, t_map *map)
{
	int	fd;
	int	init_col;
	int lines;

	lines = 1;
	init_col = 0;
	fd = open(what_map, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = count_lines(fd, lines, init_col, map);
	if (lines <= 0)
		return (0);
	close (fd);
	return (lines);
}

char **alocate_map(char *argmap, t_map *map)
{
	char **map_str;

	map->line = what_lines(argmap, map);
	if (map->line <= 0)
		return (NULL);
	if (map->validate <= 0)
		return (NULL);
	map_str = malloc(sizeof(char *) * map->line + 1);
	if (!map_str)
	{
		free(map_str);
		return (NULL);
	}
	return (map_str);
}