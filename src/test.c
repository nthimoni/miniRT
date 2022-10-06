/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:56:21 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/06 17:36:29 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "test.h"
#include "print.h"
#include "matrix.h"
#include "vector.h"

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
	t_decimal	arr1[4] = {1, 0, 0, 1};
	t_decimal	arr2[4] = {0, 1, 0, 1};
	t_decimal	arr3[4] = {0, 0, 1, 1};
	t_decimal	arr4[4] = {1, 1, 1, 1};
	t_decimal	arr5[4] = {1, 2, 3, 0};
	t_decimal	arr6[4] = {2, 3, 4, 0};

	p1 = create_tuple(arr1);
	p2 = create_tuple(arr2);
	p3 = create_tuple(arr3);
	p4 = create_tuple(arr4);
	v1 = create_v3(p1, p2);
	v2 = create_v3(p2, p1);
	v3 = create_tuple(arr5);
	v4 = create_tuple(arr6);
	v5 = cross_product_v3(v3, v4);
	v6 = norm_v3(v3);
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
	t_decimal	arr1[4] = {0, 10, 0, 1};
	t_decimal	arr2[4] = {20, 40, 0};
	t_decimal	arr3[4] = {0, -1, 0, 0};
	t_decimal	arr4[4] = {-0.01, 0, 0, 0};
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
	t_decimal	m1[4][4];
	t_decimal	m2[4][4];
	t_decimal	m3[4][4];

	matrix_ex1(m1);
	print_matrix4(m1, "m1");
	matrix_ex2(m2);
	print_matrix4(m2, "m2");
	m3 = mult_matrix_x(4, m1, m2);
	print_matrix4(m3, "m3");
	m1 = transpose_matrix(m1, 4);
	print_matrix4(m1, "m1");
	m1 = sub_matrix(m1, 4, 2, 2);
	print_matrix4(m1, "m1 sub");
	(void)rt;
}
