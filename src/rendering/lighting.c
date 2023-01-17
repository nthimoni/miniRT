/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:50 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/17 18:32:50 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "lighting.h"
#include "data_struct.h"
#include "transformations.h"
#include "vector.h"
#include "color.h"
#include "checker.h"

typedef struct s_surface
{
	t_tuple normal;
	t_tuple pos;
}	t_surface;


static t_tuple	find_pos_inter(t_intersect *inter, t_rt *rt)
{
	t_tuple	tmp;

	tmp = inter->ray.d;
	scale_v3(&tmp, inter->t0);
	return (add_tupple(rt->scn.cam.o, tmp));
}

static int	sub_synthese(int obj_color, int light_color, double ratio_light)
{
	int		r;
	int		g;
	int		b;
	double	coef;

	(void)ratio_light;
	coef = (get_r(light_color) * 1.0) / 255.0;
	r = get_r(obj_color) * coef * ratio_light;
	coef = (get_g(light_color) * 1.0) / 255.0;
	g = get_g(obj_color) * coef * ratio_light;
	coef = (get_b(light_color) * 1.0) / 255.0;
	b = get_b(obj_color) * coef * ratio_light;
	return (create_trgb(0, r, g, b));
}

static void	inc_color(int *color, int r, int g, int b)
{
	if (r + get_r(*color) > 255)
		r = 255;
	else
		r += get_r(*color);
	if (g + get_g(*color) > 255)
		g = 255;
	else
		g += get_g(*color);
	if (b + get_b(*color) > 255)
		b = 255;
	else
		b += get_b(*color);
	*color = create_trgb(0, r, g, b);
}

int	set_diffuse(t_surface *sfc, t_tuple *light_v, t_obj *light)
{
	t_u		cos_n_l;

	cos_n_l = dot_product_v3(*light_v, sfc->normal);
	if (cos_n_l <= 0.01)
		return (0);
	return (scale_color(light->color, cos_n_l));
}

int	set_specular(t_surface *sfc, t_tuple *light_v, t_rt *rt, t_obj *light)
{
	t_tuple	cam;
	t_tuple reflection;
	t_u		cos_r_c;
	t_u		factor;
	int		color;

	reflection = sfc->normal;
	light_v->x = -light_v->x;
	light_v->y = -light_v->y;
	light_v->z = -light_v->z;
	scale_v3(&reflection, 2 * dot_product_v3(*light_v, sfc->normal));
	reflection = sub_tupple(*light_v, reflection);
	cam = sub_tupple(rt->scn.cam.o, sfc->pos);
	norm_v3(&cam);
	norm_v3(&reflection);
	cos_r_c = dot_product_v3(reflection, cam);
	if (cos_r_c <= 0.01)
		return (0);
	factor = pow(cos_r_c, 500);
	color = scale_color(light->color, factor);
	color = scale_color(color, light->ratio);
	return (color);
}

void	define_uv(t_intersect *inter, t_tuple *pos)
{
	t_otype type;

	type = inter->obj->type;
	if (type == SPHERE)
		inter->uv = uv_sphere(pos);
	else if (type == CYLINDRE)
		inter->uv = uv_cylindre(pos);
	else if (type == PLAN)
		inter->uv = uv_plan(pos);
	else if (type == CONE)
		inter->uv = uv_cone(pos);
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
				(&inter->obj->img_bump,inter->uv, &sfc->normal));
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

int lighting(t_rt *rt, t_intersect *inter)
{
	int			tmp;
	int			final;
	t_surface	sfc;
	t_list		*light;
	t_tuple		light_v;	

	if (!inter->obj)
		return 0;
	ft_bzero(&sfc, sizeof(t_surface));
	define_normal_pos(rt, &sfc, inter);
	define_color(inter);
	final = sub_synthese(inter->obj->color, rt->scn.amb.color, rt->scn.amb.ratio);
	light = rt->scn.light;
	while (light)
	{
		light_v = sub_tupple(sfc.pos, ((t_obj *)light->content)->o);
		if (!isShadowed(rt, sfc.pos, light_v, inter))
		{
			norm_v3(&light_v);
			tmp = set_diffuse(&sfc, &light_v, light->content);
			tmp = sub_synthese(inter->obj->color, tmp, ((t_obj *)light->content)->ratio);
			inc_color(&final, get_r(tmp), get_g(tmp), get_b(tmp));
			tmp = set_specular(&sfc, &light_v, rt, light->content);
			inc_color(&final, get_r(tmp), get_g(tmp), get_b(tmp));
		}
		light = light->next;
	}
	return (final);
}
