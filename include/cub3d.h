/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:52:49 by almarico          #+#    #+#             */
/*   Updated: 2024/12/10 17:07:09 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft-complete/get_next_line/gnl.h"
# include "../libft-complete/libft/libft.h"
# include "../libft-complete/printf/ft_printf.h"
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <time.h>

/* general & error defines */
# define SUCCESS 0
# define FAIL 1
# define TRUE 1
# define FALSE 0
# define CONTINUE 1
# define STOP 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* mlx event define */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

/*keycode mac*/
# define W_KEYM 13
# define S_KEYM 1
# define A_KEYM 0
# define D_KEYM 2
# define RIGHT_ARROW_KEYM 124
# define LEFT_ARROW_KEYM 123

/* keycode linux*/
# define W_KEYL 119
# define S_KEYL 115
# define A_KEYL 97
# define D_KEYL 100
# define RIGHT_ARROW_KEYL 65363
# define LEFT_ARROW_KEYL 65361

/* color defines */
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_GREY 0x999999
# define DEFAULT_COLOR_VALUE 0xF000FF
# define COLOR_LIGHT_BLUE 0x6BA6B5

/* error define */
# define ERR_MALLOC "An error occured during the malloc\n"
# define ERR_ARG \
	"The number or arguments is different \
from two\n"
# define ERR_CUB_FORMAT "Error: the map is not a .cub format\n"
# define ERR_DIR \
	"Error occur while opening: argument is \
a directory\n"
# define ERR_OPEN \
	"Error occur while opening: the opening \
fail\n"
# define ERR_EMPTY \
	"Error occur while reading: the map is \
empty\n"
# define ERR_COPY "Error occur while copying the map\n"
# define ERR_TEXTURE_EXIST \
	"Error occur while init the texture: \
texture already init\n"
# define ERR_XPM \
	"Error occur while opening: xpm to image \
failed\n"
# define ERR_NO_XPM \
	"Error occur while reading: there is \
no xpm\n"
# define ERR_XPM_FORMAT \
	"Error: the texture is not a .xpm \
format\n"
# define ERR_CHAR_MAP \
	"Error: there is other character in the \
map than \" 01NSEW\"\n"
# define ERR_MULTIPLE_PLAYER \
	"Error: there are multiple player in \
the map\n"
# define ERR_NO_PLAYER "Error: no player in the map\n"
# define ERR_NO_SPACE \
	"Error: there are no space for the player \
to play\n"
# define ERR_MAP "Error: the map is not surrounded by wall\n"
# define ERR_COLOR \
	"Error: r, g or b are not in the range \
0-255\n"

/* other define */
# define HEIGHT 720
# define WIDTH 1280

/* parsing define */
# define MAP_CHARSET "01NSEW"
# define NORTH "NO"
# define EAST "EA"
# define SOUTH "SO"
# define WEST "WE"
# define FLOOR "F"
# define CEILING "C"

/* define textures */
# define T_NORTH 0
# define T_EAST 1
# define T_SOUTH 2
# define T_WEST 3

/* mlx structure */
typedef struct s_img_info
{
	void		*img_ptr;
	char		*img_data_address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img_info;

typedef struct s_window
{
	void		*init_ptr;
	void		*window;
	int			width;
	int			height;
	int			center_width;
	int			center_height;
	t_img_info	img;
}				t_window;

/* raycasting_structure */

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	char	facing;
}				t_player;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	int		texture_id;
}				t_ray;
typedef struct s_texture
{
	t_img_info	img;
	int			width;
	int			height;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		texpos;
}				t_texture;
typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			ceiling_color;
	int			floor_color;
}				t_map;

typedef struct s_render
{
	int	screenwidth;
	int	screenheight;
	int	lineheight;
	int	drawstart;
	int	drawend;
}				t_render;

/* global structure */

typedef struct s_info
{
	t_window	*mlx;
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_render	render;
	double		time;
	double		old_time;
	double		frametime;
	t_texture	texture[4];
	int			**buffer;
	int			buffer_size;
	int			isrunning;
}				t_info;

typedef struct s_parse
{
	int			fd_map;
	int			fd_texture;
	char		*tab[128];
}				t_parse;

/* raycasting_entry.c */

//	move_player
int				is_wall(t_info *info, double x, double y);
int				check_handler_move(int keycode, t_info *info);

//	ray.c

void			walk_on_x(t_info *info);
void			walk_on_y(t_info *info);
void			check_projection_on_cameradist(t_info *info);
void			check_while_wall_hit(t_info *info);
bool			check_wath_wall_hit(t_info *info, int *hit);

//	raycasting_entry.c
int				raycasting_entry(t_info *info);

//	raycasting.c
void			redraw_and_clear_window(t_info *info);
int				game_loop(t_info *info);
void			clear_image(t_info *info);

//	utils_move_player.c

//	init_player.c
void			calculate_ray_directions(t_info *info);
void			calculate_delta_distances_x(t_info *info);
void			calculate_delta_distances_y(t_info *info);
void			init_camera_start_sn(t_info *info);
void			init_camera_start_eo(t_info *info);

//	wall_texture.c
void			render_tall_for_texture(t_info *info);
void			calculate_ray_step_and_distances(t_info *info);
void			draw_wall_slice3(t_info *info, int x, t_img_info *img);
void			draw_wall(t_info *info, int x);
int				get_pix_color(t_texture texture, int x, int y);

// player move

void			keycode_s(t_info *info);
void			keycode_a(t_info *info);
void			keycode_d(t_info *info);
void			keycode_right_arrow(t_info *info);
void			keycode_left_arrow(t_info *info);
/* color_writing.c */
void			set_pixel_color(t_img_info img, int x, int y, int color);

/* event_handler.c */
void			destroy_image(t_window *mlx);
void			redraw_window(t_window *mlx);
int				closes(t_info *info);
int				key_handler(int keycode, t_info *info);
void			event_handler(t_info *info);

/* image_handler.c */
void			image_handler(t_window *mlx);

/* init_mlx.c */
int				init_display(t_window *mlx);
int				display(t_info *info);

/* utils.c */
void			write_message(const char *msg);
unsigned long	get_ticks(void);
int				flood_fill(char **map_copy, int row, int col, t_map map);
void			printf_map(char **map);
void			add_rest(t_info *info);

/* free_utils.c */
void			free_info(t_info *info);
void			free_double_int(int **tab, int size);
void			free_double_tab(char **tab);
void			free_list(t_list **lst);

/* check_format.c */
int				check_cub_format(char *str);
int				check_xpm_format(char *str);

/* check_opening.c */
int				check_opening(char *str, int *fd);

/* get_map_info.c */
int				get_map_info(t_parse *parsing);

/* fill_info.c */
int				fill_info(t_info *info, t_parse *parsing);
int				contain_only_isspace(char *line);

/* fill_texture.c */
int				fill_texture(t_info *info, char *line);

/* fill_color.c */
int				fill_color(t_info *info, char *line);

/* fill_map.c */
int				everything_is_set(t_info *info);
int				fill_map(t_info *info, t_parse *parsing, int *i);

/* fill_player.c */
int				fill_player(t_info *info);

/* init_info.c */
int				init_info(t_info *info);

#endif // !CUB3D_H
