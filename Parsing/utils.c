/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:40:02 by almarico          #+#    #+#             */
/*   Updated: 2024/12/06 15:34:37 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	write_message(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
}

int	flood_fill(char **map_copy, int row, int col, t_map map)
{
	if (row < 0 || row >= map.height
		|| col < 0 || col >= (int)ft_strlen(map_copy[row]))
		return (FALSE);
	if (map_copy[row][col] == ' ')
		return (FALSE);
	if (map_copy[row][col] == '1' || map_copy[row][col] == 'F')
		return (TRUE);
	map_copy[row][col] = 'F';
	if (!flood_fill(map_copy, row + 1, col, map)
		|| !flood_fill(map_copy, row - 1, col, map)
		|| !flood_fill(map_copy, row, col + 1, map)
		|| !flood_fill(map_copy, row, col - 1, map))
		return (FALSE);
	return (TRUE);
}

void	printf_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s", map[i++]);
}

void	add_rest(t_info *info)
{
	info->ray.map_x = (int)info->player.pos_x;
	info->ray.map_y = (int)info->player.pos_y;
	if (info->player.facing == 'N' || info->player.facing == 'S')
		init_camera_start_SN(info);
	if(info->player.facing == 'E' || info->player.facing == 'W')
		init_camera_start_EO(info);
	info->map.grid[(int)info->player.pos_y][(int)info->player.pos_x] = '0';
}
