/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:46:19 by almarico          #+#    #+#             */
/*   Updated: 2024/12/03 12:34:25 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && ft_is_in_base(map[i][j], "\t 01NSEW") == 0)
			j++;
		if (map[i][j] && ft_is_in_base(map[i][j], "\t 01NSEW") == 1)
			return (write_message(ERR_CHAR_MAP), FAIL);
		i++;
	}
	return (SUCCESS);
}

int	set_player_position(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'W')
			{
				if (player->pos_x != -1 || player->pos_y != -1)
					return (write_message(ERR_MULTIPLE_PLAYER), FAIL);
				player->pos_x = j;
				player->pos_y = i;
				player->facing = map[i][j];
				return (SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (write_message(ERR_NO_PLAYER), FAIL);
}

int	check_player_position(t_map map, t_player player)
{
	int	is_there_a_zero;

	is_there_a_zero = FALSE;
	if (player.pos_x > 0 && player.pos_y > 0
		&& player.pos_x < map.width - 1 && player.pos_y < map.height - 1)
	{
		if (map.grid[(int)player.pos_y][(int)player.pos_x - 1] == '0'
			|| map.grid[(int)player.pos_y][(int)player.pos_x + 1] == '0'
			|| map.grid[(int)player.pos_y - 1][(int)player.pos_x] == '0'
			|| map.grid[(int)player.pos_y + 1][(int)player.pos_x] == '0')
			is_there_a_zero = TRUE;
	}
	if (is_there_a_zero == TRUE)
		return (SUCCESS);
	return (write_message(ERR_NO_SPACE), FAIL);
}

int	check_map_delimitation(char **grid, t_map map)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = malloc((map.height + 1) * sizeof(char *));
	if (!map_copy)
		return (write_message(ERR_MALLOC), FAIL);
	i = -1;
	while (grid[++i])
		map_copy[i] = ft_strdup(grid[i]);
	map_copy[i] = NULL;
	i = -1;
	while (map_copy[++i] != NULL)
	{
		j = -1;
		while (map_copy[i][++j])
		{
			if (map_copy[i][j] == 'N' || map_copy[i][j] == 'E'
			|| map_copy[i][j] == 'S' || map_copy[i][j] == 'W')
			{
				if (flood_fill(map_copy, i, j, map) == STOP)
					return (write_message(ERR_MAP), FAIL);
			}
		}
	}
	return (SUCCESS);
}

int	fill_player(t_info *info)
{
	if (check_lines(info->map.grid) == FAIL)
		return (FAIL);
	if (set_player_position(info->map.grid, &info->player) == FAIL)
		return (FAIL);
	if (check_player_position(info->map, info->player) == FAIL)
		return (FAIL);
	if (check_map_delimitation(info->map.grid, info->map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
