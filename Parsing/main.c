/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:11 by raphael           #+#    #+#             */
/*   Updated: 2024-11-26 12:49:11 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_data data;
	t_map_param	*info;

	init_data(&data);
	info = malloc(sizeof(t_map_param));
	if (!info)
		return (FAIL);
	if (raycasting_entry(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
