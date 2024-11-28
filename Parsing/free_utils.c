/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:01:52 by almarico          #+#    #+#             */
/*   Updated: 2024/11/28 21:16:21 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
}

void	free_double_int(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
}

void	free_info(t_info *info)
{
	free_double_tab(info->map.grid);
	free_double_int(info->buffer, info->buffer_size);
	free(info->texture.data);
}

void	free_list(t_list **lst)
{
	t_list	*nav;

	while (*lst)
	{
		nav = (*lst)->next;
		free((*lst)->content);
		free((*lst));
		*lst = nav;
	}
	free(*lst);
	*lst = NULL;
}
