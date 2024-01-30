
#include "cub3d.h"

int cub3d(char *map_path)
{
	t_game game;
	build(map_path, &game);
	return(1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		return (cub3d(av[1]));
	else
		error_msg("Invalid Number of Arguments", NULL);
}