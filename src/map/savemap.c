#include "so_long.h"

char **gen_map_str(char *what_map)
{
    int fd;
    char **map_array;
    char *map_str;
    char *temp;
    char *aux;

    fd = open (what_map, O_RDONLY);
    map_str = ft_strdup("");
    while (true)
    {
        temp = get_next_line(fd);
        if(!temp)
            break;
        aux = map_str;
        map_str = ft_strjoin(aux,temp);
        free(temp);
        free(aux);
    }
    map_array = ft_split(map_str, '\n');
    close(fd);
    return (map_array);
}

char	**save_map(char *what_map, t_map *the_map)
{
    int fd;
    int lin;
    char **map_str;
    static int i;
    
    i = 0;
    map_str = alocate_map(what_map, the_map);
    if (!map_str)
    {
        free(map_str);
        return (NULL);
    }
    map_str = gen_map_str(what_map);
    the_map->validate = check_last_line(map_str[lin - 1], the_map);
    if (the_map->validate == 0)
    {
        free_map(map_str, the_map);
        return (NULL);
    }
    return(map_str);
}

