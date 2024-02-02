/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:30:46 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/02 21:38:19 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_player(int x, int y, char c)
{
	game()->player = ft_calloc(sizeof(t_player), 1);
	if (!game()->player)
		error_msg("Memory allocation - player");
	(game()->player->pos) = build_coord((double)y, (double)x);
	if (c == 'N')
	{
		(game()->player->dir) = build_coord((double)-1, (double)0);
		(game()->player->plane) = build_coord((double)0, (double)0.66);
	}
	else if (c == 'S')
	{
		(game()->player->dir) = build_coord((double)1, (double)0);
		(game()->player->plane) = build_coord((double)0, (double)-0.66);
	}
	else if (c == 'E')
	{
		(game()->player->dir) = build_coord((double)0, (double)1);
		(game()->player->plane) = build_coord((double)0.66, (double)0);
	}
	else if (c == 'W')
	{
		(game()->player->dir) = build_coord((double)0, (double)-1);
		(game()->player->plane) = build_coord((double)-0.66, (double)0);
	}
}

void	build_characters(void)
{
	int	x;
	int	y;

	y = 0;
	while (game()->map[y])
	{
		x = 0;
		while (game()->map[y][x])
		{
			if (game()->map[y][x] == 'N' || game()->map[y][x] == 'S'
				|| game()->map[y][x] == 'E' || game()->map[y][x] == 'W')
			{
				build_player(x, y, game()->map[y][x]);
				game()->nbr_player++;
			}
			x++;
		}
		y++;
	}
}
