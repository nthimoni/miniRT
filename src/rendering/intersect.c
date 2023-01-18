/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:55:29 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/18 18:41:25 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_bool	solve_quadratic(t_intersect *inter, t_quadra q)
{
	t_u	q1;
	t_u	q2;

	q.disc = pow(q.b, 2) - 4 * q.a * q.c;
	if (q.disc < -EPS)
		return (FALSE);
	q1 = (-q.b - sqrt(q.disc)) * 0.5 / q.a;
	q2 = (-q.b + sqrt(q.disc)) * 0.5 / q.a;
	if (isnan(q1))
		return (FALSE);
	inter->t0_tmp = min_u(q1, q2);
	inter->t1_tmp = max_u(q1, q2);
	if (inter->t0_tmp < 0 && inter->t1_tmp > 0)
	{
		inter->t0_tmp = inter->t1_tmp;
		inter->t1_tmp = DBL_MAX;
	}
	return (TRUE);
}

void	add_inter0(t_intersect *i, t_obj *o, t_u t)
{
	if (t <= i->t0 && t > EPS)
	{
		i->t0 = t;
		i->obj = o;
	}
}

void	add_inter1(t_intersect *i, t_obj *o, t_u t)
{
	if (t <= i->t1 && t > EPS)
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
