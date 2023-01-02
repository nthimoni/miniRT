/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/02 17:53:38 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static 	t_tuple	find_pos_inter(t_ray ray, t_u t0);
void	check_cone(t_obj *obj, t_ray *ray2, t_intersect *inter);
void 	intersect_endcap_cone(t_intersect *inter, t_obj *obj, t_ray *ray2);
void	normal_cone(t_tuple point, t_obj *obj, t_tuple *normal);

void	intersect_cone(t_obj *obj, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_ray		ray2;
	int			res_quad;

	mult_tuple_matrix_4(&ray2.d, obj->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, obj->wtoo_m, ray.o);
	intersect_endcap_cone(inter, obj, &ray2);
	q.a = ray2.d.x * ray2.d.x - ray2.d.y * ray2.d.y + ray2.d.z * ray2.d.z;
	q.b = 2 * ray2.o.x * ray2.d.x - 2 * ray2.o.y * ray2.d.y 
			+ 2 * ray2.o.z * ray2.d.z;
	q.c = ray2.o.x * ray2.o.x - ray2.o.y * ray2.o.y + ray2.o.z * ray2.o.z; 
	if (q.a < EPS && q.a > - EPS && q.b < EPS && q.b > - EPS)
		return ;
	else if (q.a < EPS && q.a > - EPS)
		inter->t0_tmp = - q.c / (2 * q.b);
	else
	{
		res_quad = solve_quadratic(inter, q);
		if (inter->t0_tmp >= inter->t0 || res_quad == 0)
			return ;
	}
	check_cone(obj, &ray2, inter);
	return ;
}

static t_tuple	find_pos_inter(t_ray ray, t_u t0)
{
	t_tuple	tmp;

	tmp = ray.d;
	scale_v3(&tmp, t0);
	return (add_tupple(ray.o, tmp));
}

void	check_cone(t_obj *obj, t_ray *ray2, t_intersect *inter)
{
	t_tuple i0;
	t_tuple i1;

	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	i1 = find_pos_inter(*ray2, inter->t1_tmp);
	if (i0.y > obj->o_obj.y && i0.y <= 0
			&& i1.y > obj->o_obj.y && i1.y <= 0
			&& inter->t0 > inter->t0_tmp)
	{
		add_inter0(inter, obj, inter->t0_tmp);
		add_inter1(inter, obj, inter->t1_tmp);
		normal_cone(i0, obj, &inter->normal_w);
	}
	else if (i0.y > obj->o_obj.y && i0.y <= 0
				&& inter->t0 > inter->t0_tmp)
	{
		add_inter0(inter, obj, inter->t0_tmp);
		normal_cone(i0, obj, &inter->normal_w);
	}
	else if (i1.y > obj->o_obj.y && i1.y <= 0
				&& inter->t0 > inter->t1_tmp)
	{
		add_inter0(inter, obj, inter->t1_tmp);
		normal_cone(i1, obj, &inter->normal_w);
	}
	return;
}

void intersect_endcap_cone(t_intersect *inter, t_obj *obj, t_ray *ray2)
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

void normal_cone(t_tuple point, t_obj *obj, t_tuple *normal)
{
	normal->x = point.x;
	normal->y = sqrt(point.x * point.x + point.z * point.z);
	normal->z = point.z;
	normal->w = 0;
	if (point.y <= -1)
		normal->y = -1;
	mult_tuple_matrix_4(normal, obj->otow_m, *normal);
	scale_v3(normal, -1);
}
