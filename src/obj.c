/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bek <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:07:02 by bek               #+#    #+#             */
/*   Updated: 2022/12/07 20:48:18 by nthimoni         ###   ########.fr       */
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
	trans_matrix_4(m.tra, obj->o.x, obj->o.y, obj->o.z);
	if (check_x_plane(obj->d))
		identity_matrix_4(m.rot);
	else
		get_matrix_align_v1_v2(m.rot, create_tuple_pts(0, 1, 0, 0), obj->d);
	scale_matrix_4(m.sca, obj->diam /2, 1, obj->diam /2);
	mult_matrix_4(m.tmp, m.rot, m.sca);
	mult_matrix_4(obj->otow_m, m.tra, m.tmp);
	invert_matrix_4(obj->otow_m, obj->wtoo_m);
	get_cylinder_top(obj);
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
