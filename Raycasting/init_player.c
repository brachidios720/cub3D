/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:54:45 by raphael           #+#    #+#             */
/*   Updated: 2024/12/10 15:20:46 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_ray_directions(t_info *info)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		info->ray.camera_x = 2 * x / (double)WIDTH - 1;
		info->ray.raydir_x = info->player.dir_x + info->player.plane_x
			* info->ray.camera_x;
		info->ray.raydir_y = info->player.dir_y + info->player.plane_y
			* info->ray.camera_x;
		info->ray.map_x = (int)info->player.pos_x;
		info->ray.map_y = (int)info->player.pos_y;
		calculate_delta_distances_x(info);
		calculate_delta_distances_y(info);
		walk_on_x(info);
		walk_on_y(info);
		check_while_wall_hit(info);
		check_projection_on_cameradist(info);
		render_tall_for_texture(info);
		draw_wall_slice3(info, x, info->mlx->window);
		x++;
	}
}

void	calculate_delta_distances_x(t_info *info)
{
	if (info->ray.raydir_x == 0)
		info->ray.deltadist_x = INFINITY;
	else
		info->ray.deltadist_x = fabs(1.0 / info->ray.raydir_x);
}

void	calculate_delta_distances_y(t_info *info)
{
	if (info->ray.raydir_y == 0)
		info->ray.deltadist_y = INFINITY;
	else
		info->ray.deltadist_y = fabs(1.0 / info->ray.raydir_y);
}

void	init_camera_start_eo(t_info *info)
{
	if (info->player.facing == 'W')
	{
		info->player.dir_x = 1;
		info->player.plane_y = -0.66;
	}
	else if (info->player.facing == 'E')
	{
		info->player.dir_x = -1;
		info->player.plane_y = 0.66;
	}
	info->player.dir_y = 0;
	info->player.plane_x = 0;
}

void	init_camera_start_sn(t_info *info)
{
	if (info->player.facing == 'S')
	{
		info->player.dir_y = 1;
		info->player.plane_x = 0.66;
	}
	else if (info->player.facing == 'N')
	{
		info->player.dir_y = -1;
		info->player.plane_x = -0.66;
	}
	info->player.dir_x = 0;
	info->player.plane_y = 0;
}
