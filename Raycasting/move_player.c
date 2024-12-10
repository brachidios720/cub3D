/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:21:33 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/12/10 16:29:59 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall(t_info *info, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	return (info->map.grid[map_y][map_x] == '1');
}

int	check_handler_move(int keycode, t_info *info)
{
	if (keycode == W_KEYL)
	{
		if (!is_wall(info, info->player.pos_x + info->player.dir_x
				* info->player.move_speed, info->player.pos_y))
			info->player.pos_x += info->player.dir_x * info->player.move_speed;
		if (!is_wall(info, info->player.pos_x, info->player.pos_y
				+ info->player.dir_y * info->player.move_speed))
			info->player.pos_y += info->player.dir_y * info->player.move_speed;
	}
	if (keycode == S_KEYL)
		keycode_s(info);
	if (keycode == A_KEYL)
		keycode_a(info);
	if (keycode == D_KEYL)
		keycode_d(info);
	if (keycode == RIGHT_ARROW_KEYL)
		keycode_right_arrow(info);
	if (keycode == LEFT_ARROW_KEYL)
		keycode_left_arrow(info);
	return (0);
}
