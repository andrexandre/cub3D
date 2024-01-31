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

void	check_file(t_file *file, t_game *game)
{
	if (!file)
		error_msg("Cannot read file", game);
	if (!file->path_no || !ft_strlen(file->path_no))
		error_msg("Without NO texture", game);
	if (!file->path_so || !ft_strlen(file->path_so))
		error_msg("Without SO texture", game);
	if (!file->path_we || !ft_strlen(file->path_we))
		error_msg("Without WE texture", game);
	if (!file->path_ea || !ft_strlen(file->path_ea))
		error_msg("Without EA texture", game);
	if (!file->color_ceiling || !ft_strlen(file->color_ceiling))
		error_msg("Without ceiling color", game);
	if (!file->color_floor || !ft_strlen(file->color_floor))
		error_msg("Without floor color", game);
	if (!file->map_lst)
		error_msg("Cannot read map", game);
	game->map = convert_lst_to_char(file->map_lst);
	game->map_checker = convert_lst_to_char(file->map_lst);
}

void	check(t_game *game)
{
	check_file(game->file, game);
	check_map(game);
}
