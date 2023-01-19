/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:50 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 03:20:43 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "lighting.h"
#include "transformations.h"
#include "vector.h"
#include "color.h"
#include "checker.h"

static t_tuple	find_pos_inter(t_intersect *inter, t_rt *rt)
{
	t_tuple	tmp;

	tmp = inter->ray.d;
	scale_v3(&tmp, inter->t0);
	return (add_tupple(rt->scn.cam.o, tmp));
}

void	define_normal_pos(t_rt *rt, t_surface *sfc, t_intersect *inter)
{
	sfc->pos = find_pos_inter(inter, rt);
	mult_tuple_matrix_4(&sfc->pos, inter->obj->wtoo_m, sfc->pos);
	if (inter->obj->text != COLOR || inter->obj->bump)
		define_uv(inter, &sfc->pos);
	sfc->normal = inter->normal_w;
	norm_v3(&sfc->normal);
	if (inter->obj->bump)
		sfc->normal = add_tupple(sfc->normal, normal_perturbation
				(&inter->obj->img_bump, inter->uv, &sfc->normal));
	norm_v3(&sfc->normal);
	mult_tuple_matrix_4(&sfc->pos, inter->obj->otow_m, sfc->pos);
}

void	define_color(t_intersect *inter)
{
	if (inter->obj->text == TEXTURE)
		inter->obj->color = color_at(&inter->obj->img_text, inter->uv);
	else if (inter->obj->text == CHECKER)
		inter->obj->color = get_color_checker(inter->uv, inter);
}

void	compute_lighting(t_surface *sfc, t_list *light, t_intersect *i, int *f)
{	
	t_tuple	light_v;	
	int		tmp;

	light_v = sub_tupple(sfc->pos, ((t_obj *)light->content)->o);
	if (!is_shadowed(sfc->rt, sfc->pos, light_v, i))
	{
		norm_v3(&light_v);
		tmp = set_diffuse(sfc, &light_v, light->content);
		tmp = sub_synthese(i->obj->color, tmp,
				((t_obj *)light->content)->ratio);
		inc_color(f, get_r(tmp), get_g(tmp), get_b(tmp));
		tmp = set_specular(sfc, &light_v, sfc->rt, light->content);
		inc_color(f, get_r(tmp), get_g(tmp), get_b(tmp));
	}
}

int	lighting(t_rt *rt, t_intersect *inter)
{
	int			final;
	t_surface	sfc;
	t_list		*light;

	if (!inter->obj)
		return (0);
	ft_bzero(&sfc, sizeof(t_surface));
	sfc.rt = rt;
	define_normal_pos(rt, &sfc, inter);
	define_color(inter);
	final = sub_synthese(inter->obj->color, rt->scn.amb.color,
			rt->scn.amb.ratio);
	light = rt->scn.light;
	while (light)
	{
		compute_lighting(&sfc, light, inter, &final);
		light = light->next;
	}
	return (final);
}
