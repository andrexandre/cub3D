
#include "cub3d.h"

bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01NSEW\t\n ", line[i]) || (i == 0 && line[i] == '\n'))
			return (false);
		i++;
	}
	return (true);
}

void	read_elements(char *line, t_game *game)
{
	char	*result;
	char	**sp;
	size_t	i;
	size_t	idxn;

	sp = ft_split(line, ' ');
	i = ft_strlen_matrix(sp);
	result = ft_strdup(sp[i - 1]);
	idxn = ft_strlen(result);
	result[idxn - 1] = '\0';
	if (!ft_strcmp(sp[0], "NO"))
		game->file->path_NO = result;
	else if (!ft_strcmp(sp[0], "SO"))
		game->file->path_SO = result;
	else if (!ft_strcmp(sp[0], "WE"))
		game->file->path_WE = result;
	else if (!ft_strcmp(sp[0], "EA"))
		game->file->path_EA = result;
	else if (!ft_strcmp(sp[0], "F"))
		game->file->color_floor = result;
	else if (!ft_strcmp(sp[0], "C"))
		game->file->color_ceiling = result;
	ft_cleanup_strs(sp);
}

void	read_map(int fd, t_game *game)
{
	char	*line;

	game->file = ft_calloc(sizeof(t_file), 1);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(line))
			ft_lstadd_back(&game->file->map_lst, ft_lstnew(line));
		else
			read_elements(line, game);
	}
}

void	build_map(char *map_path, t_game *game)
{
	int	fd;

	check_map_extension(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_msg("Map not found", NULL);
	read_map(fd, game);
	game->map = convert_lst_to_char(game->file->map_lst);
	game->map_checker = convert_lst_to_char(game->file->map_lst);
	close(fd);
}
