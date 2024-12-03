/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:23 by raphael           #+#    #+#             */
/*   Updated: 2024/12/02 17:06:23 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	raycasting_entry(t_info *info)
{
	if (display(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
