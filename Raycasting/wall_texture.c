/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:16:52 by raphael           #+#    #+#             */
/*   Updated: 2024/12/10 18:57:06 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_tall_for_texture(t_info *info)
{
	info->render.lineheight = (int)(HEIGHT / info->ray.perpwalldist);
	info->render.drawstart = (-info->render.lineheight / 2) + (HEIGHT / 2);
	if (info->render.drawstart < 0)
		info->render.drawstart = 0;
	info->render.drawend = (info->render.lineheight / 2) + (HEIGHT / 2);
	if (info->render.drawend >= HEIGHT)
		info->render.drawend = HEIGHT - 1;
}

int	get_pix_color(t_texture texture, int x, int y)
{
	return (*(int *)(texture.img.img_data_address + (4 * texture.width * y) + (4
			* x)));
}

void	check_side(t_info *info)
{
	info->texture[info->ray.texture_id].tex_x = \
		(int)(info->texture[info->ray.texture_id].wall_x \
		* (double)info->texture[info->ray.texture_id].width);
	if (info->ray.side == 0 && info->ray.raydir_y > 0)
		info->texture[info->ray.texture_id].tex_x = \
			info->texture[info->ray.texture_id].width \
			- info->texture[info->ray.texture_id].tex_x - 1;
	if (info->ray.side == 1 && info->ray.raydir_y < 0)
		info->texture[info->ray.texture_id].tex_x = \
			info->texture[info->ray.texture_id].width \
			- info->texture[info->ray.texture_id].tex_x - 1;
}

void	draw_wall_slice3(t_info *info, int x, t_img_info *img)
{
	(void)img;
	if (info->ray.side == 0)
		info->texture[info->ray.texture_id].wall_x = info->player.pos_y
			+ info->ray.perpwalldist * info->ray.raydir_y;
	else
		info->texture[info->ray.texture_id].wall_x = info->player.pos_x
			+ info->ray.perpwalldist * info->ray.raydir_x;
	info->texture[info->ray.texture_id].wall_x
		-= floor((info->texture[info->ray.texture_id].wall_x));
	info->texture[info->ray.texture_id].step = 1.0
		* info->texture[info->ray.texture_id].height / info->render.lineheight;
	info->texture[info->ray.texture_id].texpos = (info->render.drawstart
			- (float)HEIGHT / 2 + (float)info->render.lineheight / 2)
		* info->texture[info->ray.texture_id].step;
	check_side(info);
	draw_wall(info, x);
}

void	draw_wall(t_info *info, int x)
{
	int	pixel_color;
	int	y;

	y = info->render.drawstart;
	while (y < info->render.drawend)
	{
		info->texture[info->ray.texture_id].tex_y = \
			(int)info->texture[info->ray.texture_id].texpos \
			& (info->texture[info->ray.texture_id].height - 1);
		info->texture[info->ray.texture_id].texpos += \
			info->texture[info->ray.texture_id].step;
		if (x >= 0 && x < info->mlx->width && y >= 0 && y < info->mlx->height)
			pixel_color = get_pix_color(info->texture[info->ray.texture_id],
					info->texture[info->ray.texture_id].tex_x,
					info->texture[info->ray.texture_id].tex_y);
		set_pixel_color(info->mlx->img, x, y, pixel_color);
		y++;
	}
}
