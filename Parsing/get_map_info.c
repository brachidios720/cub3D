/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:49:56 by almarico          #+#    #+#             */
/*   Updated: 2024/12/04 18:46:20 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_map_info(t_parse *parsing)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 128)
		parsing->tab[i++] = NULL;
	line = get_next_line(parsing->fd_map);
	i = 0;
	while (line != NULL)
	{
		parsing->tab[i] = ft_strdup(line);
		if (!parsing->tab[i])
			return (free_double_tab(parsing->tab), write_message(ERR_COPY), \
			close(parsing->fd_map), FAIL);
		free(line);
		line = get_next_line(parsing->fd_map);
		i++;
	}
	close(parsing->fd_map);
	return (SUCCESS);
}
