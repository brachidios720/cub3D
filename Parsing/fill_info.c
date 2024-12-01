/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:58:21 by almarico          #+#    #+#             */
/*   Updated: 2024/11/30 22:45:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_map(t_info *info, t_parse *parsing, char *line)
{
	int	j;

	j = -1;
	while (line[++j])
	{
		if (ft_is_in_base(line[j], MAP_CHARSET) == 0)
			return (SUCCESS);
	}
	return (FAIL);
}

int	check_line(t_info *info, t_parse *parsing, char *line)
{
	if (ft_strstr(line, NORTH) || ft_strstr(line, EAST)
		|| ft_strstr(line, SOUTH) || ft_strstr(line, WEST))
	{
		if (fill_texture(info, parsing, line) == FAIL)
			return (FAIL);
	}
	else if (ft_strstr(line, FLOOR) || ft_strstr(line, CEILING))
	{
		if (fill_color(info, parsing, line) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

int	contain_only_isspace(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]) == 0)
		i++;
	return (line[i]);
}

int	fill_info(t_info *info, t_parse *parsing)
{
	int	i;

	i = 0;
	while (parsing->tab[i])
	{
		if (contain_only_isspace(parsing->tab[i]) != TRUE)
		{
			if (check_line(info, parsing, parsing->tab[i]) == FAIL)
				return (FAIL);
			else if (check_map(info, parsing, parsing->tab[i]) == SUCCESS)
			{
				if (fill_map(info, parsing, &i) == FAIL)
					return (FAIL);
			}
		}
		if (parsing->tab[i])
			i++;
	}
	if (fill_player(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
