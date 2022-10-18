/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:38:44 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/17 16:41:50 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_rt	*init_rt(void)
{
	t_rt	*rt;

	rt = malloc(sizeof(t_rt));
	if (!rt)
		return (NULL);
	ft_bzero(rt, sizeof(t_rt));
	rt->trash = NULL;
	rt->mlx = mlx_init();
	rt->win = mlx_new_window(rt->mlx, W_W, W_H, "miniRT");
	rt->img = malloc(sizeof(t_img));
	rt->img->img = mlx_new_image(rt->mlx, W_W, W_H);
	rt->img->addr = mlx_get_data_addr(rt->img->img, &rt->img->bpp,
			&rt->img->line_lgth, &rt->img->endian);
	mlx_hook(rt->win, 17, 1<<17, red_cross, rt);
	mlx_hook(rt->win, 2, 1L << 0, key_hook, rt);
	return (rt);
}
