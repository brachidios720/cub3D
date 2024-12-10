/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:43:21 by almarico          #+#    #+#             */
/*   Updated: 2024/12/10 15:30:41 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	everything_is_set(t_info *info)
{
	if (!info->texture[T_NORTH].img.img_ptr
		|| !info->texture[T_EAST].img.img_ptr
		|| !info->texture[T_SOUTH].img.img_ptr
		|| !info->texture[T_WEST].img.img_ptr)
		return (FAIL);
	if (info->map.floor_color == -1 || info->map.ceiling_color == -1)
		return (FAIL);
	return (SUCCESS);
}

int	fill_map(t_info *info, t_parse *parsing, int *i)
{
	int	start;
	int	j;

	start = *i;
	if (everything_is_set(info) == FAIL)
		return (FAIL);
	while (parsing->tab[*i])
	{
		if (contain_only_isspace(parsing->tab[*i]) == TRUE && parsing->tab[*i \
			+ 1] != NULL)
			return (free_double_tab(parsing->tab), FAIL);
		(*i)++;
	}
	info->map.grid = malloc((*i - start + 1) * sizeof(char *));
	if (!info->map.grid)
		return (write_message(ERR_MALLOC), FAIL);
	info->map.height = *i - start + 1;
	info->map.grid[*i - start] = NULL;
	j = 0;
	while (start < *i)
		info->map.grid[j++] = ft_strdup(parsing->tab[start++]);
	info->map.width = ft_strlen(info->map.grid[0]);
	return (SUCCESS);
}
