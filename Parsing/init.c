#include "../include/cub3d.h"

void    init_data(t_data *data)
{
    
    data->mlx = mlx_init();
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Game");
}