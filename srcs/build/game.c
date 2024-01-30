
#include "cub3d.h"

void build(char *map_path, t_game *game)
{
    build_map(map_path, game);
    check_map(game);
}
