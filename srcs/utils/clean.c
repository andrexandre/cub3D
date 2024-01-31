#include "cub3d.h"

void	ft_cleanup_strs(char **strs)
{
	size_t	idx;

	idx = 0;
	while (strs[idx])
		free(strs[idx++]);
	free(strs);
}
