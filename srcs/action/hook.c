/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:54:40 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/02 21:37:38 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_game *game)
{
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image_buffer.img, 0,
		0);
	return (EXIT_SUCCESS);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		msg("Fim");
		//end_game(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	hook(void)
{
	mlx_hook(game()->window, KeyPress, KeyPressMask, keypress, game());
	//mlx_hook(game()->window, 17, 0, closing_game, game());
	mlx_loop_hook(game()->mlx, loop, game());
	mlx_loop(game()->mlx);
}
