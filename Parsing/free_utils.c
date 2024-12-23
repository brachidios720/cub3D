/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:01:52 by almarico          #+#    #+#             */
/*   Updated: 2024/12/10 15:30:52 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
	}
}

void	free_double_int(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
}

void	free_info(t_info *info)
{
	if (info->map.grid)
	{
		free_double_tab(info->map.grid);
		free(info->map.grid);
	}
	free_double_int(info->buffer, info->buffer_size);
	if (info->mlx)
	{
		if (info->texture[T_NORTH].img.img_ptr)
			mlx_destroy_image(info->mlx->init_ptr,
				info->texture[T_NORTH].img.img_ptr);
		if (info->texture[T_EAST].img.img_ptr)
			mlx_destroy_image(info->mlx->init_ptr,
				info->texture[T_EAST].img.img_ptr);
		if (info->texture[T_SOUTH].img.img_ptr)
			mlx_destroy_image(info->mlx->init_ptr,
				info->texture[T_SOUTH].img.img_ptr);
		if (info->texture[T_WEST].img.img_ptr)
			mlx_destroy_image(info->mlx->init_ptr,
				info->texture[T_WEST].img.img_ptr);
		mlx_destroy_window(info->mlx->init_ptr, info->mlx->window);
		mlx_destroy_display(info->mlx->init_ptr);
		free(info->mlx->init_ptr);
		free(info->mlx);
	}
}
