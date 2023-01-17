/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:42:34 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/20 17:28:29 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	red_cross(t_rt *rt)
{
	ft_printf("Sayonara !\n");
	mlx_loop_end(rt->mlx);
	return (1);
}

int	key_hook(int keycode, t_rt *rt)
{
	if (keycode == 65307)
	{
		ft_printf("Auf Wiedersehen Herr Muller !\n");
		mlx_loop_end(rt->mlx);
	}
	return (1);
}

int	mouse_hook(int button, int x, int y, t_rt *rt)
{
	mlx_mouse_get_pos(rt->mlx, rt->win, &x, &y);
	printf("x = %d, y = %d\n", x, y);
	(void)button;
	return (1);
}
