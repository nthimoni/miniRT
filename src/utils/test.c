/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:56:21 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/11 18:30:54 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ray.h"

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

void	test_wtoo(t_rt *rt)
{
	t_list	*tmp;
	t_obj	*obj;
	t_tuple	r_vec3;
	t_tuple	t[2];

	tmp = rt->scn.objs;
	while (tmp)
	{
		obj = tmp->content;
		r_vec3 = cross_product_v3(create_tuple_pts(0, 1, 0, 0), obj->d);
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
