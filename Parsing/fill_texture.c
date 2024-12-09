/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:43:41 by almarico          #+#    #+#             */
/*   Updated: 2024/12/04 18:45:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_texture(t_info *info, t_texture *texture, char *line)
{
	char	*filename;
	char	*tmp;
	int		i;

	if (texture->data)
		return (write_message(ERR_TEXTURE_EXIST), FAIL);
	tmp = ft_strstr(line, "./");
	if (tmp[0] == '\0')
		return (free(tmp), write_message(ERR_NO_XPM), FAIL);
	i = 0;
	while (tmp[i] && ft_isspace(tmp[i]) != 0)
		i++;
	filename = ft_substr(tmp, 0, i);
	if (!filename)
		return (free(tmp), write_message(ERR_MALLOC), FAIL);
	if (check_xpm_format(filename) == FAIL)
		return (free(filename), write_message(ERR_XPM_FORMAT), FAIL);
	texture->data = mlx_xpm_file_to_image(info->mlx->init_ptr, filename, \
									&texture->width, &texture->height);
	if (!texture->data)
		return (free(filename), write_message(ERR_XPM), FAIL);
	free(filename);
	return (SUCCESS);
}

int	fill_texture(t_info *info, char *line)
{
	int	texture_index;

	if (ft_strstr(line, NORTH))
		texture_index = T_NORTH;
	else if (ft_strstr(line, EAST))
		texture_index = T_EAST;
	else if (ft_strstr(line, SOUTH))
		texture_index = T_SOUTH;
	else if (ft_strstr(line, WEST))
		texture_index = T_WEST;
	if (get_texture(info, &info->texture[texture_index], line) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	init_texture(t_info *info)
{
	
}