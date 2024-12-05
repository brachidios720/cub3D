/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-30 21:23:47 by raphael           #+#    #+#             */
/*   Updated: 2024-11-30 21:23:47 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void clear_image(t_img_info *img, int width, int height, int color)
{
    int x, y;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            set_pixel_color(*img, x, y, color);
            x++;
        }
        y++;
    }
}


void redraw_and_clear_window(t_info *info)
{
    // Efface l'image (remplie avec du noir, par exemple)
    // for (int y = 0; y < HEIGHT; y++) {
    //     for (int x = 0; x < WIDTH; x++) {
    //         info->mlx->img.img_data_address[y * WIDTH + x] = 0x000000; // Noir
    //     }
    // }


    clear_image(&info->mlx->img, WIDTH, HEIGHT, 0x000000);
    // Dessine les nouveaux éléments
    calculate_ray_directions(info);

    //mlx_clear_window(info->mlx->init_ptr, info->mlx->window);
    // Affiche l'image dans la fenêtre
    mlx_put_image_to_window(info->mlx->init_ptr, info->mlx->window, info->mlx->img.img_ptr, 0, 0);
}

int game_loop(t_info *info)
{
    // Calcul FPS et vitesse
    count_fps_move_speed(info);

    // Redessine tout
    redraw_and_clear_window(info);

    return (0);
}
