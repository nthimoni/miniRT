/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:14:48 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/03 23:56:03 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	clear_image(t_rt *rt)
{
	mlx_destroy_image(rt->mlx, rt->img->img);
	ft_bzero(rt->img, sizeof(t_img));
	rt->img->img = mlx_new_image(rt->mlx, W_W, W_H);
	rt->img->addr = mlx_get_data_addr(rt->img->img, &rt->img->bpp,
			&rt->img->line_lgth, &rt->img->endian);
	// Fonction pour dessiner la scene sur le raster space (l'ecran) a mettre en dessous
	// Ex : draw_scene(t_rt *rt);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->img,
		rt->img->x, rt->img->y);
}

void	my_mlx_pixel_put(t_rt *rt, int x, int y, int color)
{
	char	*dst;
	int		x2;
	int		y2;

	x2 = x + W_W / 2;
	y2 = y + W_H / 2;
	if (x2 > W_W || y2 > W_H || x2 <= 0 || y2 <= 0)
		return ;
	dst = rt->img->addr + (y2 * rt->img->line_lgth
			+ x2 * (rt->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->img, rt->img->x,
		rt->img->y);
	return (0);
}
