/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:53:27 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/14 06:09:05 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "checker.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

int get_color_checker(t_2dp pos, t_intersect *inter)
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
	static t_2dp max = {-100, -100};
	static t_2dp min = {100, 100};

	printf("POS : %lf %lf %lf\n", pos->x, pos->y, pos->z);
	theta = atan2l(pos->x, pos->z);
	phi = acosl(pos->y);
	uv.x = 1 - ((theta / (2 * M_PI)) + 0.5);
	uv.y = 1 - (phi / M_PI);
	max.y = uv.y;
	if (isnan(max.y))
	{
		ft_printf("coucou\n");
		//usleep(300000);
	}
	if (uv.x > max.x || uv.x < min.x || uv.y > max.y || uv.y < min.y)
	{
		max.x = (uv.x > max.x) ? uv.x : max.x;
		max.y = (uv.y > max.y) ? uv.y : max.y;
		min.x = (uv.x < min.x) ? uv.x : min.x;
		min.y = (uv.y < min.y) ? uv.y : min.y;
		printf("%lf %lf %lf %lf\n", max.x, max.y, min.x, min.y);
	}
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
