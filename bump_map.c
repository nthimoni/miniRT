/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:07:36 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/11 06:38:41 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "data_struct.h"
#include "color.h"
#include "mlx.h"
#include "vector.h"
#include "scene.h"

t_u normalize_black_and_white(int color)
{
	t_u ret;

	ret = get_r(color) / 255.0;
	return (ret);
}

int	color_at(t_img *img, t_2dp pos)
{
	char	*dst;
	int		x;
	int		y;

	x = floor(pos.x * (img->x - 1)) + (img->x - img->x * (1.1/50));
	y = floor(pos.y * (img->y - 1)) + (img->y - img->y * (-2.0/50));
	y %= img->y - 1;

	dst = img->addr + ((img->y - y) * img->line_lgth + x * (img->bpp / 8));
	//ft_printf("%d %d \n", x, y);
	return (*(int *)dst);
}

t_u height_at(t_img *img, t_2dp *pos)
{
	return (normalize_black_and_white(color_at(img, *pos)));
}

t_tuple normal_perturbation(t_img *img, t_2dp pos, t_tuple *normal)
{
	t_tuple	perturb;
	t_u		denom;
	t_u		tmp;
	t_2dp	unit;
	t_u		m_rot[4][4];
	t_u		m_rot_inv[4][4];

	perturb.w = 0;
	unit.x = 1.0 / img->x;
	unit.y = 1.0 / img->y;
	denom = height_at(img, &(t_2dp){pos.x + unit.x, pos.y});
	denom -= height_at(img, &(t_2dp){pos.x, pos.y});
	denom *= denom;
	tmp = height_at(img, &(t_2dp){pos.x, pos.y + unit.y});
	tmp -= height_at(img, &(t_2dp){pos.x, pos.y});
	tmp *= tmp;
	denom += tmp;
	denom += 1.0;
	perturb.x = -height_at(img, &(t_2dp){pos.x + unit.x, pos.y});
	perturb.x += height_at(img, &(t_2dp){pos.x, pos.y});
	perturb.x /= denom;
	perturb.y = -height_at(img, &(t_2dp){pos.x, pos.y + unit.y});
	perturb.y += height_at(img, &(t_2dp){pos.x, pos.y});
	perturb.y /= denom;
	perturb.z = 1 / denom;
	get_matrix_align_v1_v2(m_rot, *normal, create_tuple_pts(0, 0, -1, 0));
	invert_matrix_4(m_rot, m_rot_inv);
	mult_tuple_matrix_4(&perturb, m_rot_inv, perturb);
	norm_v3(&perturb);
	scale_v3(&perturb, 0.99);
	return (perturb);
}
