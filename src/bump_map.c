/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:07:36 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/10 06:38:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "data_struct.h"
#include "color.h"
#include "mlx.h"
#include "vector.h"

t_u normalize_black_and_white(int color)
{
	return (get_r(color) / 255.0);
}

int	color_at(t_img *img, t_2dp pos)
{
	char	*dst;
	int		x;
	int		y;

	x = floor(pos.x * (img->x - 1));
	y = floor(pos.y * (img->y - 1));
	dst = img->addr + ((img->y - y) * img->line_lgth + x * (img->bpp / 8));
	//ft_printf("%d %d \n", x, y);
	return (*(int *)dst);
}

t_u height_at(t_img *img, t_2dp *pos)
{
	return (normalize_black_and_white(color_at(img, *pos)));
}

t_tuple normal_perturbation(t_img *img, t_2dp pos)
{
	t_tuple	per;
	t_u		denom;
	t_u		tmp;

	per.w = 0;
	denom = height_at(img, &(t_2dp){pos.x + 0.001, pos.y});
	denom -= height_at(img, &(t_2dp){pos.x, pos.y});
	denom *= denom;
	tmp = height_at(img, &(t_2dp){pos.x, pos.y + 0.001});
	tmp -= height_at(img, &(t_2dp){pos.x, pos.y});
	tmp *= tmp;
	denom += tmp;
	denom += 1.0;
	per.x = -height_at(img, &(t_2dp){pos.x + 0.001, pos.y});
	per.x += height_at(img, &(t_2dp){pos.x, pos.y});
	per.x /= denom;
	per.y = -height_at(img, &(t_2dp){pos.x, pos.y + 0.001});
	per.y += height_at(img, &(t_2dp){pos.x, pos.y});
	per.y /= denom;
	per.z = 1 / denom;
	norm_v3(&per);
	scale_v3(&per, 0.7);
	return (per);
}
