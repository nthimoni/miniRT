/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/20 17:37:17 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lighting.h"

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
	init_pixel(rt);
	clear_image(rt);
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
		while (j++ < W_H)
		{
			ft_bzero(&inter, sizeof(t_intersect));
			inter.t0 = DBL_MAX;
			inter.t1 = DBL_MAX;
			pixel_raster_to_space(&inter, i, j, rt);
			intersect_obj(rt, &inter, i, j);
		}
		j = 0;
		i++;
	}
	printf("Done !");
}

void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt)
{
	i->pixel.x = (x + 0.5) / W_W;
	i->pixel.y = (y + 0.5) / W_H;
	i->pixel.x = 2 * i->pixel.x - 1;
	i->pixel.y = 1 - 2 * i->pixel.y;
	i->pixel.x = i->pixel.x * W_W / W_H * tan(rt->scn.cam.FOV / 2);	
	i->pixel.y = i->pixel.y * tan(rt->scn.cam.FOV / 2);	
	i->pixel.z = -1;
	i->pixel.w = 1;
	ft_bzero(&i->ray.o, sizeof(t_tuple));
	i->ray.o.w = 1;
	i->ray.d.x = i->pixel.x - 0;
	i->ray.d.y = i->pixel.y - 0;
	i->ray.d.z = i->pixel.z - 0;
	i->ray.d.w = 0;
	mult_tuple_matrix_4(&i->ray.o, rt->ctow_m, i->ray.o);
	mult_tuple_matrix_4(&i->ray.d, rt->ctow_m, i->ray.d);
	norm_v3(&i->ray.d);
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

void	intersect_obj(t_rt *rt, t_intersect *inter, int i, int j)
{
	t_list	*tmp;

	tmp = rt->scn.objs;
	while (tmp)
	{
		//print_tuple(&((t_obj *)tmp->content)->o, "sph");
		if (((t_obj *)tmp->content)->type == SPHERE)
			intersect_sph(tmp->content, inter);
		else if (((t_obj *)tmp->content)->type == PLAN)
			intersect_plane(tmp->content, inter);
		//printf("inter->t0 = %lf\n", inter->t0);
		tmp = tmp->next;
	}
	if (inter->t0 < DBL_MAX)
		my_mlx_pixel_put(rt, i, j, lighting(rt, inter));
}

void	intersect_sph(t_obj	*sph, t_intersect *inter)
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
}

void	intersect_plane(t_obj *plane, t_intersect *inter)
{
	t_u		k;
	t_tuple	r_to_p;

	k = dot_product_v3(plane->d, inter->ray.d);
	r_to_p = create_v3(inter->ray.o, plane->o);
//	printf("k = %lf\n", k);
//	print_tuple(&r_to_p, "rtop");
	if (k > EPS)
		inter->t0_tmp = dot_product_v3(r_to_p, inter->ray.d) / k;
	if (inter->t0_tmp > inter->t0 || inter->t0_tmp < 0)
		return ;
	inter->obj = plane;
	inter->t0 = inter->t0_tmp;
	inter->t1 = DBL_MAX;

}

void	get_matrix_align_v1_v2(t_u m[4][4], t_tuple v1, t_tuple v2)
{
	t_tuple	u;
	t_u		cos_a;
	t_u		k;

	u = cross_product_v3(v1, v2);
	cos_a = dot_product_v3(v1, v2);
	k = 1.0 / (1.0 + cos_a);
	m[0][0] = u.x * u.x * k + cos_a;
	m[0][1] = u.y * u.x * k - u.z;
	m[0][2] = u.z * u.x * k + u.y;
	m[0][3] = 0;
	m[1][0] = u.x * u.y * k + u.z;
	m[1][1] = u.y * u.y * k + cos_a;
	m[1][2] = u.z * u.y * k - u.x;
	m[1][3] = 0;
	m[2][0] = u.x * u.z * k - u.y;
	m[2][1] = u.y * u.z * k + u.x;
	m[2][2] = u.z * u.z * k + cos_a;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void	world_to_camera(t_rt *rt)
{
	t_u		trans_m4[4][4];
	t_u		tmp[4][4];
	t_tuple	cam_space;

	cam_space.x = 0;
	cam_space.y = 0;
	cam_space.z = -1;
	cam_space.w = 0;
	norm_v3(&cam_space);
	if (check_vector_opposite(cam_space, rt->scn.cam.d))
		rot_y_matrix_4(tmp, M_PI);
	else
		get_matrix_align_v1_v2(tmp, rt->scn.cam.d, cam_space);
	trans_matrix_4(trans_m4, -rt->scn.cam.o.x, -rt->scn.cam.o.y, -rt->scn.cam.o.z);
	mult_matrix_4(rt->wtoc_m, tmp, trans_m4);
	invert_matrix_4(rt->wtoc_m, rt->ctow_m);
	print_tuple(&rt->scn.cam.o, "camo");
	print_tuple(&rt->scn.cam.d, "camd");
	test_world_matrix(rt);
}

t_bool	check_vector_opposite(t_tuple v1, t_tuple v2)
{

	norm_v3(&v1);
	norm_v3(&v2);
	if ((v1.x == -v2.x) && (v1.y == -v2.y) && (v1.z == -v2.z) && (v1.w == v2.w))
		return (TRUE);
	return (FALSE);
}
