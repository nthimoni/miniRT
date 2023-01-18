/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isShadowed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:48:40 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/18 16:39:52 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "ray.h"
#include "vector.h"
#include "libft.h"

static void	intersect_obj_shadow(t_rt *rt, t_intersect *inter, t_u len);

int	isShadowed(t_rt *rt, t_tuple pos, t_tuple light_v, t_intersect *o_inter)
{
	t_intersect	inter;
	t_u			length;

	length = length_v3(light_v);
	norm_v3(&light_v);
	ft_bzero(&inter, sizeof(inter));
	inter.t0 = DBL_MAX;
	inter.t1 = DBL_MAX;
	if (o_inter->obj && o_inter->obj->type == PLAN)
		inter.obj_ign = o_inter->obj;
	inter.ray.d = light_v;
	inter.ray.o = pos;
	intersect_obj_shadow(rt, &inter, length);
	if (inter.obj && (inter.t0 < length || inter.t1 < length))
		return 1;
	return 0;
}

static void	intersect_obj_shadow(t_rt *rt, t_intersect *inter, t_u len)
{
	t_list	*tmp;

	tmp = rt->scn.objs;
	while (tmp && inter->t0 > len)
	{
		if (inter->obj_ign != tmp->content)
		{	
			if (((t_obj *)tmp->content)->type == SPHERE)
			{
				if (rt->space == WORLD)
					intersect_sph(tmp->content, inter, inter->ray);
				else if (rt->space == OBJ)
					intersect_sph2(tmp->content, inter, inter->ray);
			}
			else if (((t_obj *)tmp->content)->type == PLAN)
				intersect_plane(tmp->content, inter, inter->ray);
			else if (((t_obj *)tmp->content)->type == CYLINDRE)
				intersect_cylinder(tmp->content, inter, inter->ray);
			else if (((t_obj *)tmp->content)->type == CONE)
				intersect_cone(tmp->content, inter, inter->ray);
		}
		tmp = tmp->next;
	}
}
