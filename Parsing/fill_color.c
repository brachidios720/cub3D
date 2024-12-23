/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:42:51 by almarico          #+#    #+#             */
/*   Updated: 2024/12/10 14:05:47 by almarico         ###   ########.fr       */
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
	while (line[i] && ft_isdigit(line[i]) == 0 && line[i] != '-')
		i++;
	if (line[i])
		*r = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]) != 0 && line[i] != '-')
		i++;
	while (line[i] && ft_isdigit(line[i]) == 0)
		i++;
	if (line[i])
		*g = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]) != 0 && line[i] != '-')
		i++;
	while (line[i] && ft_isdigit(line[i]) == 0)
		i++;
	if (line[i])
		*b = ft_atoi(&line[i]);
}

int	fill_color(t_info *info, char *line)
{
	int	r;
	int	g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	if (ft_strstr(line, FLOOR))
	{
		get_rgb(line, &r, &g, &b);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			return (write_message(ERR_COLOR), FAIL);
		info->map.floor_color = set_color(0, r, g, b);
	}
	else if (ft_strstr(line, CEILING))
	{
		get_rgb(line, &r, &g, &b);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			return (write_message(ERR_COLOR), FAIL);
		info->map.ceiling_color = set_color(0, r, g, b);
	}
	return (SUCCESS);
}
