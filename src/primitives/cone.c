/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/17 15:08:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	check_cone(t_obj *obj, t_ray *ray2, t_intersect *inter, t_u m_m[2]);
static void	intersect_endcap_cone(t_intersect *inter, t_obj *obj, t_ray *ray2);
static void	normal_cone(t_tuple point, t_obj *obj, t_intersect *i, t_u t);
static void	intersect_side_cone(t_intersect *i, t_obj *obj, t_ray *r);
static void	cone_normal(t_intersect *i, t_ray *ray, t_obj *obj);

void	intersect_cone(t_obj *obj, t_intersect *inter, t_ray ray)
{
	t_ray	ray2;

	mult_tuple_matrix_4(&ray2.d, obj->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, obj->wtoo_m, ray.o);
	intersect_endcap_cone(inter, obj, &ray2);
	intersect_side_cone(inter, obj, &ray2);
	return ;
}

static void	intersect_endcap_cone(t_intersect *inter, t_obj *obj, t_ray *ray2)
{
	t_tuple	i0;

	inter->t0_tmp = (obj->o_obj.y - ray2->o.y) / ray2->d.y;
	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	if (i0.x * i0.x + i0.z * i0.z <= 1)
	{
		add_inter0(inter, obj, inter->t0_tmp);
		if (inter_is_true(inter->t0_tmp, inter->t0) 
				&& i0.y >= obj->top_obj.y - EPS)
			inter->endcap = TOP;
		else if (inter_is_true(inter->t0_tmp, inter->t0)
				&& i0.y <= obj->o_obj.y + EPS)
			inter->endcap = BOTTOM;
	}
}

static void	intersect_side_cone(t_intersect *i, t_obj *obj, t_ray *r)
{
	t_quadra	q;
	int			res_quad;
	t_u			min_max[2];

	q.a = r->d.x * r->d.x - r->d.y * r->d.y + r->d.z * r->d.z;
	q.b = 2 * r->o.x * r->d.x - 2 * r->o.y * r->d.y
		+ 2 * r->o.z * r->d.z;
	q.c = r->o.x * r->o.x - r->o.y * r->o.y + r->o.z * r->o.z;
	if (q.a < EPS && q.a > -EPS && q.b < EPS && q.b > -EPS)
		return ;
	else
	{
		res_quad = solve_quadratic(i, q);
		if (i->t0_tmp >= i->t0 || res_quad == 0)
			return ;
	}
	min_max[0] = -1;
	min_max[1] = 0;
	if ((obj->d.x == 0 && obj->d.z == 0 && obj->d.y < 0))
	{
		min_max[0] = 0;
		min_max[1] = 1;
	}
	check_cone(obj, r, i, min_max);
}

static void	check_cone(t_obj *obj, t_ray *ray2, t_intersect *i, t_u m_m[2])
{
	t_tuple	i0;
	t_tuple	i1;

	i0 = find_pos_inter(*ray2, i->t0_tmp);
	i1 = find_pos_inter(*ray2, i->t1_tmp);
	if (i0.y > m_m[0] && i0.y <= m_m[1] && i1.y > m_m[0] && i1.y <= m_m[1]
		&& inter_is_true(i->t0_tmp, i->t0))
	{
		add_inter0(i, obj, i->t0_tmp);
		add_inter1(i, obj, i->t1_tmp);
		i->endcap = SIDE;
	}
	else if (i0.y > m_m[0] && i0.y <= m_m[1] && inter_is_true(i->t0_tmp, i->t0))
	{
		add_inter0(i, obj, i->t0_tmp);
		i->endcap = SIDE;
	}
	else if (i1.y > m_m[0] && i1.y <= m_m[1] && inter_is_true(i->t1_tmp, i->t0))
	{
		add_inter0(i, obj, i->t1_tmp);
		i->endcap = SIDE;
	}
	return ;
}

static void	normal_cone(t_tuple point, t_obj *obj, t_intersect *i, t_u t)
{
	if (i->t0 != t)
		return ;
	i->normal_w.x = point.x;
	i->normal_w.y = 0;
	if ((obj->d.x == 0 && obj->d.y == 0 && obj->d.z < 0))
		i->normal_w.y = (0.2 * point.x + 0.2 * point.z);
	i->normal_w.z = point.z;
	i->normal_w.w = 0;
	mult_tuple_matrix_4(&i->normal_w, obj->otow_m, i->normal_w);
}

static void	cone_normal(t_intersect *i, t_ray *ray, t_obj *obj)
{
	t_u		angle_cone;
	t_tuple	obj_to_inter;
	t_tuple	scaled_direction;
	t_tuple	intersection;

	intersection = find_pos_inter(*ray, i->t0_tmp);
	(void)ray;
	angle_cone = 0;
	if (obj->height)
		angle_cone = atan(obj->diam / 2 / obj->height);
	obj_to_inter = sub_tupple(obj->o, intersection);
	scaled_direction = create_tuple_copy(obj->d);
	scale_v3(&scaled_direction, length_v3(obj_to_inter) / cos(angle_cone));
	i->normal_w = sub_tupple(scaled_direction, obj_to_inter);
}
