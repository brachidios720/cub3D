/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:16:52 by raphael           #+#    #+#             */
/*   Updated: 2024/12/09 16:00:39 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


t_texture   *get_texture(t_info *info)
{
    if(info->ray.side == 0)
    {
        if(info->ray.raydir_x > 0)
            return(&info->texture[T_SOUTH]);
        else
            return(&info->texture[T_NORTH]);   
    }
    else
    {
        if(info->ray.raydir_y > 0)
            return(&info->texture[T_EAST]);
        else
            return(&info->texture[T_WEST]);
    }
}
 
int	get_pix_color(t_texture texture, int x, int y)
{
	return (*(int *)(texture.img.img_data_address + (4 * texture.width * y) + (4 * x)));
}

void    draw_wall_slice3(t_info *info, int x, t_img_info *img)
{
    (void)img;
    int pixel_color;
    if(info->ray.side ==  0)
        info->texture[info->ray.texture_id].wall_x = info->player.pos_y + info->ray.perpwalldist * info->ray.raydir_y;
    else
        info->texture[info->ray.texture_id].wall_x = info->player.pos_x + info->ray.perpwalldist * info->ray.raydir_x;
    info->texture[info->ray.texture_id].wall_x -= floor((info->texture[info->ray.texture_id].wall_x));
    info->texture[info->ray.texture_id].step = 1.0 * info->texture[info->ray.texture_id].height / info->render.lineheight;
    info->texture[info->ray.texture_id].texpos = (info->render.drawstart - HEIGHT / 2 + info->render.lineheight / 2) * info->texture[info->ray.texture_id].step;
    int y = info->render.drawstart;
    while( y < info->render.drawend)
    {
        info->texture[info->ray.texture_id].tex_y = (int)info->texture[info->ray.texture_id].texpos & (info->texture[info->ray.texture_id].height - 1);
        info->texture[info->ray.texture_id].texpos += info->texture[info->ray.texture_id].step;
        if(x >= 0 && x < info->mlx->width && y >= 0 && y < info->mlx->height)
            pixel_color = get_pix_color(info->texture[info->ray.texture_id], info->texture[info->ray.texture_id].tex_x, info->texture[info->ray.texture_id].tex_y);
        set_pixel_color(info->mlx->img, x, y, pixel_color);
        y++;
    }
}

void    check_side(t_info *info)
{
    info->texture[info->ray.texture_id].tex_x = (int)(info->texture[info->ray.texture_id].wall_x * (double)info->texture[info->ray.texture_id].width);
    if(info->ray.side == 0 && info->ray.raydir_y > 0)
        info->texture[info->ray.texture_id].tex_x = info->texture[info->ray.texture_id].width - info->texture[info->ray.texture_id].tex_x - 1;
    if(info->ray.side == 1 && info->ray.raydir_y < 0)
        info->texture[info->ray.texture_id].tex_x = info->texture[info->ray.texture_id].width - info->texture[info->ray.texture_id].tex_x - 1;
}
