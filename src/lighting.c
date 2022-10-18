/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/18 23:40:26 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "vector.h"
#include "color.h"

static int	set_specular(t_rt *rt, t_intersect *inter)
{
	t_tuple	light;
	t_tuple	normal;
	t_u		cos_n_l;

	light = sub_tupple(((t_obj *)rt->scn.light->content)->o, inter->pixel);
	norm_v3(&light);
	normal = sub_tupple(inter->pixel, inter->obj->o);
	norm_v3(&normal);
	cos_n_l = dot_product_v3(normal, light);
	printf("cos : %lf\n", cos_n_l);
	if (cos_n_l > 0)
		return (create_trgb(0, 0, 0, 0));
	return (scale_color(inter->obj->color, -cos_n_l));
}

int	lighting(t_rt *rt, t_intersect *inter)
{
	int	ambiant;
	int	specular;

	ambiant = scale_color(rt->scn.amb.color, rt->scn.amb.ratio);
	specular = set_specular(rt, inter);
	(void)ambiant, (void)specular;
	//return (inter->obj->color);
	return (specular);
}
