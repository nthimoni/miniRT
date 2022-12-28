/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/12/28 21:36:43 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static 		t_tuple	find_pos_inter(t_ray ray, t_u t0);
void	check_cylinder(t_obj *cyl, t_ray *ray2, t_intersect *inter);
void	add_inter(t_intersect *inter, t_ray ray, int index, t_obj *cyl);
void 	endcap(t_intersect *inter, t_obj *cyl, t_tuple cyl_obj[2], t_ray *ray2);

void	intersect_cylinder(t_obj *cyl, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_ray		ray2;
	int			res_quad;

	mult_tuple_matrix_4(&ray2.d, cyl->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, cyl->wtoo_m, ray.o);
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

static t_tuple	find_pos_inter(t_ray ray, t_u t0)
{
	t_tuple	tmp;

	tmp = ray.d;
	scale_v3(&tmp, t0);
	return (add_tupple(ray.o, tmp));
}

// Le calcul de t0 et t1 se fait sur un cylindre infini -> la premiere intersection peut etre en dehors du cylindre
// mais la deuxieme peux parfois etre bonne. Les deux sont a verifier.
void	check_cylinder(t_obj *cyl, t_ray *ray2, t_intersect *inter)
{
	t_tuple	cyl_obj[2];
	t_tuple i0;
	t_tuple i1;

	mult_tuple_matrix_4(&cyl_obj[0], cyl->wtoo_m, create_tuple_copy(cyl->o));
	mult_tuple_matrix_4(&cyl_obj[1], cyl->wtoo_m, cyl->top);
	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	i1 = find_pos_inter(*ray2, inter->t1_tmp);
	if (i0.y > cyl_obj[0].y && i0.y < cyl_obj[1].y
			&& i1.y > cyl_obj[0].y	&& i1.y < cyl_obj[1].y)
		add_inter(inter, *ray2, 2, cyl);
	else if (i0.y > cyl_obj[0].y && i0.y < cyl_obj[1].y)
		add_inter(inter, *ray2, 0, cyl);
	else if (i1.y > cyl_obj[0].y && i1.y < cyl_obj[1].y)
		add_inter(inter, *ray2, 1, cyl);
	endcap(inter, cyl, cyl_obj, ray2);
	return;
}

void	add_inter(t_intersect *inter, t_ray ray2, int index, t_obj *cyl)
{
	t_tuple	k;

	ft_bzero(&k, sizeof(t_tuple));
	if (index == 0)
	{
		inter->t0 = inter->t0_tmp;
		k = find_pos_inter(ray2, inter->t0_tmp);
	}
	else if (index == 1)
	{
		inter->t0 = inter->t1_tmp;
		k = find_pos_inter(ray2, inter->t1_tmp);
	}
	else if (index == 2)
	{
		inter->t0 = inter->t0_tmp;
		inter->t1 = inter->t1_tmp;
		k = find_pos_inter(ray2, inter->t0_tmp);
	}
	inter->normal_w.x = k.x;
	inter->normal_w.y = 0;
	inter->normal_w.z = k.z;
	inter->normal_w.w = 0;
	scale_v3(&inter->normal_w, -1);
	inter->obj = cyl;
	mult_tuple_matrix_4(&inter->normal_w, cyl->otow_m, inter->normal_w);
}

void endcap(t_intersect *inter, t_obj *cyl, t_tuple cyl_obj[2], t_ray *ray2)
{
	t_u	t0;
	t_u	t1;
	t_tuple i0;
	t_tuple i1;

	(void)cyl;
	t0 = (cyl_obj[0].y - ray2->o.y) / ray2->d.y;
	t1 = (cyl_obj[1].y - ray2->o.y) / ray2->d.y;
	inter->t0_tmp = t0 < t1 ? t0 : t1;
	inter->t1_tmp = t0 < t1 ? t1 : t0;
	i0 = find_pos_inter(*ray2, inter->t0_tmp);
	i1 = find_pos_inter(*ray2, inter->t1_tmp);
	if (i0.x * i0.x + i0.z * i0.z <= 1)
	{
		inter->t0 = inter->t0_tmp;
	}
	if (i1.x * i1.x + i1.z * i1.z <= 1)
	{
		inter->t1 = inter->t1_tmp;
	}

}
