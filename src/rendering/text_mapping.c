/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:53:27 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 02:55:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "checker.h"
#include "libft.h"
#include "vector.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

int	get_color_checker(t_2dp pos, t_intersect *inter)
{
	int		x2;
	int		y2;
	t_otype	type;

	type = inter->obj->type;
	if (type == SPHERE)
	{
		pos.x *= 4;
		x2 = floorl(pos.x * CHECKER_WIDTH_S);
		y2 = floorl(pos.y * CHECKER_HEIGHT_S);
	}
	else
	{
		x2 = floorl(pos.x * CHECKER_WIDTH_P);
		y2 = floorl(pos.y * CHECKER_HEIGHT_P);
	}
	if ((x2 + y2) % 2 == 0)
		return (CHECKER_COL_1);
	return (CHECKER_COL_2);
}

t_2dp	uv_plan(t_tuple *pos)
{
	t_2dp	uv;

	uv.x = fmod(pos->x, 1);
	uv.y = fmod(pos->z, 1);
	return (uv);
}

t_2dp	uv_sphere(t_tuple *pos)
{
	t_2dp	uv;
	double	theta;
	double	phi;

	theta = atan2l(pos->x, pos->z);
	phi = acosl(pos->y);
	uv.x = 1 - ((theta / (2 * M_PI)) + 0.5);
	uv.y = 1 - (phi / M_PI);
	if (uv.x > 1)
		uv.x -= 1;
	if (uv.y > 1)
		uv.y -= 1;
	return (uv);
}

t_2dp	uv_cylindre(t_tuple *pos)
{
	t_2dp	uv;
	double	theta;

	theta = atan2(pos->x, pos->z);
	uv.x = 1 - ((theta / (2 * M_PI)) + 0.5);
	uv.y = fmod(pos->y, 1);
	return (uv);
}

t_2dp	uv_cone(t_tuple *pos)
{
	t_2dp	uv;
	double	theta;
	double	radius;

	radius = pos->x * pos->x + pos->z * pos->z;
	theta = atan2(pos->x, pos->z);
	uv.x = 1 - ((theta / (2 * M_PI)) + 0.5);
	uv.y = fmod(sqrt(radius), 1);
	return (uv);
}
