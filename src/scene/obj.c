/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bek <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:07:02 by bek               #+#    #+#             */
/*   Updated: 2023/01/11 17:38:30 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	get_cylinder_top(t_obj *cyl)
{
	t_tuple	dir_cpy;

	dir_cpy = create_tuple_copy(cyl->d);
	scale_v3(&dir_cpy, cyl->height);
	cyl->top = add_tupple(dir_cpy, cyl->o);
	cyl->top.w = 1;
}

void	cylinder_matrix(t_obj_matrix m, t_obj *obj)
{
	get_cylinder_top(obj);
	scale_matrix_4(m.sca, obj->diam / 2, obj->height, obj->diam / 2);
	if (obj->d.x == 0 && obj->d.z == 0 && obj->d.y < 0)
		rot_z_matrix_4(m.rot, M_PI);
	else if (obj->d.x == 0 && obj->d.z == 0)
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	mult_matrix_4(m.tmp, m.rot, m.sca);
	if (obj->d.x == 0 && obj->d.z == 0 && obj->d.y < 0)
		trans_matrix_4(m.tra, obj->top.x, obj->top.y, obj->top.z);
	else
		trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	mult_matrix_4(obj->otow_m, m.tra, m.tmp);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
	mult_tuple_matrix_4(&obj->top_obj, obj->wtoo_m, obj->top);
	mult_tuple_matrix_4(&obj->o_obj, obj->wtoo_m, obj->o);
}

void	cone_matrix(t_obj_matrix m, t_obj *obj)
{
	get_cylinder_top(obj);
	scale_matrix_4(m.sca, obj->diam / 2, obj->height, obj->diam / 2);
	if (obj->d.x == 0 && obj->d.z == 0)
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	mult_matrix_4(obj->otow_m_rs, m.rot, m.sca);
	trans_matrix_4(m.tra, obj->top.x, obj->top.y, obj->top.z);
	mult_matrix_4(obj->otow_m, m.tra, obj->otow_m_rs);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
	invert_matrix_4(obj->otow_m_rs, obj->wtoo_m_inv_rs);
	mult_tuple_matrix_4(&obj->top_obj, obj->wtoo_m, obj->top);
	mult_tuple_matrix_4(&obj->o_obj, obj->wtoo_m, obj->o);
}

void	sphere_matrix(t_obj_matrix m, t_obj *obj)
{
	scale_matrix_4(m.sca, obj->diam / 2, obj->diam / 2, obj->diam / 2);
	trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	mult_matrix_4(obj->otow_m, m.tra, m.sca);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
}

void	plan_matrix(t_obj_matrix m, t_obj *obj)
{
	trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	if (obj->d.x == 0 && obj->d.z == 0)
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	mult_matrix_4(obj->otow_m, m.tra, m.rot);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
}
