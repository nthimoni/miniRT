/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/03 23:58:25 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

int	main(void)
{
	ft_printf("Hello World!\n");
	return (0);
}

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
	if (!rt)
		return (free(rt), NULL);
	rt->img->img = mlx_new_image(rt->mlx, W_W, W_H);
	rt->img->addr = mlx_get_data_addr(rt->img->img, &rt->img->bpp,
			&rt->img->line_lgth, &rt->img->endian);
	mlx_loop(rt->mlx);
	return (0);
}
