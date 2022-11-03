/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/11/03 20:05:09 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	intersect_cylinder(t_obj *cyl, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_ray		ray2;
	t_tuple		org;

	ft_bzero(&org, sizeof(t_tuple));
	org.w = 1;
	mult_tuple_matrix_4(&ray2.d, cyl->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, cyl->wtoo_m, ray.o);
	norm_v3(&ray2.d);
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
}
