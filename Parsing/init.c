#include "../include/cub3d.h"

void    init_data(t_data *data)
{
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGH);
    data->window = mlx_new_window(data->mlx, WIDTH, HEIGH, "Game");
    data->mlx = mlx_init();
}