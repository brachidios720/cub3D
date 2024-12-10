/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:23:47 by raphael           #+#    #+#             */
/*   Updated: 2024/12/10 15:40:46 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear_image(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->mlx->center_height)
	{
		x = 0;
		while (x < info->mlx->width)
		{
			set_pixel_color(info->mlx->img, x, y, info->map.ceiling_color);
			x++;
		}
		y++;
	}
	while (y < info->mlx->height)
	{
		x = 0;
		while (x < info->mlx->width)
		{
			set_pixel_color(info->mlx->img, x, y, info->map.floor_color);
			x++;
		}
		y++;
	}
}

void	redraw_and_clear_window(t_info *info)
{
	clear_image(info);
	calculate_ray_directions(info);
	mlx_put_image_to_window(info->mlx->init_ptr, info->mlx->window,
		info->mlx->img.img_ptr, 0, 0);
}

int	game_loop(t_info *info)
{
	redraw_and_clear_window(info);
	return (0);
}
