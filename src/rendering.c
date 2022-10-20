/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:54:45 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/20 17:55:36 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	print_axis(t_rt *rt)
{
	int	i;
	int	j;

	i = W_W / 2;
	j = 0;
	while (j++ < W_H)
		my_mlx_pixel_put(rt, i, j, create_trgb(0, 255, 255, 255));
	i = 0;
	j = W_H / 2;
	while (i++ < W_W)
		my_mlx_pixel_put(rt, i, j, create_trgb(0, 255, 255, 255));
	return ;
}
