/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 12:49:11 by raphael           #+#    #+#             */
/*   Updated: 2024/11/28 13:45:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



char **create_map(void) 
{
	char **map = malloc(sizeof(char *) * 11);
	map[0] = "212121212121212";
	map[1] = "100000000000002";
	map[2] = "200000004400001";
	map[3] = "100000000000002";
	map[4] = "200003000004001";
	map[5] = "100000000000002";
	map[6] = "200000003000001";
	map[7] = "100400000004002";
	map[8] = "200000000000001";
	map[9] = "121212121212121";
	map[10]	= NULL;

	return(map);
}

void	init_map(t_info *info)
{
	info->map.grid = create_map();
	for (int i = 0; i < 10; i++) {
        printf("%s\n", info->map.grid[i]);
    }
}

int	main(void)
{
	t_info info;

	init_map(&info);
	//info = malloc(sizeof(t_info));
	raycasting_entry(&info);
	return (SUCCESS);
}
