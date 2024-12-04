/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:11 by raphael           #+#    #+#             */
/*   Updated: 2024/12/04 09:53:46 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_parse	parsing;

	(void)info;
	if (argc != 2)
		return (write_message(ERR_ARG), FAIL);
	argv++;
	if (check_cub_format(*argv) == FAIL)
		return (write_message(ERR_CUB_FORMAT), FAIL);
	if (check_opening(*argv, &parsing.fd_map) == FAIL)
		return (FAIL);
	if (get_map_info(&parsing) == FAIL)
		return (FAIL);
	init_info(&info);
	if (fill_info(&info, &parsing) == FAIL)
		return (free_info(&info), FAIL);
	raycasting_entry(&info);
	return (SUCCESS);
}
