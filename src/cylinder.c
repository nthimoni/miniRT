/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/11/04 17:13:07 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_tuple	find_pos_inter(t_ray ray, t_u t0);

void	intersect_cylinder(t_obj *cyl, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_ray		ray2;
	t_tuple		org;
	t_tuple		point_inter;

	ft_bzero(&org, sizeof(t_tuple));
	org.w = 1;
	mult_tuple_matrix_4(&ray2.d, cyl->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, cyl->wtoo_m, ray.o);
	q.a = pow(ray2.d.x, 2) + pow(ray2.d.z, 2);
	if (q.a < EPS)
		return ;
	q.b = 2 * ray2.o.x * ray2.d.x + 2 * ray2.o.z * ray2.d.z;
	q.c = pow(ray2.o.x, 2) + pow(ray2.o.z, 2) - 1; 
	if (!solve_quadratic(inter, q) || inter->t0_tmp >= inter->t0)
		return ;
	inter->obj = cyl;
	inter->t0 = inter->t0_tmp;
	inter->t1 = inter->t1_tmp;
	point_inter = find_pos_inter(ray2, inter->t0);
	inter->normal_w = create_tuple_pts(point_inter.x, 0, point_inter.z, 0);
	mult_tuple_matrix_4(&inter->normal_w, cyl->otow_m, inter->normal_w);
}

static t_tuple	find_pos_inter(t_ray ray, t_u t0)
{
	t_tuple	tmp;

	tmp = ray.d;
	scale_v3(&tmp, t0);
	return (add_tupple(ray.o, tmp));
}
