/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/11 21:55:13 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	check_cylinder(t_obj *cyl, t_ray *ray2, t_intersect *inter);
void	intersect_endcap(t_intersect *inter, t_obj *cyl, t_ray *ray2);

void	intersect_cylinder(t_obj *cyl, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_ray		ray2;
	int			res_quad;

	mult_tuple_matrix_4(&ray2.d, cyl->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, cyl->wtoo_m, ray.o);
	intersect_endcap(inter, cyl, &ray2);
	q.a = ray2.d.x * ray2.d.x + ray2.d.z * ray2.d.z;
	if (q.a < EPS)
		return ;
	q.b = 2 * ray2.o.x * ray2.d.x + 2 * ray2.o.z * ray2.d.z;
	q.c = ray2.o.x * ray2.o.x + ray2.o.z * ray2.o.z - 1;
	res_quad = solve_quadratic(inter, q);
	if (inter->t0_tmp >= inter->t0 || res_quad == 0)
		return ;
	check_cylinder(cyl, &ray2, inter);
	return ;
}

void	check_cylinder(t_obj *cyl, t_ray *ray2, t_intersect *i)
{
	t_tuple	i0;
	t_tuple	i1;

	i0 = find_pos_inter(*ray2, i->t0_tmp);
	i1 = find_pos_inter(*ray2, i->t1_tmp);
	if (i0.y > cyl->o_obj.y && i0.y < cyl->top_obj.y && i1.y > cyl->o_obj.y
		&& i1.y < cyl->top_obj.y && i->t0 > i->t0_tmp)
	{
		add_inter0(i, cyl, i->t0_tmp);
		add_inter1(i, cyl, i->t1_tmp);
		if (i->t0 == i->t0_tmp)
			normal_cylinder(i0, cyl, &i->normal_w);
	}
	else if (i0.y > cyl->o_obj.y && i0.y < cyl->top_obj.y && i->t0 > i->t0_tmp)
	{
		add_inter0(i, cyl, i->t0_tmp);
		if (i->t0 == i->t0_tmp)
			normal_cylinder(i0, cyl, &i->normal_w);
	}
	else if (i1.y > cyl->o_obj.y && i1.y < cyl->top_obj.y && i->t0 > i->t1_tmp)
	{
		add_inter0(i, cyl, i->t1_tmp);
		if (i->t0 == i->t1_tmp)
			normal_cylinder(i1, cyl, &i->normal_w);
	}
}

void	intersect_endcap(t_intersect *i, t_obj *c, t_ray *r)
{
	t_tuple	i0;
	t_tuple	i1;

	i->t0_tmp = min_u((c->o_obj.y - r->o.y) / r->d.y,
			(c->top_obj.y - r->o.y) / r->d.y);
	i->t1_tmp = max_u((c->o_obj.y - r->o.y) / r->d.y,
			(c->top_obj.y - r->o.y) / r->d.y);
	i0 = find_pos_inter(*r, i->t0_tmp);
	i1 = find_pos_inter(*r, i->t1_tmp);
	if (i0.x * i0.x + i0.z * i0.z <= 1 && i1.x * i1.x + i1.z * i1.z <= 1)
	{
		add_inter0(i, c, i->t0_tmp);
		add_inter1(i, c, i->t1_tmp);
		normal_endcap(i0, c, i, i->t0_tmp);
	}
	else if (i0.x * i0.x + i0.z * i0.z <= 1)
	{
		add_inter0(i, c, i->t0_tmp);
		normal_endcap(i0, c, i, i->t0_tmp);
	}
	else if (i1.x * i1.x + i1.z * i1.z <= 1)
	{
		add_inter0(i, c, i->t1_tmp);
		normal_endcap(i1, c, i, i->t1_tmp);
	}
}

void	normal_endcap(t_tuple p, t_obj *cyl, t_intersect *i, t_u t)
{
	if (i->t0 != t)
		return ;
	i->normal_w.x = 0;
	if (p.y >= cyl->top_obj.y - EPS)
		i->normal_w.y = 1;
	else if (p.y <= cyl->o_obj.y + EPS)
		i->normal_w.y = -1;
	i->normal_w.z = 0;
	i->normal_w.w = 0;
	mult_tuple_matrix_4(&i->normal_w, cyl->otow_m, i->normal_w);
}

void	normal_cylinder(t_tuple point, t_obj *cyl, t_tuple *normal)
{
	normal->x = point.x;
	normal->y = 0;
	normal->z = point.z;
	normal->w = 0;
	mult_tuple_matrix_4(normal, cyl->otow_m, *normal);
}
