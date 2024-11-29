/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:11 by raphael           #+#    #+#             */
/*   Updated: 2024/11/29 13:57:37 by almarico         ###   ########.fr       */
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
		return (FAIL);
	if (check_opening(*argv, &parsing.fd_map) == FAIL)
		return (FAIL);
	if (get_map_info(&parsing) == FAIL)
		return (FAIL);
	if (fill_info(&info, &parsing) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
