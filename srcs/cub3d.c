/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:31:51 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/02 14:55:10 by analexan         ###   ########.fr       */
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
#define mapWidth 7
#define mapHeight 7
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight] =
{
  {1,1,1,1,1,1,1},
  {1,0,0,0,0,0,1},
  {1,0,0,0,0,0,1},
  {1,0,0,0,0,0,1},
  {1,0,0,0,0,0,1},
  {1,0,0,0,0,0,1},
  {1,1,1,1,1,1,1}
};

// int	main(int ac, char **av)
int	main(void)
{
	
	return (0);
	// if (ac == 2)
	// 	return (cub3d(av[1]));
	// else
	// 	error_msg("Invalid Number of Arguments");
}
