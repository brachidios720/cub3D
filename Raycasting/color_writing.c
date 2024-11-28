/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_writing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:37:26 by almarico          #+#    #+#             */
/*   Updated: 2024/11/28 13:37:39 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_pixel_color(t_img_info img, int pos_x, int pos_y, int color)
{
	int		offset;
	char	*dst;

	offset = (pos_y * img.size_line + pos_x * (img.bits_per_pixel / 8));
	dst = img.img_data_address + offset;
	*(unsigned int *)dst = color;
}
