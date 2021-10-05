#include "so_long.h"

void    restart_game(t_game *game)
{
	int i = 0;
	printf("reiniciando mapa\n");
	printf("mapa para reiniciar\n");
	while (game->map.map[i] != NULL)
		printf("%s", game->map.map[i++]);
	printf("\n");
	i =0;
	printf("mapa de backup\n");
	while (game->map.backup_map[i] != NULL)
		printf("%s", game->map.backup_map[i++]);
	printf("\n");
	use_backup_map(&game->map);
	printf("mapa reiniciado\n");
	i = 0;
	while (game->map.map[i] != NULL)
		printf("%s", game->map.map[i++]);
	printf("\n");
	printf("posição de backup\nx %d\ny %d\n", game->map.player_backup.x, game->map.player_backup.y);
	game->map.player.x = game->map.player_backup.x;
	game->map.player.y = game->map.player_backup.y;
	printf("nova posição do jogador\n%d x\n%d y\n",game->map.player.x, game->map.player.y);
	game->end_game = 0;
	game->steps = 0;
	game->side = D;
}

int    use_backup_map(t_map *map)
{
	int i;
	int	line;

	i = 0;
	while (i <= map->line)
		free(map->map[i++]);
	free(map->map);
	line = map->line;
	i = 0;
	map->map = malloc (sizeof(char *) * line + 1);
	if (!map->map)
		return (FALSE);
	while(i < line)
	{
		map->map[i] = ft_strdup(map->backup_map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->check.colect = map->colect;
	return (TRUE);
}