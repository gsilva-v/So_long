#include "so_long.h"

int check_ber(char *what_map, char *extension)
{
    int len_map;
    int len_ext;
    int comp;
    
    comp = 0;
    len_map = ft_strlen(what_map);
    len_ext = ft_strlen(extension);
    while (len_ext > 0)
    {
        if (extension[--len_ext] == what_map[--len_map])
            comp++;
        else
            return (0);
    }
    return (1);
}
