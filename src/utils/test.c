/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:56:21 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/11 21:19:26 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ray.h"

void	test(t_rt *rt)
{
	t_tuple		p1;
	t_tuple		p2;
	t_tuple		p3;
	t_tuple		p4;
	t_tuple		v1;
	t_tuple		v2;
	t_tuple		v3;
	t_tuple		v4;
	t_tuple		v5;
	t_tuple		v6;
	t_u	arr1[4] = {1, 0, 0, 1};
	t_u	arr2[4] = {0, 1, 0, 1};
	t_u	arr3[4] = {0, 0, 1, 1};
	t_u	arr4[4] = {1, 1, 1, 1};
	t_u	arr5[4] = {1, 2, 3, 0};
	t_u	arr6[4] = {2, 3, 4, 0};

	p1 = create_tuple(arr1);
	p2 = create_tuple(arr2);
	p3 = create_tuple(arr3);
	p4 = create_tuple(arr4);
	v1 = create_v3(p1, p2);
	v2 = create_v3(p2, p1);
	v3 = create_tuple(arr5);
	v4 = create_tuple(arr6);
	v5 = cross_product_v3(v3, v4);
	norm_v3(&v3);
	print_tuple(&p1, "p1");
	print_tuple(&p2, "p2");
	print_tuple(&p3, "p3");
	print_tuple(&p4, "p4");
	print_tuple(&v1, "v1");
	print_tuple(&v2, "v2");
	print_tuple(&v3, "v3");
	print_tuple(&v4, "v4");
	print_tuple(&v5, "v5");
	print_tuple(&v6, "v6");
	printf("Length v1 = %lf\n", length_v3(v1));
	printf("Length v4 = %lf\n", length_v3(v4));
	printf("Length v6 = %lf\n", length_v3(v6));
	(void)rt;
}

void	test2(t_rt *rt)
{
	t_proj		proj;
	t_tuple		gravity;
	t_tuple		wind;
	t_u	arr1[4] = {0, 10, 0, 1};
	t_u	arr2[4] = {20, 40, 0};
	t_u	arr3[4] = {0, -1, 0, 0};
	t_u	arr4[4] = {-0.01, 0, 0, 0};
	int			i;
	int			j;
	int			k;

	i = 0;
	proj.position = create_tuple(arr1);
	proj.velocity = create_tuple(arr2);
	gravity = create_tuple(arr3);
	wind = create_tuple(arr4);
	j = -2;
	k = -2;
	while (i < 200)
	{
		while (j < 2)
		{
			while (k < 2)
			{
				if ((int)proj.position.y + k > 0 && (int)proj.position.y + k < W_H && (int)proj.position.x + j > 0 &&  (int)proj.position.x + j < W_W)
					my_mlx_pixel_put(rt, (int)proj.position.x + j, W_H - (int)proj.position.y - k, create_trgb(0, 255, 0, 0));
				k++;
			}
			j++;
			k = -2;
		}
		j = -2;
		proj = tick_environment(proj, gravity, wind);
		i++;
	}
}

t_proj	tick_environment(t_proj proj, t_tuple gravity, t_tuple wind)
{
	//printf("proj.position x = %lf y = %f\n", proj.position.x, proj.position.y);
	proj.position = add_tupple(proj.position, proj.velocity);
	proj.velocity = add_tupple(proj.velocity, gravity);
	proj.velocity = add_tupple(proj.velocity, wind);
	return (proj);
}

void	test3(t_rt *rt)
{
	t_u	m1[4][4];
	t_u	m2[4][4];
	t_u	m3[4][4];
	t_u	m4[3][3];
	t_u	m5[2][2];
	t_u	m6[4][4];
	t_u	ret;

	ft_bzero(&m1, sizeof(m1));
	ft_bzero(&m2, sizeof(m2));
	ft_bzero(&m3, sizeof(m3));
	ft_bzero(&m4, sizeof(m4));
	ft_bzero(&m5, sizeof(m5));
	ft_bzero(&m6, sizeof(m6));
	matrix_ex1(m1);
	print_matrix_4(m1, "m1");
	transpose_matrix_4(m1, m2);
	print_matrix_4(m2, "m2 = m1 transpose");
	sub_matrix_4(m2, 2, 2, m4);
	print_matrix_3(m4, "m4 = m2 sub(2, 2)");
	sub_matrix_3(m4, 0, 0, m5);
	print_matrix_2(m5, "m5 = m4 sub(0, 0)");
	matrix_ex3(m4);
	ret = minor_matrix_3(m4, 0, 0);
	printf("Minor m4(0, 0) = %lf\n", ret);
	ret = cofactor_matrix_3(m4, 0, 0);
	printf("Cofact m4(0, 0) = %lf\n", ret);
	ret = minor_matrix_3(m4, 1, 0);
	printf("Minor m4(1, 0) = %lf\n", ret);
	ret = cofactor_matrix_3(m4, 1, 0);
	printf("Cofact m4(1, 0) = %lf\n", ret);
	ret = det_matrix_3(m4);
	printf("Det m4 = %lf\n", ret);
	matrix_ex2(m3);
	print_matrix_4(m3, "m3");
	ret = det_matrix_4(m3);
	printf("Det m3 = %lf\n", ret);
	identity_matrix_4(m3);
	print_matrix_4(m3, "m3");
	invert_matrix_4(m3, m6);
	print_matrix_4(m6, "m4");
	matrix_ex2(m3);
	print_matrix_4(m3, "m3");
	invert_matrix_4(m3, m6);
	print_matrix_4(m6, "m6 = inverse(m3)");
	mult_matrix_4(m1, m3, m6);
	print_matrix_4(m1, "m1 = m3 * m6");
	(void)ret;
	(void)rt;
}

