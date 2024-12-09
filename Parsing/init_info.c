/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:26 by almarico          #+#    #+#             */
/*   Updated: 2024/12/02 18:03:27 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_player_and_ray(t_info *info)
{
	info->player.pos_x = -1;
	info->player.pos_y = -1;
	info->player.dir_x = -1;
	info->player.dir_y = 0;
	info->player.plane_x = 0;
	info->player.plane_y = 0;
    info->player.move_speed = 0.10;
    info->player.rot_speed = 0.07;
	info->player.facing = 0;
	info->ray.raydir_x = -1;
	info->ray.raydir_y = -1;
	info->ray.deltadist_x = -1;
	info->ray.deltadist_y = -1;
	info->ray.sidedist_x = -1;
	info->ray.sidedist_y = -1;
	info->ray.perpwalldist = -1;
	info->ray.step_x = -1;
	info->ray.step_y = -1;
	info->ray.map_x = 0;
	info->ray.map_y = 0;
	info->ray.side = 0;
	info->ray.texture_id = 0;
}

static void	init_texture(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		info->texture[i].data = NULL;
		info->texture[i].width = 64;
		info->texture[i].height = 64;
		info->texture[i].wall_x = 0;
		info->texture[i].tex_x = 0;
		info->texture[i].tex_y = 0;
		info->texture[i].step = 0;
		info->texture[i].texpos = 0;
		i++;
	}
}

int	init_info(t_info *info)
{
	info->buffer = NULL;
	info->buffer_size = -1;
	info->isrunning = -1;
	init_player_and_ray(info);
	info->map.grid = NULL;
	info->map.width = 0;
	info->map.height = 0;
	info->map.ceiling_color = -1;
	info->map.floor_color = -1;
	info->render.screenwidth = WIDTH;
	info->render.screenheight = HEIGHT;
	info->render.lineheight = 0;
	info->render.drawstart = 0;
	info->render.drawend = 0;
	init_texture(info);
	info->mlx = malloc(sizeof(t_window));
	if (!info->mlx)
		return (write_message(ERR_MALLOC), FAIL);
	return (init_display(info->mlx));
}
