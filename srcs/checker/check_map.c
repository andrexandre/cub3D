#include "cub3d.h"

void	check_first_last_line(char **map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' && map[0][x] != ' ' && map[0][x] != '\n')
			error_msg("erro primeira linha", game);
		x++;
	}
	x = 0;
	y = ft_strlen_matrix(map) - 1;
	while (map[y][x])
	{
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
			error_msg("erro ultima linha", game);
		x++;
	}
}

void	check_first_column(char **map, t_game *game, int y)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == ' ')
		{
			x++;
			continue ;
		}
		if (map[y][x] != '1')
			error_msg("erro primeira coluna", game);
		break ;
	}
}

void	check_last_column(char **map, t_game *game, int y)
{
	int	x;

	x = ft_strlen(map[y]) - 1;
	while (map[y][x])
	{
		if (map[y][x] == ' ' || map[y][x] == '\n')
		{
			x--;
			continue ;
		}
		if (map[y][x] != '1')
			error_msg("erro ultima coluna", game);
		break ;
	}
}

void	check_middle_line(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		check_first_column(map, game, y);
		check_last_column(map, game, y);
		y++;
	}
}

void	check_map(t_game *game)
{
	check_first_last_line(game->map, game);
	check_middle_line(game->map, game);
	floodfill(game->map_checker, game);
}
