/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:28 by almarico          #+#    #+#             */
/*   Updated: 2024/12/04 18:46:59 by almarico         ###   ########.fr       */
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
	mlx->window = mlx_new_window(mlx->init_ptr, mlx->width, \
						mlx->height, "cub3d");
	if (!mlx->window)
		return (FAIL);
	return (SUCCESS);
}

int	display(t_info *info)
{
	image_handler(info->mlx);
	mlx_put_image_to_window(info->mlx->init_ptr, info->mlx->window, \
						info->mlx->img.img_ptr, 0, 0);
	event_handler(info);
	mlx_loop(info->mlx->init_ptr);
	return (SUCCESS);
}
