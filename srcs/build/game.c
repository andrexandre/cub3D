/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:31:10 by jealves-          #+#    #+#             */
/*   Updated: 2024/01/31 21:06:11 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_mlx_itens(t_game *game)
{
	int	width;
	int	height;

	width = 600;
	height = 400;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, width, height, "cub3D");
	game->image_buffer.img = mlx_new_image(game->mlx, width, height);
	game->image_buffer.addr = mlx_get_data_addr(game->image_buffer.img,
			&game->image_buffer.bits_per_pixel,
			&game->image_buffer.line_length, &game->image_buffer.endian);
	game->image_buffer.width = width;
	game->image_buffer.height = height;
}

void	build(char *map_path)
{
	build_file(map_path);
	build_characters();
	build_mlx_itens(game());
	check();
}
