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
        if (info->map.grid[info->ray.map_x][info->ray.map_y] > '0') 
            hit = 1;
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
    info->render.drawstart = (-info->render.lineheight / 2 )+ (HEIGHT / 2);
    if(info->render.drawstart < 0)
        info->render.drawstart = 0;
    info->render.drawend = (info->render.lineheight / 2) + (HEIGHT / 2);
    if(info->render.drawend >= HEIGHT)
        info->render.drawend = HEIGHT - 1;
}

void    draw_wall_slice(t_info *info, int x, t_window *window)
{
    int color;

    // Déterminer la couleur du mur en fonction de la valeur de la carte
    switch (info->map.grid[info->ray.map_x][info->ray.map_y])
    {
        case '1':  color = 0xFF0000; break; // Rouge
        case '2':  color = 0x00FF00; break; // Vert
        case '3':  color = 0x0000FF; break; // Bleu
        case '4':  color = 0xFFFFFF; break; // Blanc
        default:   color = 0xFFFF00; break; // Jaune
    }

    // Réduire la luminosité si on est sur un côté (horizontal ou vertical)
    if (info->ray.side == 1)
        color = (color & 0xFEFEFE) >> 1; // Divise les composantes RGB par 2

    // Dessiner la ligne verticale
    verLine(window->img, x, info, color);
}

void    verLine(t_img_info img, int x, t_info *info, int color)
{
    int y;

    for (y = info->render.drawstart; y <= info->render.drawend; y++)
    {
        //printf("iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n");
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

    // Assurez-vous que les coordonnées sont dans la carte
    // if (map_x < 0 || map_y < 0 || map_x >= info->map_width || map_y >= info->map_height)
    //     return 1;

    // Retourne 1 si c'est un mur, 0 sinon
    return (info->map.grid[map_y][map_x] == '1');
}

int    check_handler_move(int keycode, t_info *info)
{
    if (keycode == W_KEYL) 
    { // Avancer (W)
        //printf("IIIIIIIIIIIIIIIIIICCCCCCCCCCCCCCCCCCIIIIIIIIIIIII\n");
        if (!is_wall(info, info->player.pos_x + info->player.dir_x * info->player.move_speed, info->player.pos_y))
            info->player.pos_x += info->player.dir_x * info->player.move_speed;
        if (!is_wall(info, info->player.pos_x, info->player.pos_y + info->player.dir_y * info->player.move_speed))
            info->player.pos_y += info->player.dir_y * info->player.move_speed;    
    }
    if (keycode == S_KEYL)
    { // reculer (S)
        if (!is_wall(info, info->player.pos_x - info->player.dir_x * info->player.move_speed, info->player.pos_y))
            info->player.pos_x -= info->player.dir_x * info->player.move_speed;
        if (!is_wall(info, info->player.pos_x, info->player.pos_y - info->player.dir_y * info->player.move_speed))
            info->player.pos_y -= info->player.dir_y * info->player.move_speed;
    }
    if  (keycode == D_KEYL)
    {
        double olddirx = info->player.dir_x;
        info->player.dir_x = info->player.dir_x * cos(-info->player.rot_speed) - info->player.dir_y * sin(-info->player.rot_speed);
        info->player.dir_y = olddirx * sin(-info->player.rot_speed) + info->player.dir_y * cos(-info->player.rot_speed);
        double  oldplanex = info->player.plane_x;
        info->player.plane_x = info->player.plane_x * cos(-info->player.rot_speed) - info->player.plane_y * sin(-info->player.rot_speed);
        info->player.plane_y = oldplanex * sin(-info->player.rot_speed) + info->player.plane_y * cos(-info->player.rot_speed);
    }
    if  (keycode == A_KEYL)
    {
        double olddirx = info->player.dir_x;
        info->player.dir_x = info->player.dir_x * cos(info->player.rot_speed) - info->player.dir_y * sin(info->player.rot_speed);
        info->player.dir_y = olddirx * sin(info->player.rot_speed) + info->player.dir_y * cos(info->player.rot_speed);
        double  oldplanex = info->player.plane_x;
        info->player.plane_x = info->player.plane_x * cos(info->player.rot_speed) - info->player.plane_y * sin(info->player.rot_speed);
        info->player.plane_y = oldplanex * sin(info->player.rot_speed) + info->player.plane_y * cos(info->player.rot_speed);
    }
	// else if (keycode == KEY_S)
	// {
	// 	check(map, map->pos_x + 1, map->pos_y);
	// 	parcours_map(map);
	// }
	// else if (keycode == KEY_D)
	// {
	// 	check(map, map->pos_x, map->pos_y + 1);
	// 	parcours_map(map);
	// }
    return(0);
}