/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isShadowed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:48:40 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/02 20:56:26 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "ray.h"
#include "vector.h"
#include "libft.h"

int	isShadowed(t_rt *rt, t_tuple pos, t_tuple light_v, t_intersect *o_inter)
{
	t_intersect	inter;
	t_u			length;

	length = length_v3(light_v);
	norm_v3(&light_v);
	ft_bzero(&inter, sizeof(inter));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	inter.obj_ign = o_inter->obj;
	scale_v3(&light_v, -1);
	inter.ray.d = light_v;
	//scale_v3(&light_v, 0.1);
	//inter.ray.o = add_tupple(pos, light_v);
	inter.ray.o = pos;
	intersect_obj(rt, &inter);
	if (inter.obj && inter.t0 < length)
		return 1;
	return 0;
}
