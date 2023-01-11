/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:53:27 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/15 20:13:47 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "checker.h"
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

t_2dp sphere_pos_to_2d(t_tuple *pos, t_u diameter)
{
	t_u		phi;
	t_u		raw_u;
	t_2dp	ret;

	phi = acosl(pos->y / (diameter / 2));
	raw_u = atan2l(pos->x, pos->z) / (2 * M_PI);
	ret.x = 1 - (raw_u + 0.5);
	ret.y = 1 - phi / M_PI;
	return (ret);
}


t_2dp plan_pos_to_2d(t_tuple *pos)
{
	t_2dp	ret;
	long double useless;

	ret.x = modfl(pos->x / 40, &useless);
	ret.y = modfl(pos->z / 40, &useless);
	return (ret);
}
