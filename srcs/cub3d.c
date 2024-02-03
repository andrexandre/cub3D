/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:31:51 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/03 19:10:13 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*gm(void)
{
	static t_game	game;

	return (&game);
}

int	cub3d(char *map_path)
{
	build(map_path);
	return (1);
}

///mini_lib() {
void	my_mlx_pixel_put(t_buffer *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < image->width && y < image->height)
	{
		dst = image->addr 
			+ (y * image->line_length + x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	else
		prt("Illegal value x: %i, y: %i\n", x, y);
}

void	put_line(t_buffer *image, int x1, int y1, int x2, int y2, int color)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;
	int		i;

	dx = (float)(x2 - x1);
	dy = (float)(y2 - y1);
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	// step recebe o valor absoluto da diferenca maior
	dx /= step;
	dy /= step;
	x = x1;
	y = y1;
	i = 0;
	while (i <= step)
	{
		my_mlx_pixel_put(image, (int)x, (int)y, color);
		x += dx;
		y += dy;
		i++;
	}
}
// void	put_line(t_buffer *image, int x1, int y1, int x2, int y2, int color)
// {
// 	int	i;
// 	int	j;
// 	i = 0;
// 	j = 0;
// 	while (x1 + i < x2 || y1 + j < y2)
// 	{
// 		my_mlx_pixel_put(image, x1 + i, y1 + j, color);
// 		if (x1 + i < x2)
// 			i++;
// 		if (y1 + j < y2)
// 			j++;
// 	}
// 	my_mlx_pixel_put(image, x2, y2, color);
// }

int	argb(double a, int r, int g, int b)
{
	a = 1 - a;
	r *= a;
	g *= a;
	b *= a;
	return (r << 16 | g << 8 | b);
}

void	put_square(t_buffer *image, int x1, int y1, int x2, int y2, 
		int just_perimeter, int color)
{
	int	i;

	if (just_perimeter)
	{
		put_line(image, x1, y1, x1, y2, color);
		put_line(image, x1, y1, x2, y1, color);
		put_line(image, x2, y1, x2, y2, color);
		put_line(image, x1, y2, x2, y2, color);
	}
	else
	{
		i = 0;
		while (y1 + i <= y2)
		{
			put_line(image, x1, y1 + i, x2, y1 + i, color);
			i++;
		}
	}
}

void	create_image(int width, int height, int color, t_buffer *image)
{
	int is_perimeter;
	image->width = width;
	image->height = height;
	image->img = mlx_new_image(gm()->mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, 
			&image->bits_per_pixel, &image->line_length, 
			&image->endian);
	is_perimeter = (color == argb(0, 64, 64, 64));
	put_square(image, 0, 0, image->width - 1, image->height - 1, is_perimeter, color);
}
//} x = width, y = height
#define mapWidth 8
#define mapHeight 8
#define screenWidth 640
#define screenHeight 480
#define blockSize 40
char worldMap[mapWidth][mapHeight] =
{
  {'1','1','1','1','1','1','1', 0},
  {'1','0','0','0','0','0','1', 0},
  {'1','0','0','0','0','0','1', 0},
  {'1','0','0','0','0','0','1', 0},
  {'1','0','0','0','0','0','1', 0},
  {'1','0','0','0','0','0','1', 0},
  {'1','1','1','1','1','1','1', 0}
};

int quit(void)
{
	mlx_destroy_image(gm()->mlx, gm()->image_b.img);
	mlx_destroy_window(gm()->mlx, gm()->win);
	mlx_destroy_display(gm()->mlx);
	free(gm()->mlx);
	exit(0);
}
int	key_hook(int keycode)
{
	int step = 10;
	if (keycode == ESC_KEY || keycode == 'q')
		return (quit());
	put_square(&gm()->image_b, 0, 0, screenWidth - 1, screenHeight - 1, 0, 0);
	int	x;
	int	y = -1;
	while (++y < screenHeight / blockSize)
	{
		x = -1;
		while (++x < screenWidth / blockSize)
			put_square(&gm()->image_b, x * blockSize, y * blockSize, x * blockSize + blockSize - 1, y * blockSize + blockSize - 1, 1, argb(0, 64, 64, 64));
	}
	if (keycode == UP_KEY || keycode == W_KEY)
		gm()->pos.y -= step;
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		gm()->pos.x -= step;
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		gm()->pos.x += step;
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		gm()->pos.y += step;
	put_line(&gm()->image_b, gm()->pos.x + blockSize / 4, gm()->pos.y, gm()->pos.x + blockSize / 4, gm()->pos.y - blockSize, 255);
	put_square(&gm()->image_b, gm()->pos.x, gm()->pos.y, gm()->pos.x + 20 - 1, gm()->pos.y + 20 - 1, 0, argb(0, 255, 0, 0));
	mlx_put_image_to_window(gm()->mlx, gm()->win, gm()->image_b.img, 0, 0);
	return (0);
}
// int	main(int ac, char **av)
int	main(void)
{
	gm()->win_size.x = screenWidth;
	gm()->win_size.y = screenHeight;
	gm()->pos.x = screenWidth / 2 - blockSize / 4;
	gm()->pos.y = screenHeight / 2 - blockSize / 4;
	gm()->mlx = mlx_init();
	gm()->win = mlx_new_window(gm()->mlx, gm()->win_size.x, gm()->win_size.y, "cub3D");
	create_image(screenWidth, screenHeight, 25, &gm()->image_b);
	key_hook(0);
	mlx_hook(gm()->win, 2, 1L<<0, key_hook, NULL);
	mlx_hook(gm()->win, 17, 0, quit, &gm);
	mlx_loop(gm()->mlx);
	return (0);
	// if (ac == 2)
	// 	return (cub3d(av[1]));
	// else
	// 	error_msg("Invalid Number of Arguments");
}
