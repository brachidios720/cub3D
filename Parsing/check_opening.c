/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opening.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:01:04 by almarico          #+#    #+#             */
/*   Updated: 2024/11/28 20:48:18 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_opening(char *str, int *fd)
{
	*fd = open(str, O_DIRECTORY);
	if (*fd != -1 && *fd > 2)
		return (close(*fd), write_message(ERR_DIR), FAIL);
	*fd = open(str, O_RDONLY);
	if (*fd == -1)
		return (write_message(ERR_OPEN), FAIL);
	return (SUCCESS);
}
