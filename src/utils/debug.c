/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:27:37 by rmorel            #+#    #+#             */
/*   Updated: 2022/11/03 17:57:45 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_pixel_debug(t_rt *rt)
{
	t_intersect	inter;

	/*printf("------------ x = W_W / 4 and y = W_H / 4 -------------\n");
	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, W_W / 4, W_H / 4, rt);
	intersect_obj_debug(rt, &inter, W_W / 4, W_W / 4);
	ft_bzero(&inter, sizeof(t_intersect));
	printf("------------ x = W_W * 3 / 4 and y = W_H / 4 ------------\n");
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, W_W * 3 / 4, W_H / 4, rt);
	intersect_obj_debug(rt, &inter, W_W * 3 / 4, W_W / 4);
	ft_bzero(&inter, sizeof(t_intersect));
	printf("------------ x = W_W / 4 and y = W_H * 3 / 4 ------------\n");
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, W_W / 4, W_H * 3 / 4, rt);
	intersect_obj_debug(rt, &inter, W_W / 4, W_W * 3 / 4);*/
	ft_bzero(&inter, sizeof(t_intersect));
	printf("------------ x = W_W * 3 / 4 and y = W_H * 3 / 4 ------------\n");
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, W_W * 3 / 4, W_H * 3 / 4, rt);
	intersect_obj_debug(rt, &inter, W_W * 3 / 4, W_W * 3 / 4);
	printf("Done !\n");
}
void	intersect_obj_debug(t_rt *rt, t_intersect *inter, int i, int j)
{
	t_list	*tmp;

	tmp = rt->scn.objs;
	while (tmp)
	{
		if (((t_obj *)tmp->content)->type == SPHERE)
		{
			if (rt->space == WORLD)
				intersect_sph(tmp->content, inter, inter->ray);
			else if (rt->space == OBJ)
				intersect_sph2_debug(tmp->content, inter, inter->ray);
		}
		//else if (((t_obj *)tmp->content)->type == PLAN)
		//	intersect_plane(tmp->content, inter);
		//printf("inter->t0 = %lf\n", inter->t0);
		tmp = tmp->next;
	}
	if (inter->t0 < DBL_MAX)
		my_mlx_pixel_put(rt, i, j, inter->obj->color);
}

void	intersect_sph2_debug(t_obj *sph, t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	t_tuple		s_to_r;
	t_ray		ray2;

	mult_tuple_matrix_4(&ray2.d, sph->wtoo_m, ray.d);
	mult_tuple_matrix_4(&ray2.o, sph->wtoo_m, ray.o);
 	print_tuple(&inter->ray.d, "rayd normed");
 	print_tuple(&ray2.o, "rayo * wtoo");
 	print_tuple(&ray2.d, "rayd * wtoo");
	s_to_r = create_v3(sph->o, ray2.o);
	q.a = dot_product_v3(ray2.d, ray2.d);
	q.b = 2 * dot_product_v3(ray2.d, s_to_r);
	q.c = dot_product_v3(s_to_r, s_to_r) - pow(sph->diam / 2, 2); 
	print_tuple(&s_to_r, "stor");
	printf("a = %lf b = %lf c = %lf\n", q.a, q.b, q.c);
	if (!solve_quadratic(inter, q) || inter->t0_tmp >=	 inter->t0)
		return ;
	inter->obj = sph;
	inter->t0 = inter->t0_tmp;
	inter->t1 = inter->t1_tmp;
 	printf("(intersect)sph) inter->t0 = %lf\n", inter->t0);
}
