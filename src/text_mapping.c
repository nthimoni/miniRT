/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:53:27 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/11 18:17:12 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "checker.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

int get_color_checker(t_2dp pos, t_intersect *inter)
{
	int		x2;
	int		y2;
	t_otype	type;

	type = inter->obj->type;
	if (type == SPHERE)
	{
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

t_2dp uv_sphere(t_tuple *pos)
{
	t_u		phi;
	t_u		theta;
	t_2dp	ret;

	phi = acosl(pos->y);
	theta = atan2l(pos->x, pos->z);
	ret.x = (1 - ((theta / M_PI_2) + 0.5)) / 4;
	ret.y = 1 - (phi / M_PI);
	return (ret);
}


t_2dp uv_plan(t_tuple *pos)
{
	t_2dp	ret;

	ret.x = fmod(pos->x / 40, 1);
	ret.y = fmod(pos->z / 40, 1);
	return (ret);
}
