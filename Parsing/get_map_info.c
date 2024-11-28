/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:49:56 by almarico          #+#    #+#             */
/*   Updated: 2024/11/28 21:23:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	transform_list_to_tab(char **tab, t_list *head)
{
	t_list	*tmp;
	int		size;

	tmp = head;
	size = ft_lstsize(tmp);
	tab = malloc(size * sizeof(char *));
	if (!tab)
		return (free_list(&head), write_message(ERR_MALLOC), FAIL);
	tab[size] = NULL;
	size = 0;
	while (tab[size] != NULL)
	{
		tab[size] = ft_strdup((char *)tmp->content);
		if (!tab[size])
			return (free_double_tab(tab), write_message(ERR_MALLOC), FAIL);
		size++;
		tmp = tmp->next;
	}
	free_list(&head);
	return (SUCCESS);
}

int	get_map_info(int fd)
{
	t_list	*map;
	t_list	*head;
	char	**tab;

	tab = NULL;
	map = ft_lstnew(NULL);
	ft_lstinit(map);
	map->content = get_next_line(fd);
	if (!map->content)
		return (close(fd), write_message(ERR_EMPTY), FAIL);
	head = map;
	while (map->content != NULL)
	{
		ft_lstadd_back(&map, ft_lstnew(NULL));
		map = map->next;
		map->content = get_next_line(fd);
	}
	if (transform_list_to_tab(tab, head) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
