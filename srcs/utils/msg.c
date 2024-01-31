#include "cub3d.h"

void	error_msg(char *message, t_game *game)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	// end_game(game);
	exit(EXIT_FAILURE);
}
