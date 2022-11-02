/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:41:56 by rmorel            #+#    #+#             */
/*   Updated: 2022/11/02 18:14:58 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	intersect_plane(t_obj *plane, t_intersect *inter)
{
	t_ray		ray2;

	mult_tuple_matrix_4(&ray2.d, plane->wtoo_m, inter->ray.d);
	mult_tuple_matrix_4(&ray2.o, plane->wtoo_m, inter->ray.o);
	if (abs_u(ray2.d.y) < EPS)
		return ;
	inter->t0_tmp = -ray2.o.y / ray2.d.y;
	if (inter->t0_tmp >= inter->t0 || inter->t0_tmp < 0)
		return ;
	inter->obj = plane;
	inter->t0 = inter->t0_tmp;
	inter->t1 = DBL_MAX;
}

