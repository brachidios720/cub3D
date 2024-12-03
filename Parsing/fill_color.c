/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:42:51 by almarico          #+#    #+#             */
/*   Updated: 2024/12/03 11:13:46 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_rgb(char *line, int *r, int *g, int *b)
{
	int	i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]) == 0)
		i++;
	*r = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]) == 0)
		i++;
	*g = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]) == 0)
		i++;
	*b = ft_atoi(&line[i]);
}

int	fill_color(t_info *info, char *line)
{
	int	r;
	int	g;
	int	b;

	if (ft_strstr(line, FLOOR))
	{
		get_rgb(line, &r, &g, &b);
		info->map.floor_color = set_color(0, r, g, b);
	}
	else if (ft_strstr(line, CEILING))
	{
		get_rgb(line, &r, &g, &b);
		info->map.ceiling_color = set_color(0, r, g, b);
	}
	return (SUCCESS);
}
