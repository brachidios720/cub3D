/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:11 by raphael           #+#    #+#             */
/*   Updated: 2024/11/28 20:51:08 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		fd_map;

	(void)info;
	if (argc != 2)
		return (write_message(ERR_ARG), FAIL);
	argv++;
	if (check_cub_format(*argv) == FAIL)
		return (FAIL);
	if (check_opening(*argv, &fd_map) == FAIL)
		return (FAIL);
	if (get_map_info(fd_map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
