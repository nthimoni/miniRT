/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/11/02 19:22:12 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "transformations.h"
#include "vector.h"
#include "color.h"

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
/*
static int	set_diffuse(t_rt *rt, t_intersect *inter, int *specular)
{
	t_tuple	light;
	t_tuple	normal;
	t_tuple	position;
	t_u		cos_n_l;

	cos_n_l = dot_product_v3(light, normal);
	*specular = set_specular(&normal, &light, &position, rt);
	if (cos_n_l <= 0.01)
		return (scale_color(((t_obj *)rt->scn.light->content)->color, 0));
	return (scale_color(((t_obj *)rt->scn.light->content)->color, cos_n_l));
}
*/
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
/*
int	lighting(t_rt *rt, t_intersect *inter)
{
	int	ambiant;
	int	diffuse;
	int	specular;
	int	final;

	ambiant = sub_synthese(inter->obj->color, rt->scn.amb.color, rt->scn.amb.ratio);
	diffuse = set_diffuse(rt, inter, &specular);
	(void)ambiant, (void)diffuse;
	diffuse = sub_synthese(inter->obj->color, diffuse, ((t_obj *)rt->scn.light->content)->ratio);
	final = create_trgb(0, get_r(ambiant), get_g(ambiant), get_b(ambiant));
	inc_color(&final, get_r(diffuse), get_g(diffuse), get_b(diffuse));
	inc_color(&final, get_r(specular), get_g(specular), get_b(specular));
	return final;
}
*/
int	set_diffuse(t_surface *sfc, t_tuple *light_v, t_obj *light)
{
	t_u		cos_n_l;

	cos_n_l = dot_product_v3(*light_v, sfc->normal);
	if (cos_n_l <= 0.01)
		return (0);
	return (scale_color(light->color, cos_n_l));
}


static void	set_normal_position(t_rt *rt, t_intersect *inter, t_surface *sfc)
{

	sfc->pos = find_pos_inter(inter, rt);
	switch (inter->obj->type)
	{
		case SPHERE:
			sfc->normal = sub_tupple(sfc->pos, inter->obj->o);
			break;
		case PLAN:
			sfc->normal = inter->obj->d;
		default:
			break;
	}
}

int	set_specular(t_surface *sfc, t_tuple *light_v, t_rt *rt, t_obj *light)
{
	t_tuple	cam;
	t_tuple reflection;
	t_u		cos_r_c;
	t_u		factor;
	int		color;

	reflection.x = sfc->normal.x + (sfc->normal.x - light_v->x);
	reflection.y = sfc->normal.y + (sfc->normal.y - light_v->y);
	reflection.z = sfc->normal.z + (sfc->normal.z - light_v->z);
	cam = sub_tupple(rt->scn.cam.o, sfc->pos);
	norm_v3(&cam);
	norm_v3(&reflection);
	cos_r_c= dot_product_v3(reflection, cam);
	if (cos_r_c <= 0.01)
		return (0);
	factor = pow(cos_r_c, 350);
	color = scale_color(light->color, factor);
	color = scale_color(color, light->ratio);
	return (color);
}

int lighting(t_rt *rt, t_intersect *inter)
{
	int			tmp;
	int			final;
	t_surface	sfc;
	t_list		*light;
	t_tuple		light_v;	

	set_normal_position(rt, inter, &sfc);
	norm_v3(&sfc.normal);
	final = sub_synthese(inter->obj->color, rt->scn.amb.color, rt->scn.amb.ratio);
	light = rt->scn.light;
	while (light)
	{
		light_v = sub_tupple(((t_obj *)light->content)->o, sfc.pos);
		norm_v3(&light_v);
		tmp = set_diffuse(&sfc, &light_v, light->content);
		tmp = sub_synthese(inter->obj->color, tmp, ((t_obj *)light->content)->ratio);
		inc_color(&final, get_r(tmp), get_g(tmp), get_b(tmp));
		tmp = set_specular(&sfc, &light_v, rt, light->content);
		inc_color(&final, get_r(tmp), get_g(tmp), get_b(tmp));
		light = light->next;
	}
	return (final);
}
