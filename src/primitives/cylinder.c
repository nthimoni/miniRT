/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/04 17:17:58 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	check_cylinder(t_obj *cyl, t_ray *ray2, t_intersect *inter);
void 	intersect_endcap(t_intersect *inter, t_obj *cyl, t_ray *ray2);

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

// Le calcul de t0 et t1 se fait sur un cylindre infini -> la premiere intersection peut etre en dehors du cylindre
// mais la deuxieme peux parfois etre bonne. Les deux sont a verifier.
void	check_cylinder(t_obj *cyl, t_ray *ray2, t_intersect *inter)
{
	t_tuple i0;
	t_tuple i1;

	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	i1 = find_pos_inter(*ray2, inter->t1_tmp);
	if (i0.y > cyl->o_obj.y && i0.y < cyl->top_obj.y
			&& i1.y > cyl->o_obj.y	&& i1.y < cyl->top_obj.y
			&& inter->t0 > inter->t0_tmp)
	{
		add_inter0(inter, cyl, inter->t0_tmp);
		add_inter1(inter, cyl, inter->t1_tmp);
		if (inter->t0 == inter->t0_tmp)
			normal_cylinder(i0, cyl, &inter->normal_w);
	}
	else if (i0.y > cyl->o_obj.y && i0.y < cyl->top_obj.y
				&& inter->t0 > inter->t0_tmp)
	{
		add_inter0(inter, cyl, inter->t0_tmp);
		if (inter->t0 == inter->t0_tmp)
			normal_cylinder(i0, cyl, &inter->normal_w);
	}
	else if (i1.y > cyl->o_obj.y && i1.y < cyl->top_obj.y
				&& inter->t0 > inter->t1_tmp)
	{
		add_inter0(inter, cyl, inter->t1_tmp);
		if (inter->t0 == inter->t1_tmp)
			normal_cylinder(i1, cyl, &inter->normal_w);
	}
	return;
}

void intersect_endcap(t_intersect *inter, t_obj *cyl, t_ray *ray2)
{
	t_u	t0;
	t_u	t1;
	t_tuple i0;
	t_tuple i1;

	t0 = (cyl->o_obj.y - ray2->o.y) / ray2->d.y;
	t1 = (cyl->top_obj.y - ray2->o.y) / ray2->d.y;
	inter->t0_tmp = t0 < t1 ? t0 : t1;
	inter->t1_tmp = t0 < t1 ? t1 : t0;
	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	i1 = find_pos_inter(*ray2, inter->t1_tmp);
	if (i0.x * i0.x + i0.z * i0.z <= 1 && i1.x * i1.x + i1.z * i1.z <= 1)
	{
		add_inter0(inter, cyl, inter->t0_tmp);
		add_inter1(inter, cyl, inter->t1_tmp);
		if (inter->t0 == inter->t0_tmp)
			normal_endcap(i0, cyl, &inter->normal_w);
	}
	else if (i0.x * i0.x + i0.z * i0.z <= 1)
	{
		add_inter0(inter, cyl, inter->t0_tmp);
		if (inter->t0 == inter->t0_tmp)
			normal_endcap(i0, cyl, &inter->normal_w);
	}
	else if (i1.x * i1.x + i1.z * i1.z <= 1)
	{
		add_inter0(inter, cyl, inter->t1_tmp);
		if (inter->t0 == inter->t1_tmp)
			normal_endcap(i1, cyl, &inter->normal_w);
	}
}

void normal_endcap(t_tuple point, t_obj *cyl, t_tuple *normal)
{
	normal->x = 0;
	if (point.y >= cyl->top_obj.y - EPS)
		normal->y = 1;
	else if (point.y <= cyl->o_obj.y + EPS)
		normal->y = -1;
	normal->z = 0;
	normal->w = 0;
	mult_tuple_matrix_4(normal, cyl->otow_m, *normal);
}

void normal_cylinder(t_tuple point, t_obj *cyl, t_tuple *normal)
{
	normal->x = point.x;
	normal->y = 0;
	normal->z = point.z;
	normal->w = 0;
	mult_tuple_matrix_4(normal, cyl->otow_m, *normal);
}