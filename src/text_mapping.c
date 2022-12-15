/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:53:27 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/15 03:27:06 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "checker.h"
#include <math.h>

int get_color_checker(t_2dp pos)
{
	int x2;
	int y2;
	x2 = floorl(pos.x * CHECKER_WIDTH);
	y2 = floorl(pos.y * CHECKER_HEIGHT);
	if ((x2 + y2) % 2 == 0)
		return (CHECKER_COL_1);
	return (CHECKER_COL_2);
}

t_2dp sphere_pos_to_2d(t_tuple *pos, t_u radius)
{
	t_u		phi;
	t_u		raw_u;
	t_2dp	ret;

	phi = acosl(pos->y/ radius);
	raw_u = atan2l(pos->x, pos->z) / (2 * M_PI);
	ret.x = 0.5 - raw_u;
	ret.y = 1 - phi / M_PI;
	return (ret);
}
