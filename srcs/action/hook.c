/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:54:40 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/02 21:55:00 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_game *game)
{
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image_buffer.img, 0,
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
	mlx_hook(gm()->win, KeyPress, KeyPressMask, keypress, gm());
	//mlx_hook(gm()->window, 17, 0, closing_game, gm());
	mlx_loop_hook(gm()->mlx, loop, gm());
	mlx_loop(gm()->mlx);
}
