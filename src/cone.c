/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/03 21:16:04 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	check_cone(t_obj *obj, t_ray *ray2, t_intersect *inter);
static void 	intersect_endcap_cone(t_intersect *inter, t_obj *obj, t_ray *ray2);
static void	normal_cone(t_tuple point, t_obj *obj, t_tuple *normal);
static void	intersect_side_cone(t_intersect *i, t_obj *obj, t_ray *r);

void	intersect_cone(t_obj *obj, t_intersect *inter, t_ray ray)
{
	t_ray		ray2;

	mult_tuple_matrix_4(&ray2.d, obj->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, obj->wtoo_m, ray.o);
	intersect_endcap_cone(inter, obj, &ray2);
	intersect_side_cone(inter, obj, &ray2);
	return ;
}

static void	intersect_side_cone(t_intersect *i, t_obj *obj, t_ray *r)
{
	t_quadra	q;
	int			res_quad;

	q.a = r->d.x * r->d.x - r->d.y * r->d.y + r->d.z * r->d.z;
	q.b = 2 * r->o.x * r->d.x - 2 * r->o.y * r->d.y 
			+ 2 * r->o.z * r->d.z;
	q.c = r->o.x * r->o.x - r->o.y * r->o.y + r->o.z * r->o.z; 
	if (q.a < EPS && q.a > - EPS && q.b < EPS && q.b > - EPS)
		return ;
	else if (q.a < EPS && q.a > - EPS)
	{
		i->t0_tmp = - q.c / (2 * q.b);
		i->t1_tmp = DBL_MAX;
	}
	else
	{
		res_quad = solve_quadratic(i, q);
		if (i->t0_tmp >= i->t0 || res_quad == 0)
			return ;
	}
	check_cone(obj, r, i);
}

static void	check_cone(t_obj *obj, t_ray *ray2, t_intersect *inter)
{
	t_tuple i0;
	t_tuple i1;

	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	i1 = find_pos_inter(*ray2, inter->t1_tmp);
	if (i0.y > -1 && i0.y <= 0
			&& i1.y > -1 && i1.y <= 0
			&& inter->t0 > inter->t0_tmp)
	{
		add_inter0(inter, obj, inter->t0_tmp);
		add_inter1(inter, obj, inter->t1_tmp);
		normal_cone(i0, obj, &inter->normal_w);
	}
	else if (i0.y > -1 && i0.y <= 0
				&& inter->t0 > inter->t0_tmp)
	{
		add_inter0(inter, obj, inter->t0_tmp);
		normal_cone(i0, obj, &inter->normal_w);
	}
	else if (i1.y > -1 && i1.y <= 0
				&& inter->t0 > inter->t1_tmp)
	{
		add_inter0(inter, obj, inter->t1_tmp);
		normal_cone(i1, obj, &inter->normal_w);
	}
	return;
}

static void intersect_endcap_cone(t_intersect *inter, t_obj *obj, t_ray *ray2)
{
	t_tuple i0;

	inter->t0_tmp = (obj->o_obj.y - ray2->o.y) / ray2->d.y;
	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	if (i0.x * i0.x + i0.z * i0.z <= 1)
	{
		add_inter0(inter, obj, inter->t0_tmp);
		normal_endcap(i0, obj, &inter->normal_w);
	}
}

static void normal_cone(t_tuple point, t_obj *obj, t_tuple *normal)
{
	/*
	t_u	radius;

	radius = point.x * point.x + point.z * point.z;
	if (radius < 1 && point.y >= 1 - EPS)
		*normal = create_tuple_pts(0, 1, 0, 0);
	else if (radius < 1 && point.y <= 0 + EPS)
		*normal = create_tuple_pts(0, -1, 0, 0);
	else
		*normal = create_tuple_pts(point.x, 0, point.z, 0);
	*/
	normal->x = point.x;
	//normal->y = sqrt(point.x * point.x + point.z * point.z);
	normal->y = 0;
	normal->z = point.z;
	normal->w = 0;
	if (point.y > 0)
		normal->y *= -1;	
	/*
	t_tuple hit_to_top;

	//point.y -= 1;
	hit_to_top = sub_tupple(point, obj->top_obj);
	scale_v3(&hit_to_top, dot_product_v3(hit_to_top, create_tuple_pts(0, 1, 0, 0)) / dot_product_v3(hit_to_top, hit_to_top));
	*normal = sub_tupple(hit_to_top, create_tuple_pts(0, 1, 0, 0));
	*/
	mult_tuple_matrix_4(normal, obj->otow_m, *normal);
}
