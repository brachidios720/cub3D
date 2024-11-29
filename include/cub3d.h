/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:52:49 by almarico          #+#    #+#             */
/*   Updated: 2024/11/29 13:59:29 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include "../libft-complete/libft/libft.h"
# include "../libft-complete/printf/ft_printf.h"
# include "../libft-complete/get_next_line/gnl.h"

/* general & error defines */
# define SUCCESS					0
# define FAIL						1
# define CONTINUE					0
# define STOP						1
# define STDIN						0
# define STDOUT						1
# define STDERR						2

/* mlx event define */
# define ON_KEYDOWN					2
# define ON_KEYUP					3
# define ON_MOUSEDOWN				4
# define ON_MOUSEUP					5
# define ON_MOUSEMOVE				6
# define ON_EXPOSE					12
# define ON_DESTROY					17

/* color defines */
# define COLOR_RED					0xFF0000
# define COLOR_GREEN				0x00FF00
# define COLOR_BLUE					0x0000FF
# define COLOR_GREY					0x999999
# define DEFAULT_COLOR_VALUE		0xF000FF
# define COLOR_LIGHT_BLUE			0x6BA6B5

/* error define */
# define ERR_MALLOC					"An error occured during the malloc\n"
# define ERR_ARG					"The number or arguments is different from two\n"
# define ERR_DIR					"Error occur while opening: argument is a directory\n"
# define ERR_OPEN					"Error occur while opening: the oppening fail\n"
# define ERR_EMPTY					"Error occur while reading: the map is empty\n"
# define ERR_COPY					"Error occur while copying the map\n"

/* other define */
# define HEIGHT	720
# define WIDTH	1280

/* mlx structure */
typedef struct s_img_info
{
	void			*img_ptr;
	char			*img_data_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_img_info;

typedef struct s_window
{
	void			*init_ptr;
	void			*window;
	int				width;
	int				height;
	int				center_width;
	int				center_height;
	t_img_info		img;
}				t_window;

/* raycasting_structure */

typedef struct s_player
{
	double	pos_x;		// Player's _x position
	double	pos_y;		// Player's _y position
	double	dir_x;		// Player's direction vector _x
	double	dir_y;		// Player's direction vector _y
	double	plane_x;		// Camera plane vector _x
	double	plane_y;		// Camera plane vector _y
	double	move_speed;	// Movement speed
	double	rot_speed;	// Rotation speed
}				t_player;

typedef struct s_ray
{
	double	raydir_x;		// Direction of the ray X
	double	raydir_y;		// Direction of the ray Y
	double	deltadist_x;	// Distance ray travels to cross a grid cell X
	double	deltadist_y;	// Distance ray travels to cross a grid cell Y
	double	sidedist_x;		// Distance to the first side of the grid X
	double	sidedist_y;		// Distance to the first side of the grid Y
	double	perpwalldist;	// Perpendicular distance to the wall
	int		step_x;				// Step direction in X (+1 or -1)
	int		step_y;				// Step direction in Y (+1 or -1)
	int		map_x;				// Current grid cell X
	int		map_y;				// Current grid cell Y
	int		side;				// 0 for vertical wall, 1 for horizontal wall
}				t_ray;

typedef struct s_texture
{
	int		*data;		// Pointer to the texture data
	int		width;		// Width of the texture
	int		height;		// Height of the texture
	double	wall_x;		// Exact X coordinate of the wall hit
	int		tex_x;		// X coordinate in the texture
	int		tex_y;		// Y coordinate in the texture
	double	step;		// Step size for sampling the texture
	double	texpos;		// Current position in the texture
}				t_texture;

typedef struct s_map
{
	char	**grid;			// 2D array representing the map
	int		width;			// Map width
	int		height;			// Map height
}				t_map;

typedef struct s_render
{
	int	screenwidth;	// Screen width
	int	screenheight;	// Screen height
	int	lineheight;		// Height of the wall slice
	int	drawstart;		// Start point for drawing the wall slice
	int	drawend;		// End point for drawing the wall slice
}				t_render;

/* global structure */

typedef struct s_info
{
	t_window	*mlx;
	t_player	player;		// Player information
	t_ray		ray;		// Raycasting variables
	t_map		map;		// Map data
	t_render	render;		// Rendering parameters
	t_texture	texture;	// Texture data
	int			**buffer;	// Framebuffer for rendering
	int			buffer_size;
	int			isrunning;	// Game loop flag
}				t_info;

typedef struct s_parse
{
	int			fd_map;
	int			fd_texture;
	char		*tab[128];
}				t_parse;

/* raycasting_entry.c */
int							raycasting_entry(t_info *info);

/* color_writing.c */
void						set_pixel_color(t_img_info img, int pos_x, int pos_y, int color);

/* event_handler.c */
void						destroy_image(t_window *mlx);
void						redraw_window(t_window *mlx);
int							closes(t_info *info);
int							key_handler(int keycode, t_info *info);
void						event_handler(t_info *info);

/* image_handler.c */
void						image_handler(t_window *mlx);

/* init_mlx.c */
int							init_display(t_window *mlx);
int							display(t_info *info);

/* utils.c */
void						write_message(const char *msg);

/* free_utils.c */
void						free_info(t_info *info);
void						free_double_int(int **tab, int size);
void						free_double_tab(char **tab);
void						free_list(t_list **lst);

/* check_format.c */
int							check_cub_format(char *str);

/* check_opening.c */
int							check_opening(char *str, int *fd);

/* get_map_info.c */
int							get_map_info(t_parse *parsing);

/* fill_info.c */
int							fill_info(t_info *info, t_parse *parsing);

#endif // !CUB3D_H
