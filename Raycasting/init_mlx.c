/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:28 by almarico          #+#    #+#             */
/*   Updated: 2024/12/10 18:31:30 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_display(t_window *mlx)
{
	mlx->width = WIDTH;
	mlx->height = HEIGHT;
	mlx->center_width = mlx->width / 2 - 1;
	mlx->center_height = mlx->height / 2 - 1;
	mlx->init_ptr = mlx_init();
	if (!mlx->init_ptr)
		return (FAIL);
	mlx->window = mlx_new_window(mlx->init_ptr, mlx->width, mlx->height,
			"cub3d");
	if (!mlx->window)
		return (FAIL);
	return (SUCCESS);
}

int	display(t_info *info)
{
	image_handler(info->mlx);
	mlx_key_hook(info->mlx->window, check_handler_move, info);
	mlx_loop_hook(info->mlx->init_ptr, game_loop, info);
	event_handler(info);
	mlx_loop(info->mlx->init_ptr);
	return (SUCCESS);
}