void	test4(t_rt *rt)
{
	t_tuple	pos;
	t_u		arr1[4] = {0, 0, 0, 1};
	t_u		m_trans[4][4];
	t_u		m_rotate[4][4];
	t_u		angle;
	int		i;

	pos = create_tuple(arr1);
	trans_matrix_4(m_trans, 0, 300, 0);
	mult_tuple_matrix_4(&pos, m_trans, pos);
	angle = 30 * M_PI / 180;
	i = 0;
	while (i < 12)
	{
		print_point_test4(rt, pos);
		rot_z_matrix_4(m_rotate, angle);
		mult_tuple_matrix_4(&pos, m_rotate, pos);
		i++;
	}
}

void	print_point_test4(t_rt *rt, t_tuple pos)
{
	int			j;
	int			k;

	j = -4;
	k = -4;
	pos.x += W_W / 2;
	pos.y += W_H / 2;
	printf("M2 pos.x = %lf pos.y = %lf\n", pos.x, pos.y);
	while (j < 4)
	{
		while (k < 4)
		{
			if ((int)pos.y + k > 0 && (int)pos.y + k < W_H && (int)pos.x + j > 0 &&  (int)pos.x + j < W_W)
			{
				my_mlx_pixel_put(rt, (int)pos.x + j, W_H - (int)pos.y - k, create_trgb(0, 0, 255, 0));
			}
			k++;
		}
		j++;
		k = -4;
	}
}

void	test_world_matrix(t_rt *rt)
{
	print_matrix_4(rt->wtoc_m, "wtoc");
	print_matrix_4(rt->ctow_m, "ctow");
	printf("\n");
	print_tuple(&rt->scn.cam.d, "rt->scn.cam.d");
	mult_tuple_matrix_4(&rt->scn.cam.d, rt->wtoc_m, rt->scn.cam.d);
	print_tuple(&rt->scn.cam.d, "rt->scn.cam.d * wtoc");
	mult_tuple_matrix_4(&rt->scn.cam.d, rt->ctow_m, rt->scn.cam.d);
	print_tuple(&rt->scn.cam.d, "rt->scn.cam.d * ctow");
	printf("\n");
	print_tuple(&rt->scn.cam.o, "rt->scn.cam.o");
	mult_tuple_matrix_4(&rt->scn.cam.o, rt->wtoc_m, rt->scn.cam.o);
	print_tuple(&rt->scn.cam.o, "rt->scn.cam.o * wtoc");
	mult_tuple_matrix_4(&rt->scn.cam.o, rt->ctow_m, rt->scn.cam.o);
	print_tuple(&rt->scn.cam.o, "rt->scn.cam.o * ctow");
	printf("\n");
}

void	test_sphere_init(t_rt *rt)
{
	t_tuple	o1;
	t_tuple	o2;
	t_tuple	o3;
	t_u		arr1[4] = {-20, -20, 150, 1};
	t_u		arr2[4] = {-50, -50, 200, 1};
	t_u		arr3[4] = {-40, 0, 220, 1};

	ft_bzero(&rt->scn.cam, sizeof(t_obj));
	rt->scn.cam.o.x = 0;
	rt->scn.cam.o.y = 0;
	rt->scn.cam.o.z = 0;
	rt->scn.cam.o.w = 1;
	rt->scn.cam.d.x = 0;
	rt->scn.cam.d.y = 0;
	rt->scn.cam.d.z = 1;
	rt->scn.cam.d.w = 0;
	norm_v3(&rt->scn.cam.d);
	rt->scn.cam.FOV = M_PI * 70 / 180;	
	o1 = create_tuple(arr1); 
	o2 = create_tuple(arr2); 
	o3 = create_tuple(arr3); 
	ft_lstadd_back(&rt->scn.objs, ft_lstnew(create_sphere(3, o1, 30, create_trgb(0, 0, 255, 0))));
	printf("sph_color = %d\n", ((t_obj *)rt->scn.objs->content)->color); 
	ft_lstadd_back(&rt->scn.objs, ft_lstnew(create_sphere(3, o2, 50, create_trgb(0, 0, 255, 255))));
	ft_lstadd_back(&rt->scn.objs, ft_lstnew(create_sphere(3, o3, 80, create_trgb(0, 0, 0, 255))));
}

