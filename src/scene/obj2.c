/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:04 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 16:26:23 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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
