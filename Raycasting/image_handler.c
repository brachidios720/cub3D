/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:30:17 by almarico          #+#    #+#             */
/*   Updated: 2024/12/09 15:58:17 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	image_handler(t_window *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->init_ptr, mlx->width, mlx->height);
	if (!mlx->img.img_ptr)
	{
		printf("Erreur : mlx_new_image a échoué\n");
		return ;
	}
	mlx->img.img_data_address = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
	if (!mlx->img.img_data_address)
	{
		printf("Erreur : mlx_get_data_addr a échoué\n");
	}
}
