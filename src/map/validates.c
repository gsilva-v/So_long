#include "so_long.h"

int check_arg(int argc, char *what_map)
{
    if (argc == 1)
        return (0);
    //if (argc > 2)
      //  alguma mensagem;
    if (check_ber(what_map, ".ber") <= 0)
        return(0);
    return (1);
}

void free_map(char **map_str, t_map *map)
{
    int i;

    i = 0;
    while (i <= map->line)
    {
        free(map_str[i]);
        free(map->backup_map[i]);
        i++;
    }
    free(map_str);
    free(map->backup_map);
}

void make_backup_map(t_map *map, char **map_str)
{
    int i;

    i = 0;
    map->backup_map = malloc(sizeof(char *) * map->line + 1);
    if (!map->backup_map)
    {
        free(map->backup_map);
        return ;
    }
    while (i < map->line)
    {
        map->backup_map[i] = ft_strdup(map_str[i]);
        i++;
    }
    map->backup_map[i] = NULL;
    map->colect = map->check.colect;
}