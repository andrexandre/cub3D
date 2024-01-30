
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

char *rm_path(char *line)
{
    char *result;
    char **sp;
    size_t i;
    size_t idxn;

    sp = ft_split(line, ' ');
    i = ft_strlen_matrix(sp);
    result = ft_strdup(sp[i - 1]);
    idxn = ft_strlen(result);
    result[idxn - 1] = '\0';
    ft_cleanup_strs(sp);
    return(result);
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
		{
			if (!ft_strncmp(line, "NO", 2))
				game->file->path_NO = rm_path(line);
			else if (!ft_strncmp(line, "SO", 2))
				game->file->path_SO = rm_path(line);
			else if (!ft_strncmp(line, "WE", 2))
				game->file->path_WE = rm_path(line);
			else if (!ft_strncmp(line, "EA", 2))
				game->file->path_EA = rm_path(line);
			else if (!ft_strncmp(line, "F", 1))
				game->file->color_floor = rm_path(line);
			else if (!ft_strncmp(line, "C", 1))
				game->file->color_ceiling = rm_path(line);
		}
	}
}

void	convert_lst_to_char(t_game *game)
{
	t_list	*lst;
	int		i;

	lst = game->file->map_lst;
	i = 0;
	game->file->map = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!game->file->map)
		error_msg("Error: Memory game->file->map[][]", game);
	while (lst)
	{
		game->file->map[i] = ft_strdup(lst->content);
		if (!game->file->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
}

void	build_map(char *map_path, t_game *game)
{
	int fd;

	check_map_extension(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_msg("Map not found", NULL);
	read_map(fd, game);
    convert_lst_to_char(game);
	close(fd);
}
