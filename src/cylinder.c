/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/11/22 17:33:19 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_tuple	find_pos_inter(t_ray ray, t_u t0);
static int	check_cyl(t_obj *cyl, t_ray *ray2, t_intersect *inter);
static void	mini(t_u a, t_u b, t_u *y);

void	intersect_cylinder(t_obj *cyl, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_ray		ray2;
	t_tuple		k;
	int			res_endcap;
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
	res_endcap = check_cyl(cyl, &ray2, inter);
	if (res_endcap == 0)
		return ;
	inter->obj = cyl;
	k = find_pos_inter(ray, inter->t0);
	inter->normal_w = create_tuple_pts(k.x, 0, k.z, 0);
	mult_tuple_matrix_4(&inter->normal_w, cyl->otow_m, inter->normal_w);
}

static t_tuple	find_pos_inter(t_ray ray, t_u t0)
{
	t_tuple	tmp;

	tmp = ray.d;
	scale_v3(&tmp, t0);
	return (add_tupple(ray.o, tmp));
}

static int	check_cyl(t_obj *cyl, t_ray *ray2, t_intersect *inter)
{
	t_tuple	org_cyl_obj;
	t_tuple	top_cyl_obj;
	t_tuple	top_cyl_world;
	t_tuple	dir_cpy;;
	t_u		y[2];

	dir_cpy = create_tuple_copy(cyl->d);
	scale_v3(&dir_cpy, cyl->height);
	top_cyl_world = add_tupple(dir_cpy, cyl->o); 
	top_cyl_world.w = 1;
	mult_tuple_matrix_4(&org_cyl_obj, cyl->wtoo_m, create_tuple_copy(cyl->o));
	mult_tuple_matrix_4(&top_cyl_obj, cyl->wtoo_m, top_cyl_world);
	mini(ray2->o.y + inter->t0_tmp * ray2->d.y,	ray2->o.y + inter->t1_tmp * ray2->d.y, y);
	if (y[0] > org_cyl_obj.y && y[0] < top_cyl_obj.y && y[1] > org_cyl_obj.y && y[1] < top_cyl_obj.y)
	{
		inter->t0 = inter->t0_tmp;
		inter->t1 = inter->t1_tmp;
		return (2);
	}
	else if (y[0] > org_cyl_obj.y && y[0] < top_cyl_obj.y)
	{
		inter->t0 = inter->t0_tmp;
		inter->t1 = inter->t1_tmp;
		return (1);
	}
	else if (y[1] > org_cyl_obj.y && y[1] < top_cyl_obj.y)
	{
		inter->t0 = inter->t1_tmp;
		inter->t1 = inter->t1_tmp;
		return (3);
	}
	else
		return 0;	
}

static void	mini(t_u a, t_u b, t_u *y)
{
	if (a > b)
	{
		y[0] = b;
		y[1] = a;
	}
	else
	{
		y[0] = b;
		y[1] = a;
	}
}