t_obj	*create_sphere(int type, t_tuple origin, float diam, int color)
{
	t_obj	*sph;

	sph = malloc(sizeof(t_obj));
	if (!sph)
		return (NULL);
	sph->type = type; //3
	sph->o.x = origin.x;
	sph->o.y = origin.y;
	sph->o.z = origin.z;
	sph->o.w = origin.w;
	sph->diam = diam;
	sph->color = color;
	return (sph);
}

void	test_wtoo(t_rt *rt)
{
	t_list	*tmp;
	t_obj	*obj;
	t_tuple r_vec3;
	t_tuple	t[2];

	tmp = rt->scn.objs;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->type != CONE)
			tmp = tmp->next;
		else
		{
			r_vec3 = cross_product_v3(create_tuple_pts(0,1,0,0), obj->d);
			norm_v3(&r_vec3);
			scale_v3(&r_vec3, obj->diam / 2);
			t[0] = add_tupple(obj->o, r_vec3);
			scale_v3(&r_vec3, -1);
			t[1] = add_tupple(obj->o, r_vec3);
			printf("\nWORLD coordinate:\n");
			print_cone_test_tuple(obj->o, obj->d, obj->top, t);
			mult_tuple_matrix_4(&t[0], obj->wtoo_m, t[0]);
			mult_tuple_matrix_4(&t[1], obj->wtoo_m, t[1]);
			printf("OBJ coordinate:\n");
			print_cone_test_tuple(obj->o_obj,
					sub_tupple(obj->o_obj, obj->top_obj), obj->top_obj, t);
			tmp = tmp->next;
		}
	}
}

void	cone_intersect(t_intersect *inter, t_ray ray)
{
	t_quadra	q;
	int			res_quad;

	ft_bzero(&q, sizeof(t_quadra));
	q.a = ray.d.x * ray.d.x - ray.d.y * ray.d.y + ray.d.z * ray.d.z;
	q.b = 2 * ray.o.x * ray.d.x - 2 * ray.o.y * ray.d.y 
			+ 2 * ray.o.z * ray.d.z;
	q.c = ray.o.x * ray.o.x - ray.o.y * ray.o.y + ray.o.z * ray.o.z; 
	if (q.a < EPS && q.a > - EPS && q.b < EPS && q.b > - EPS)
		return ;
	else if (q.a < EPS && q.a > - EPS)
	{
		inter->t0_tmp = - q.c / (2 * q.b);
		inter->t1_tmp = DBL_MAX;
	}
	else
	{
		res_quad = solve_quadratic(inter, q);
		print_tuple(&ray.o, "Origin");
		print_tuple(&ray.d, "Direction");
		printf("q.a = %lf, q.b = %lf & q.c = %lf\n", q.a, q.b, q.c);
		printf("t0 = %lf && t1 = %lf\n", inter->t0_tmp, inter->t1_tmp);
		(void)res_quad;
	}
}

void	test_cone(void)
{
	t_ray		ray1;
	t_ray		ray2;
	t_ray		ray3;
	t_ray		ray4;
	t_ray		ray5;
	t_ray		ray6;
	t_intersect	inter;

	ft_bzero(&inter, sizeof(t_intersect));
	ray1.o = create_tuple_pts(0, 0, -5, 0);
	ray1.d = create_tuple_pts(0, 0, 1, 1);
	norm_v3(&ray1.d);
	ray2.o = create_tuple_pts(0, 0, -5, 0);
	ray2.d = create_tuple_pts(1, 1, 1, 1);
	norm_v3(&ray2.d);
	ray3.o = create_tuple_pts(1, 1, -5, 0);
	ray3.d = create_tuple_pts(-0.5, -1, 1, 1);
	norm_v3(&ray3.d);
	ray4.o = create_tuple_pts(0, 0, -5, 0);
	ray4.d = create_tuple_pts(0, 0, 1, 1);
	norm_v3(&ray4.d);
	ray5.o = create_tuple_pts(0, 0, -5, 0);
	ray5.d = create_tuple_pts(1, 1, 1, 1);
	norm_v3(&ray5.d);
	ray6.o = create_tuple_pts(1, 1, -5, 0);
	ray6.d = create_tuple_pts(-0.5, -1, 1, 1);
	norm_v3(&ray6.d);
	cone_intersect(&inter, ray4);
	cone_intersect(&inter, ray5);
	cone_intersect(&inter, ray6);
}

