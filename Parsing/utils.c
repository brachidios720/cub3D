/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:40:02 by almarico          #+#    #+#             */
/*   Updated: 2024/12/03 12:11:34 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	write_message(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
}

int	flood_fill(char **map_copy, int row, int col, t_map map)
{
	if (row < 0 || row >= map.height || col < 0 || col >= map.width)
		return (STOP);
	if (map_copy[row][col] == ' ')
		return (STOP);
	if (map_copy[row][col] == '1' || map_copy[row][col] == 'V')
		return (CONTINUE);
	map_copy[row][col] = 'V';
	flood_fill(map_copy, row + 1, col, map);
	flood_fill(map_copy, row - 1, col, map);
	flood_fill(map_copy, row, col + 1, map);
	flood_fill(map_copy, row, col - 1, map);
	return (CONTINUE);
}
