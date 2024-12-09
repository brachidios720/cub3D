/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-06 17:16:52 by raphael           #+#    #+#             */
/*   Updated: 2024-12-06 17:16:52 by raphael          ###   ########.fr       */
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


// void       draw_wall_slice2(t_info *info, int x, t_window *window)
// {

//     int color ;
//     t_texture *tex = &info->texture[info->ray.texture_id];
//     int y ;

//     if(info->ray.side == 0)
//         tex->wall_x = info->player.pos_y + (info->ray.perpwalldist * info->ray.raydir_y);
//     else
//         tex->wall_x = info->player.pos_x + (info->ray.perpwalldist * info->ray.raydir_x);
//     tex->wall_x -= floor(tex->wall_x); 

//     tex->tex_x = (int)(tex->wall_x * (double)tex->width);
//     if((info->ray.side == 0 && info->ray.raydir_x > 0) || (info->ray.side == 1 && info->ray.raydir_y < 0))
//         tex->tex_x = tex->width - tex->tex_x -1;

//     tex->step = 1.0 * tex->height / info->render.lineheight;
//     tex->texpos = (info->render.drawstart - HEIGHT / 2 + info->render.lineheight / 2) * tex->step;
//     y = info->render.drawstart;

//     while(y <= info->render.drawend)
//     {
//         tex->tex_y = (int)tex->texpos & (tex->height - 1);
//         tex->texpos += tex->step;

//         color = tex->data[tex->tex_y * tex->width + tex->tex_x];
        
//         if(info->ray.side == 1)
//             color = (color & 0xFEFEFE) >> 1;
//         set_pixel_color(window->img, x, y, color);
//         y++;
//     }
// }   
int	get_pix_color(t_texture texture, int x, int y)
{
	return (*(int *)(texture.img->img_data_address + (4 * texture.img->size_line * y) + (4 * x)));
}

void    draw_wall_slice3(t_info *info, int x, t_img_info *img)
{
    (void)img;
    int pixel_color;
    if(info->ray.side ==  0)
        info->texture->wall_x = info->player.pos_y + info->ray.perpwalldist * info->ray.raydir_y;
    else
        info->texture->wall_x = info->player.pos_x + info->ray.perpwalldist * info->ray.raydir_x;
    info->texture->wall_x -= floor((info->texture->wall_x));

    info->texture->tex_x = (int)(info->texture->wall_x * (double)info->texture->width);
    if(info->ray.side == 0 && info->ray.raydir_y > 0)
        info->texture->tex_x = info->texture->width - info->texture->tex_x - 1;
    if(info->ray.side == 1 && info->ray.raydir_y < 0)
        info->texture->tex_x = info->texture->width - info->texture->tex_x - 1;

    info->texture->step = 1.0 * info->texture->height / info->render.lineheight;

    info->texture->texpos = (info->render.drawstart - HEIGHT / 2 + info->render.lineheight / 2) * info->texture->step;
    int y = info->render.drawstart;
    while( y < info->render.drawend)
    {
        info->texture->tex_y = (int)info->texture->texpos & (info->texture[info->ray.texture_id].height - 1);
        info->texture->texpos += info->texture->step;

        pixel_color = info->texture[info->ray.texture_id].img->img_data_address[info->texture->tex_y * info->texture[info->ray.texture_id].width + info->texture->tex_x];

        if(x >= 0 && x < info->mlx->width && y >= 0 && y < info->mlx->height)
            get_pix_color(info->texture[info->ray.texture_id], x, y);
        set_pixel_color(info->mlx->img, x, y, pixel_color);
        y++;
    }

}

