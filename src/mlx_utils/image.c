/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:14:48 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/11 17:26:23 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	clear_image(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->img,
		rt->img->x, rt->img->y);
}

void	my_mlx_pixel_put(t_rt *rt, int x, int y, int color)
{
	char	*dst;

	if (x >= W_W || y >= W_H || x < 0 || y < 0)
		return ;
	dst = rt->img->addr + (y * rt->img->line_lgth + x * (rt->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->img, rt->img->x,
		rt->img->y);
	return (0);
}