/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:31:03 by jealves-          #+#    #+#             */
/*   Updated: 2024/01/31 19:31:04 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	read_elements(char *line)
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
		game()->file->path_no = result;
	else if (!ft_strcmp(sp[0], "SO"))
		game()->file->path_so = result;
	else if (!ft_strcmp(sp[0], "WE"))
		game()->file->path_we = result;
	else if (!ft_strcmp(sp[0], "EA"))
		game()->file->path_ea = result;
	else if (!ft_strcmp(sp[0], "F"))
		game()->file->color_floor = result;
	else if (!ft_strcmp(sp[0], "C"))
		game()->file->color_ceiling = result;
	ft_cleanup_strs(sp);
}

void	read_file(int fd)
{
	char	*line;
	bool	map;

	game()->file = ft_calloc(sizeof(t_file), 1);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(line) || map)
		{
			ft_lstadd_back(&game()->file->map_lst, ft_lstnew(line));
			map = true;
		}
		else
			read_elements(line);
	}
}

void	build_file(char *map_path)
{
	int	fd;

	check_map_extension(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_msg("File not found");
	read_file(fd);
	close(fd);
	if (!game()->file->map_lst)
		error_msg("Cannot read map");
	game()->map = convert_lst_to_char(game()->file->map_lst);
	game()->map_checker = convert_lst_to_char(game()->file->map_lst);
}
