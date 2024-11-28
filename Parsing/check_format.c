/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:51:40 by almarico          #+#    #+#             */
/*   Updated: 2024/11/28 20:00:05 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_cub_format(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i - 3] != '.' && str[i - 2] != 'c'
		&& str[i - 1] != 'u' && str[i] != 'b')
		return (FAIL);
	return (SUCCESS);
}

int	check_xpm_format(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i - 3] != '.' && str[i - 2] != 'x'
		&& str[i - 1] != 'p' && str[i] != 'm')
		return (FAIL);
	return (SUCCESS);
}
