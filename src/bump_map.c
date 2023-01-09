/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:07:36 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/09 19:30:42 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "data_struct.h"
#include "color.h"

t_u normalize_black_and_white(int color)
{
	return (get_r(color) / 255.0);
}

int	color_at(t_img *img, t_2dp *pos)
{
	char	*dst;
	int		x;
	int		y;

	x = (int)floor(pos->x) % img->x;
	y = (int)floor(pos->y) % img->y;
	if (x >= img->x || y >= img->y || x < 0 || y < 0)
	{
		ft_printf("invalid call to color_at() *bump_map.c*\n");
		return (0);
	}
	dst = img->addr + (y * img->line_lgth + x * (img->bpp / 8));
	return (*(int *)dst);
}

t_u height_at(t_img *img, t_2dp *pos)
{
	return (normalize_black_and_white(color_at(img, pos)));
}

t_tuple normal_perturbation(t_img *img, t_2dp *pos)
{
	t_tuple	per;
	t_u		denom;
	t_u		tmp;

	per.w = 0;
	denom = height_at(img, &(t_2dp){pos->x + 1, pos->y});
	denom -= height_at(img, &(t_2dp){pos->x, pos->y});
	denom *= denom;
	tmp = height_at(img, &(t_2dp){pos->x, pos->y + 1});
	tmp -= height_at(img, &(t_2dp){pos->x, pos->y});
	tmp *= tmp;
	denom += tmp;
	denom += 1.0;
	per.x = -height_at(img, &(t_2dp){pos->x + 1, pos->y});
	per.x += height_at(img, &(t_2dp){pos->x, pos->y});
	per.x /= denom;
	per.y = -height_at(img, &(t_2dp){pos->x, pos->y + 1});
	per.y += height_at(img, &(t_2dp){pos->x, pos->y});
	per.y /= denom;
	per.z = 1 / denom;
	return (per);
}
