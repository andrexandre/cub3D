/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealex <andrealex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:32:15 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/14 20:03:11 by andrealex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "constants.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define ESC_KEY 65307

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_file
{
	t_list		*map_lst;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*color_f;
	char		*color_c;
}				t_file;

typedef struct s_player
{
	t_coord		*pos;
	t_coord		*dir;
	t_coord		*plane;
}				t_player;

typedef struct s_buffer
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_buffer;

typedef struct s_sprites
{
	t_buffer	minimap_wall;
	t_buffer	minimap_floor;
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_coord		win_size;
	t_coord		pos;
	float		angle;
	t_file		*file;
	t_buffer	image_b;
	char		**map;
	char		**map_checker;
	t_player	*player;
	int			nbr_player;
	t_sprites	*sprites;
}				t_game;

// hook
int				quit(void);

// build_structure
t_game			*gm(void);
void			build(char *map_path);
void			build_file(char *map_path);
void			build_characters(void);
void			build_sprites(void);

// msg
void			error_msg(char *message);
void			ft_cleanup_strs(char **strs);
void			msg(const char *message);

// checker
void			check(void);
void			check_map(void);
void			check_map_extension(char *map_path);
void			floodfill(char **map);

// util
char			**convert_lst_to_char(t_list *lst);
bool			is_map_char(char c);
t_coord			*build_coord(double y, double x);

// action
void			hook(void);

// draw
void			draw_background(t_game *game);
void			draw(int x, int y, t_buffer *sprite, t_game *game);
void			put_pixel(t_buffer *img, int x, int y, int color);

#endif
