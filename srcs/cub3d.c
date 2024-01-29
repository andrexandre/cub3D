#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		return (1);//cub3d(av[1]));
	else
		ft_printf("Error: Invalid Number of Arguments %s", av[0]);
}