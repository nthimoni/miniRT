/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/24 15:36:27 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "transformations.h"
#include "vector.h"
#include "color.h"

static t_tuple find_pos_inter(t_intersect *inter, t_rt *rt)
{
	t_tuple	tmp;

	tmp = inter->ray.d;
	scale_v3(&tmp, inter->t0);
	return (add_tupple(rt->scn.cam.o, tmp));
}

static int	set_specular(t_rt *rt, t_intersect *inter)
{
	t_tuple	light;
	t_tuple	normal;
	t_tuple	position;
	t_u		cos_n_l;

	position = find_pos_inter(inter, rt);
	light = sub_tupple(((t_obj *)rt->scn.light->content)->o, position);
	norm_v3(&light);
	normal = sub_tupple(position, inter->obj->o);
	norm_v3(&normal);
	cos_n_l = dot_product_v3(light, normal);
	if (cos_n_l >= -0.01)
		return (scale_color(inter->obj->color, 0));
	return (scale_color(inter->obj->color, 1.0 - cos_n_l));
}

int	lighting(t_rt *rt, t_intersect *inter)
{
	int	ambiant;
	int	specular;
	int	final;

	ambiant = scale_color(rt->scn.amb.color, rt->scn.amb.ratio);
	specular = set_specular(rt, inter);
	specular = scale_color(specular, ((t_obj *)rt->scn.light->content)->ratio);
	(void)ambiant, (void)specular;
	final = create_trgb(0, get_r(ambiant) + get_r(specular),
			get_g(ambiant) + get_g(specular), get_b(ambiant) + get_b(specular));
	//return (inter->obj->color);
	final = scale_color(final, 0.8);
	return final;
	if (specular == 0)
		return (ambiant);
	return (specular);
}
