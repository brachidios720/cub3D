/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-30 16:24:59 by raphael           #+#    #+#             */
/*   Updated: 2024-11-30 16:24:59 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    walk_on_x(t_info *info)
{
    if(info->ray.raydir_x < 0) 
    {
        info->ray.step_x = -1;
        info->ray.sidedist_x = (info->player.pos_x - info->ray.map_x) * info->ray.deltadist_x;
    } 
    else
    {
        info->ray.step_x = 1;
        info->ray.sidedist_x = (info->ray.map_x + 1 - info->player.pos_x) * info->ray.deltadist_x;
    }
}

void    walk_on_y(t_info *info)
{
    if(info->ray.raydir_y < 0) 
    {
        info->ray.step_y = -1;
        info->ray.sidedist_y = (info->player.pos_y - info->ray.map_y) * info->ray.deltadist_y;
    } 
    else
    {
        info->ray.step_y = 1;
        info->ray.sidedist_y = (info->ray.map_y + 1 - info->player.pos_y) * info->ray.deltadist_y;
    }
}

void    check_while_wall_hit(t_info *info)
{
    int hit = 0;
    while (hit == 0)
    {
        if (info->ray.sidedist_x < info->ray.sidedist_y)
        {
          info->ray.sidedist_x += info->ray.deltadist_x;
          info->ray.map_x += info->ray.step_x;
          info->ray.side = 0;
        }
        else
        {
          info->ray.sidedist_y += info->ray.deltadist_y;
          info->ray.map_y += info->ray.step_y;
          info->ray.side = 1;
        }
        if (info->map.grid[info->ray.map_y][info->ray.map_x] > '0')
        {
            hit = 1;
            if(info->ray.side == 0)
            {
                if(info->ray.raydir_x > 0)
                    info->ray.texture_id = T_SOUTH;
                else 
                    info->ray.texture_id = T_NORTH;
            }
            else
            {
                if(info->ray.raydir_y > 0)
                    info->ray.texture_id = T_EAST;
                else
                    info->ray.texture_id = T_WEST;
            }
        }
    }
}

void    check_projection_on_cameradist(t_info *info)
{
    if(info->ray.side == 0)
        info->ray.perpwalldist = (info->ray.sidedist_x - info->ray.deltadist_x);
    else
        info->ray.perpwalldist = (info->ray.sidedist_y - info->ray.deltadist_y);
}

void    render_tall_for_texture(t_info *info)
{
    info->render.lineheight = (int)(HEIGHT / info->ray.perpwalldist);
    info->render.drawstart = (-info->render.lineheight / 2 ) + (HEIGHT / 2);
    if(info->render.drawstart < 0)
        info->render.drawstart = 0;
    info->render.drawend = (info->render.lineheight / 2) + (HEIGHT / 2);
    if(info->render.drawend >= HEIGHT)
        info->render.drawend = HEIGHT - 1;
}

// void    draw_wall_slice(t_info *info, int x, t_window *window)
// {
//     int color;

//     // Déterminer la couleur du mur en fonction de la valeur de la carte
//     switch (info->map.grid[info->ray.map_y][info->ray.map_x])
//     {
//         case '1':  color = 0xFF0000; break; // Rouge
//         case '2':  color = 0x00FF00; break; // Vert
//         case '3':  color = 0x0000FF; break; // Bleu
//         case '4':  color = 0xFFFFFF; break; // Blanc
//         default:   color = 0xFFFF00; break; // Jaune
//     }

//     // Réduire la luminosité si on est sur un côté (horizontal ou vertical)
//     if (info->ray.side == 1)
//         color = (color & 0xFEFEFE) >> 1; // Divise les composantes RGB par 2

//     // Dessiner la ligne verticale
//     verLine(window->img, x, info, color);
// }

void    verLine(t_img_info img, int x, t_info *info, int color)
{
    int y;

    for (y = info->render.drawstart; y <= info->render.drawend; y++)
    {
        set_pixel_color(img, x, y, color);
    }
}

void    count_fps_move_speed(t_info *info)
{
    info->old_time = info->time;
    info->time = get_ticks();

    info->frametime = (info->time - info->old_time) / 1000;
    //printf("fps = %f\r", 1/info->frametime);

    //redraw_and_clear_window(info);

    //info->player.move_speed = info->frametime * 5;
    //info->player.rot_speed = info->frametime * 3;
}

unsigned long get_ticks() 
{
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}

int is_wall(t_info *info, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;

    return (info->map.grid[map_y][map_x] == '1');
}

int    check_handler_move(int keycode, t_info *info)
{
    if (keycode == W_KEYL) 
    { // Avancer (W)
        if (!is_wall(info, info->player.pos_x + info->player.dir_x * \
        info->player.move_speed, info->player.pos_y))
            info->player.pos_x += info->player.dir_x * info->player.move_speed;
        if (!is_wall(info, info->player.pos_x, info->player.pos_y + \
        info->player.dir_y * info->player.move_speed))
            info->player.pos_y += info->player.dir_y * info->player.move_speed;    
    }
    if (keycode == S_KEYL)
        keycode_S(info);
    if (keycode == A_KEYL)
        keycode_A(info);
    if (keycode == D_KEYL)
        keycode_D(info);
    if  (keycode == RIGHT_ARROW_KEYL)
        keycode_right_arrow(info);
    if  (keycode == LEFT_ARROW_KEYL)
        keycode_left_arrow(info);
    return(0);
}