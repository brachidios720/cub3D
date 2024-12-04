/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:58:21 by almarico          #+#    #+#             */
/*   Updated: 2024/12/04 18:53:25 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_map(char *line)
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

int	check_line(t_info *info, char *line)
{
	if (ft_strstr(line, NORTH) || ft_strstr(line, EAST)
		|| ft_strstr(line, SOUTH) || ft_strstr(line, WEST))
	{
		if (fill_texture(info, line) == FAIL)
			return (FAIL);
	}
	else if (ft_strstr(line, FLOOR) || ft_strstr(line, CEILING))
	{
		if (fill_color(info, line) == FAIL)
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
	if (i && line[i] == '\0')
		return (TRUE);
	return (line[i]);
}

int	fill_info(t_info *info, t_parse *parsing)
{
	int	i;

	i = -1;
	while (parsing->tab[++i])
	{
		if (contain_only_isspace(parsing->tab[i]) != TRUE
			&& everything_is_set(info) == FAIL)
			if (check_line(info, parsing->tab[i]) == FAIL)
				return (free_double_tab(parsing->tab), FAIL);
		if (everything_is_set(info) == SUCCESS)
			break ;
	}
	while (parsing->tab[++i])
	{
		if (contain_only_isspace(parsing->tab[i]) != TRUE)
			if (everything_is_set(info) == SUCCESS
				&& check_map(parsing->tab[i]) == SUCCESS)
				if (fill_map(info, parsing, &i) == FAIL)
					return (FAIL);
	}
	free_double_tab(parsing->tab);
	if (everything_is_set(info) == FAIL || fill_player(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
