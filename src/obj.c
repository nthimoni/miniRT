/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bek <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:07:02 by bek               #+#    #+#             */
/*   Updated: 2023/01/02 14:22:10 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	get_cylinder_top(t_obj *cyl)
{
	t_tuple	dir_cpy;;

	dir_cpy = create_tuple_copy(cyl->d);
	scale_v3(&dir_cpy, cyl->height);
	cyl->top = add_tupple(dir_cpy, cyl->o); 
	cyl->top.w = 1;
}

static t_bool	check_x_plane(t_tuple d)
{
	if (d.x == 0 && d.z == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	cylinder_matrix(t_obj_matrix m, t_obj *obj)
{
	get_cylinder_top(obj);
	trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	if (check_x_plane(obj->d))
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	scale_matrix_4(m.sca, obj->diam /2, 1, obj->diam /2);
	mult_matrix_4(m.tmp, m.rot, m.sca);
	mult_matrix_4(obj->otow_m, m.tra, m.tmp);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
	mult_tuple_matrix_4(&obj->top_obj, obj->wtoo_m, obj->top);
	mult_tuple_matrix_4(&obj->o_obj, obj->wtoo_m, obj->o);
}

void	cone_matrix(t_obj_matrix m, t_obj *obj)
{
//	t_u 	m_trans_2[4][4];
//	t_tuple	top_obj_tmp;

//	ft_bzero(m_trans_2, sizeof(t_u[4][4]));
//	ft_bzero(&top_obj_tmp, sizeof(t_tuple));
	get_cylinder_top(obj);
	//print_tuple(&obj->top, "top");
	trans_matrix_4(m.tra, obj->top.x, obj->top.y, obj->top.z);
	//print_matrix_4(m.tra, "m.tra");
	if (check_x_plane(obj->d))
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	scale_matrix_4(m.sca, obj->diam / 2, obj->height, obj->diam / 2);
	mult_matrix_4(m.tmp, m.rot, m.sca);
	mult_matrix_4(obj->otow_m, m.tra, m.tmp);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
//	mult_tuple_matrix_4(&top_obj_tmp, obj->wtoo_m, obj->top); 
//	trans_matrix_4(m_trans_2, 0, top_obj_tmp.y, 0);
//	mult_matrix_4bis(&obj->otow_m, m_trans_2, obj->otow_m);
//	invert_matrix_4(obj->otow_m, obj->wtoo_m);
	mult_tuple_matrix_4(&obj->top_obj, obj->wtoo_m, obj->top);
	mult_tuple_matrix_4(&obj->o_obj, obj->wtoo_m, obj->o);
	print_tuple(&obj->o_obj, "obj->o_obj");
	print_tuple(&obj->top_obj, "obj->top_obj");
}

void	sphere_matrix(t_obj_matrix m, t_obj *obj)
{
	trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	scale_matrix_4(m.sca, obj->diam /2, obj->diam /2, obj->diam /2);
	mult_matrix_4(obj->otow_m, m.tra, m.sca);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
}

void	plan_matrix(t_obj_matrix m, t_obj *obj)
{
	trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	if (check_x_plane(obj->d))
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	mult_matrix_4(obj->otow_m, m.tra, m.rot);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
}
