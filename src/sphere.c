/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:28:44 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/26 19:55:17 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_bool	solve_quadratic(t_intersect *inter, t_quadra q)
{
	q.disc = pow(q.b, 2) - 4 * q.a * q.c;
	if (q.disc < - EPS)
		return (FALSE);
	inter->t0_tmp = (-q.b - sqrt(q.disc)) * 0.5 / q.a;
	inter->t1_tmp = (-q.b + sqrt(q.disc)) * 0.5 / q.a;
	return (TRUE);
}

void	intersect_sph(t_obj *sph, t_intersect *inter)
{
	t_quadra	q;
	t_tuple		s_to_r;

	s_to_r = create_v3(sph->o, inter->ray.o);
	q.a = dot_product_v3(inter->ray.d, inter->ray.d);
	q.b = 2 * dot_product_v3(inter->ray.d, s_to_r);
	q.c = dot_product_v3(s_to_r, s_to_r) - pow(sph->diam / 2, 2); 
	if (!solve_quadratic(inter, q) || inter->t0_tmp > inter->t0)
		return ;
	inter->obj = sph;
	inter->t0 = inter->t0_tmp;
	inter->t1 = inter->t1_tmp;
//	printf("(intersect)sph) inter->t0 = %lf\n", inter->t0);
}

void	intersect_sph2(t_obj *sph, t_intersect *inter)
{
	t_quadra	q;
	t_tuple		s_to_r;
	t_ray		ray2;
	t_tuple		org;

	ft_bzero(&org, sizeof(t_tuple));
	org.w = 1;
	mult_tuple_matrix_4(&ray2.d, sph->wtoo_m, inter->ray.d);
	mult_tuple_matrix_4(&ray2.o, sph->wtoo_m, inter->ray.o);
	s_to_r = create_v3(org, ray2.o);
	q.a = dot_product_v3(ray2.d, ray2.d);
	q.b = 2 * dot_product_v3(ray2.d, s_to_r);
	q.c = dot_product_v3(s_to_r, s_to_r) - 1; 
	if (!solve_quadratic(inter, q) || inter->t0_tmp >= inter->t0)
		return ;
	inter->obj = sph;
	inter->t0 = inter->t0_tmp;
	inter->t1 = inter->t1_tmp;
}
