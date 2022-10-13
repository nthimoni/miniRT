/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:56:21 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/13 23:00:15 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "test.h"
#include "print.h"
#include "matrix.h"
#include "vector.h"
#include "transformations.h"
#include <math.h>

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
	t_tuple	cam_space;

	cam_space.x = 0;
	cam_space.y = 0;
	cam_space.z = -1;
	cam_space.w = 0;
	print_matrix_4(rt->wtoc_m, "wtoc");
	print_matrix_4(rt->ctow_m, "ctow");
	printf("\n");
	print_tuple(&cam_space, "cam_space");
	mult_tuple_matrix_4(&cam_space, rt->ctow_m, cam_space);
	print_tuple(&cam_space, "cam_space * ctow");
	mult_tuple_matrix_4(&cam_space, rt->wtoc_m, cam_space);
	print_tuple(&cam_space, "cam_space * wtoc");
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
