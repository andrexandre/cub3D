#ifndef CUB3D_H
# define CUB3D_H

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
# include <unistd.h>

typedef struct s_file
{
	t_list		*map_lst;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*color_floor;
	char		*color_ceiling;
}				t_file;

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

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_file		*file;
	t_buffer	image_buffer;
	char		**map;
	char		**map_checker;
}				t_game;

// build_structure
void			build(char *map_path, t_game *game);
void			build_map(char *map_path, t_game *game);

// msg
void			error_msg(char *message, t_game *game);
void			ft_cleanup_strs(char **strs);

// checker
void			check(t_game *game);
void			check_map(t_game *game);
void			check_map_extension(char *map_path);
void			floodfill(char **map, t_game *game);

// util
char			**convert_lst_to_char(t_list *lst);
bool			vaild_map_char(char c);

#endif
