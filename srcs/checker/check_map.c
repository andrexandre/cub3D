
#include "cub3d.h"

void	check_map_extension(char *map_path)
{
	char	*extension;

	extension = ft_strchr(map_path, '.');
	if (extension == NULL)
		error_msg("Map extension invalid", NULL);
	if (ft_strcmp(extension, ".cub") != 0)
		error_msg("Map extension invalid", NULL);
}

void	check_wall(char **map, t_game *game)
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
	y = 0;
	while (map[y])
	{
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
		y++;
	}
}

void	check_map(t_game *game)
{
	check_wall(game->file->map, game);
}
