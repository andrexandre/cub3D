/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:31:51 by jealves-          #+#    #+#             */
/*   Updated: 2024/01/31 19:31:55 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int	cub3d(char *map_path)
{
	build(map_path);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		return (cub3d(av[1]));
	else
		error_msg("Invalid Number of Arguments");
}
