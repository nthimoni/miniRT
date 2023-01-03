/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:55:29 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/03 10:10:30 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_bool	solve_quadratic(t_intersect *inter, t_quadra q)
{
	t_u	q1;
	t_u	q2;

	q.disc = pow(q.b, 2) - 4 * q.a * q.c;
	if (q.disc < - EPS)
		return (FALSE);
	q1 = (-q.b - sqrt(q.disc)) * 0.5 / q.a;
	q2 = (-q.b + sqrt(q.disc)) * 0.5 / q.a;
	inter->t0_tmp = (q1 > q2 ? q2 : q1);
	inter->t1_tmp = (q1 > q2 ? q1 : q2);
	return (TRUE);
}

void add_inter0(t_intersect *i, t_obj *o, t_u t)
{
	if (t < i->t0 && t > 0)
	{
		i->t0 = t;
		i->obj = o;
	}
}

void add_inter1(t_intersect *i, t_obj *o, t_u t)
{
	if (t < i->t1 && t > 0)
	{
		i->t1 = t;
		i->obj = o;
	}
}

t_tuple	find_pos_inter(t_ray ray, t_u t)
{
	t_tuple	tmp;

	tmp = ray.d;
	scale_v3(&tmp, t);
	return (add_tupple(ray.o, tmp));
}
