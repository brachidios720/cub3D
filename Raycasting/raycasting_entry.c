/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:23 by raphael           #+#    #+#             */
/*   Updated: 2024/11/28 13:54:45 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	raycasting_entry(t_info *info)
{
	info->mlx = malloc(sizeof(t_window));
	if (!info->mlx)
		return (write_message(ERR_MALLOC), FAIL);
	if (init_display(info->mlx) == FAIL)
		return (FAIL);
	if (display(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
