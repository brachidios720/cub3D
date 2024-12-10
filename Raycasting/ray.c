/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:24:59 by raphael           #+#    #+#             */
/*   Updated: 2024/12/10 18:55:01 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	walk_on_x(t_info *info)
{
	if (info->ray.raydir_x < 0)
	{
		info->ray.step_x = -1;
		info->ray.sidedist_x = (info->player.pos_x - info->ray.map_x)
			* info->ray.deltadist_x;
	}
	else
	{
		info->ray.step_x = 1;
		info->ray.sidedist_x = (info->ray.map_x + 1 - info->player.pos_x)
			* info->ray.deltadist_x;
	}
}

void	walk_on_y(t_info *info)
{
	if (info->ray.raydir_y < 0)
	{
		info->ray.step_y = -1;
		info->ray.sidedist_y = (info->player.pos_y - info->ray.map_y)
			* info->ray.deltadist_y;
	}
	else
	{
		info->ray.step_y = 1;
		info->ray.sidedist_y = (info->ray.map_y + 1 - info->player.pos_y)
			* info->ray.deltadist_y;
	}
}

bool	check_wath_wall_hit(t_info *info, int *hit)
{
	if (info->map.grid[info->ray.map_y][info->ray.map_x] > '0')
	{
		*hit = 1;
		if (info->ray.side == 0)
		{
			if (info->ray.raydir_x > 0)
				info->ray.texture_id = T_SOUTH;
			else
				info->ray.texture_id = T_NORTH;
		}
		else
		{
			if (info->ray.raydir_y > 0)
				info->ray.texture_id = T_EAST;
			else
				info->ray.texture_id = T_WEST;
		}
		return (TRUE);
	}
	return (FALSE);
}

void	check_while_wall_hit(t_info *info)
{
	int	hit;

	hit = 0;
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
		if (check_wath_wall_hit(info, &hit) == TRUE)
			hit = 1;
	}
}

void	check_projection_on_cameradist(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.perpwalldist = (info->ray.sidedist_x - info->ray.deltadist_x);
	else
		info->ray.perpwalldist = (info->ray.sidedist_y - info->ray.deltadist_y);
}
