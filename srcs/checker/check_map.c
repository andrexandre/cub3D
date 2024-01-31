
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

bool vaild_map_char(char c)
{
	if(c != ' ' && c != '\n')
		return true;
	return false;
}

void fill(int y, int x, char **map, int size_y, int size_x)
{
	if(map[y][x] == ' ' || map[y][x] == '1'  || map[y][x] == 'I' ||
	  map[y][x] == 'V' || y < 0 || x < 0 || y >= size_y || x >= size_x)
		return;
	if(vaild_map_char(map[y + 1][x - 1]) && 
		vaild_map_char(map[y][x - 1]) && 
		vaild_map_char(map[y - 1][x - 1]) &&
		vaild_map_char(map[y + 1][x + 1]) && 
		vaild_map_char(map[y][x + 1]) && 
		vaild_map_char(map[y - 1][x + 1]) &&
		vaild_map_char(map[y + 1][x]) && 
		vaild_map_char(map[y - 1][x]))
		map[y][x] = 'V';
	else
		map[y][x] = 'I';
	fill(y+1,x,map,size_y,size_x);
	fill(y,x+1,map,size_y,size_x);
	fill(y-1,x,map,size_y,size_x);
	fill(y,x-1,map,size_y,size_x);
}

void check_floodfill(char **map, t_game *game)
{
	int x;
	int size_x;
	int y;
	int size_y;
	
	y = 0;
	size_y = ft_strlen_matrix(map);
	while (y < size_y)
	{
		x = 0;
		size_x = ft_strlen(map[y]);
		while (x < size_x)
		{
			if(map[y][x] == 'I')
			{
				error_msg("erro estrutura invalida", game);
			}
			x++;
		}
		y++;
	}
}
void floodfill(char **map, t_game *game)
{
	int x;
	int size_x;
	int y;
	int size_y;
	
	y = 0;
	size_y = ft_strlen_matrix(map);
	while (y < size_y)
	{
		x = 0;
		size_x = ft_strlen(map[y]);
		while (x < size_x)
		{
			if(map[y][x] == '0')
			{
				fill(y,x,map,size_y,size_x);
			}
			x++;
		}
		y++;
	}
	check_floodfill(map,game);
}

void	check_map(t_game *game)
{
	check_wall(game->map, game);
	floodfill(game->map_checker, game);
}
