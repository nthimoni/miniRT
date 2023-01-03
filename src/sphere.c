/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:28:44 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/03 09:59:24 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	normal_sphere(t_intersect *inter, t_ray *ray, t_u t);

void	intersect_sph(t_obj *sph, t_intersect *inter, t_ray	ray)
{
	t_quadra	q;
	t_tuple		s_to_r;

	s_to_r = create_v3(sph->o, ray.o);
	q.a = 1;
	q.b = 2 * dot_product_v3(ray.d, s_to_r);
	q.c = dot_product_v3(s_to_r, s_to_r) - pow(sph->diam / 2, 2); 
	if (!solve_quadratic(inter, q) || inter->t0_tmp > inter->t0 || inter->t0_tmp < 0)
		return ;
	inter->obj = sph;
	inter->t0 = inter->t0_tmp;
	inter->t1 = inter->t1_tmp;
	normal_sphere(inter, &ray, inter->t0);
}

void	intersect_sph2(t_obj *sph, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_tuple		s_to_r;
	t_ray		ray2;
	t_tuple		org;

	ft_bzero(&org, sizeof(t_tuple));
	org.w = 1;
	mult_tuple_matrix_4(&ray2.d, sph->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, sph->wtoo_m, ray.o);
	s_to_r = create_v3(org, ray2.o);
	q.a = dot_product_v3(ray2.d, ray2.d);
	q.b = 2 * dot_product_v3(ray2.d, s_to_r);
	q.c = dot_product_v3(s_to_r, s_to_r) - 1; 
	if (!solve_quadratic(inter, q) || inter->t0_tmp >= inter->t0 || inter->t0_tmp < 0)
		return ;
	inter->obj = sph;
	add_inter0(inter, sph, inter->t0_tmp);
	add_inter1(inter, sph, inter->t1_tmp);
	normal_sphere(inter, &ray, inter->t0);
}

static void	normal_sphere(t_intersect *inter, t_ray *ray, t_u t)
{
	t_tuple	intersection;

	intersection = find_pos_inter(*ray, t);
	inter->normal_w = sub_tupple(inter->obj->o, intersection);
}
