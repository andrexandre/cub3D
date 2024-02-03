/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:54:40 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/03 19:14:42 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_game *game)
{
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->image_b.img, 0,
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
int quit(void)
{
	// (void)game;
	mlx_destroy_image(gm()->mlx, gm()->image_b.img);
	mlx_destroy_window(gm()->mlx, gm()->win);
	mlx_destroy_display(gm()->mlx);
	free(gm()->mlx);
	exit(0);
}

void	hook(void)
{
	mlx_hook(gm()->win, KeyPress, KeyPressMask, keypress, gm());
	mlx_hook(gm()->win, 17, 0, quit, &gm);
	//mlx_hook(gm()->window, 17, 0, closing_game, gm());
	mlx_loop_hook(gm()->mlx, loop, gm());
	mlx_loop(gm()->mlx);
}
