/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/20 22:14:18 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	create_ray(t_ray *new, t_tuple p, t_tuple v)
{
	new->o.x = p.x;
	new->o.y = p.y;
	new->o.z = p.z;
	new->o.w = p.w;
	new->d.x = v.x;
	new->d.y = v.y;
	new->d.z = v.z;
	new->d.w = v.w;
}

void	position(t_tuple *new, t_ray r, t_tuple p)
{
	new->x = p.x * r.d.x + r.o.x;
	new->y = p.y * r.d.y + r.o.y;
	new->z = p.z * r.d.z + r.o.z;
	new->w = 0;
}

void	init_inter(t_rt *rt)
{
	//test_sphere_init(rt);
	world_to_camera(rt);
	print_axis(rt);
	fill_obj(rt);
	init_pixel(rt);
	clear_image(rt);
}

t_bool	solve_quadratic(t_intersect *inter, t_quadra q)
{
	q.disc = pow(q.b, 2) - 4 * q.a * q.c;
	if (q.disc < 0)
		return (FALSE);
	else if (q.disc == 0)
	{
		inter->t0_tmp = -q.b * 0.5 / q.a;
		inter->t1_tmp = -inter->t0_tmp;
		return (TRUE);
	}
	else
	{
		q.q = - 0.5 * (q.b + ft_sign(q.b) * sqrt(q.disc));
		if (q.q / q.a > q.q / q.a)
		{
			inter->t0_tmp = q.q / q.c;
			inter->t1_tmp = q.q / q.a;
		}
		else
		{
			inter->t0_tmp = q.q / q.a;
			inter->t1_tmp = q.q / q.c;
		}
	}
	return (TRUE);
}

int	ft_sign(t_u i)
{
	if (i < 0)
		return (-1);
	else
		return (1);
}

void	init_pixel(t_rt *rt)
{
	t_intersect	inter;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < W_W)
	{
		while (j < W_H)
		{
			if (i == 1248 && j == 350)
				printf("On est ici\n");
			ft_bzero(&inter, sizeof(t_intersect));
			inter.t0 = DBL_MAX;
			inter.t1 = DBL_MAX;
			pixel_raster_to_space(&inter, i, j, rt);
			intersect_obj(rt, &inter, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, 1230, 363, rt);
	intersect_obj(rt, &inter, 1230, 363);
	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, 1248, 350, rt);
	intersect_obj(rt, &inter, 1248, 350);
	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, 1232, 362, rt);
	intersect_obj(rt, &inter, 1232, 362);
	ft_bzero(&inter, sizeof(t_intersect));
	printf("Done !\n");
}

void	init_pixel_debug(t_rt *rt)
{
	t_intersect	inter;

	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, 1230, 363, rt);
	intersect_obj(rt, &inter, 1230, 363);
	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, 1248, 350, rt);
	intersect_obj(rt, &inter, 1248, 350);
	ft_bzero(&inter, sizeof(t_intersect));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	pixel_raster_to_space(&inter, 1232, 362, rt);
	intersect_obj(rt, &inter, 1232, 362);
	ft_bzero(&inter, sizeof(t_intersect));
	printf("Done !\n");
}

void	intersect_obj(t_rt *rt, t_intersect *inter, int i, int j)
{
	t_list	*tmp;

	tmp = rt->scn.objs;
	while (tmp)
	{
		//print_tuple(&((t_obj *)tmp->content)->o, "sph");
		if (((t_obj *)tmp->content)->type == SPHERE)
			intersect_sph2(tmp->content, inter);
		//else if (((t_obj *)tmp->content)->type == PLAN)
		//	intersect_plane(tmp->content, inter);
		//printf("inter->t0 = %lf\n", inter->t0);
		tmp = tmp->next;
	}
	if (inter->t0 < DBL_MAX)
		my_mlx_pixel_put(rt, i, j, inter->obj->color);
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

/* 	print_tuple(&inter->ray.d, "rayd");
	print_matrix_4(sph->wtoo_m, "wtoo"); */
	mult_tuple_matrix_4(&ray2.d, sph->wtoo_m, inter->ray.d);
	mult_tuple_matrix_4(&ray2.o, sph->wtoo_m, inter->ray.o);
	s_to_r = create_v3(sph->o, inter->ray.o);
	q.a = dot_product_v3(inter->ray.d, inter->ray.d);
	q.b = 2 * dot_product_v3(inter->ray.d, s_to_r);
	q.c = dot_product_v3(s_to_r, s_to_r) - pow(sph->diam / 2, 2); 
/* 	print_tuple(&inter->ray.d, "rayd");
	print_tuple(&s_to_r, "stor");
	printf("a = %lf b = %lf c = %lf\n", q.a, q.b, q.c);	 */
	if (!solve_quadratic(inter, q) || inter->t0_tmp >=	 inter->t0)
		return ;
	inter->obj = sph;
	inter->t0 = inter->t0_tmp;
	inter->t1 = inter->t1_tmp;
/* 	printf("(intersect)sph) inter->t0 = %lf\n", inter->t0) */;
}

void	intersect_plane(t_obj *plane, t_intersect *inter)
{
	t_u		k;
	t_tuple	r_to_p;

//	print_tuple(&plane->d, "pland");
//	print_tuple(&inter->ray.d, "rayd");
	k = dot_product_v3(plane->d, inter->ray.d);
//	printf("k = %lf\n", k);
	r_to_p = create_v3(inter->ray.o, plane->o);
//	print_tuple(&r_to_p, "rtop");
//	printf("k = %lf\n", k);
//	print_tuple(&r_to_p, "rtop");
	if (k > EPS)
		inter->t0_tmp = dot_product_v3(r_to_p, plane->d) / k;
	if (inter->t0_tmp > inter->t0 || inter->t0_tmp < 0)
		return ;
	inter->obj = plane;
	inter->t0 = inter->t0_tmp;
	inter->t1 = DBL_MAX;
}
