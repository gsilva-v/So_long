#include "so_long.h"

int	error(char *s)
{
	printf("\033[1;31mError: %s\n\033[0m", s);
	return (0);
}

void	*null_error(char *s)
{
	printf("\033[1;31mError: %s\n\033[0m", s);
	return (0);
}