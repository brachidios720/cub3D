/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 14:11:01 by raphael           #+#    #+#             */
/*   Updated: 2024-12-03 14:11:01 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    keycode_S(t_info *info)
{
    if (!is_wall(info, info->player.pos_x - info->player.dir_x * info->player.move_speed, info->player.pos_y))
            info->player.pos_x -= info->player.dir_x * info->player.move_speed;
    if (!is_wall(info, info->player.pos_x, info->player.pos_y - info->player.dir_y * info->player.move_speed))
            info->player.pos_y -= info->player.dir_y * info->player.move_speed;
}

void    keycode_A(t_info *info)
{
    if (!is_wall(info, info->player.pos_x - info->player.plane_x * info->player.move_speed, info->player.pos_y))
            info->player.pos_x -= info->player.plane_x * info->player.move_speed;
    if (!is_wall(info, info->player.pos_x, info->player.pos_y - info->player.plane_y * info->player.move_speed))
            info->player.pos_y -= info->player.plane_y * info->player.move_speed;
}

void    keycode_D(t_info *info)
{
    if (!is_wall(info, info->player.pos_x + info->player.plane_x * info->player.move_speed, info->player.pos_y))
            info->player.pos_x += info->player.plane_x * info->player.move_speed;
    if (!is_wall(info, info->player.pos_x, info->player.pos_y + info->player.plane_y * info->player.move_speed))
            info->player.pos_y += info->player.plane_y * info->player.move_speed;
}

void    keycode_right_arrow(t_info *info)
{
    double olddirx = info->player.dir_x;
    info->player.dir_x = info->player.dir_x * cos(-info->player.rot_speed) - info->player.dir_y * sin(-info->player.rot_speed);
    info->player.dir_y = olddirx * sin(-info->player.rot_speed) + info->player.dir_y * cos(-info->player.rot_speed);
    double  oldplanex = info->player.plane_x;
    info->player.plane_x = info->player.plane_x * cos(-info->player.rot_speed) - info->player.plane_y * sin(-info->player.rot_speed);
    info->player.plane_y = oldplanex * sin(-info->player.rot_speed) + info->player.plane_y * cos(-info->player.rot_speed);
}

void    keycode_left_arrow(t_info *info)
{
    double olddirx = info->player.dir_x;
    info->player.dir_x = info->player.dir_x * cos(info->player.rot_speed) - info->player.dir_y * sin(info->player.rot_speed);
    info->player.dir_y = olddirx * sin(info->player.rot_speed) + info->player.dir_y * cos(info->player.rot_speed);
    double  oldplanex = info->player.plane_x;
    info->player.plane_x = info->player.plane_x * cos(info->player.rot_speed) - info->player.plane_y * sin(info->player.rot_speed);
    info->player.plane_y = oldplanex * sin(info->player.rot_speed) + info->player.plane_y * cos(info->player.rot_speed);
}