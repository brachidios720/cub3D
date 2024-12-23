/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:41:41 by raphael           #+#    #+#             */
/*   Updated: 2024/12/09 15:59:07 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_image(t_window *mlx)
{
	if (mlx->img.img_ptr)
	{
		mlx_destroy_image(mlx->init_ptr, mlx->img.img_ptr);
		mlx->img.img_ptr = NULL;
	}
}

void	redraw_window(t_window *mlx)
{
	destroy_image(mlx);
	image_handler(mlx);
	mlx_put_image_to_window(mlx->init_ptr, mlx->window, mlx->img.img_ptr, 0, 0);
}

int	closes(t_info *info)
{
	mlx_destroy_image(info->mlx->init_ptr, info->mlx->img.img_ptr);
	free_info(info);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_info *info)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(info->mlx->init_ptr, info->mlx->img.img_ptr);
		free_info(info);
		exit(0);
	}
	return (0);
}

void	event_handler(t_info *info)
{
	mlx_hook(info->mlx->window, ON_KEYDOWN, 1L << 0, key_handler, info);
	mlx_hook(info->mlx->window, ON_DESTROY, 1L << 17, closes, info);
}
