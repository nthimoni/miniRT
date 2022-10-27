/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/27 22:05:29 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "transformations.h"
#include "vector.h"
#include "color.h"

int	set_specular(t_tuple *normal, t_tuple *light, t_tuple *position, t_rt *rt)
{
	t_tuple	cam;
	t_tuple ref;
	t_u		cos_r_c;
	t_u		factor;
	int		color;

	ref.x = normal->x + (normal->x - light->x);
	ref.y = normal->y + (normal->y - light->y);
	ref.z = normal->z + (normal->z - light->z);
	cam = sub_tupple(rt->scn.cam.o, *position);
	norm_v3(&cam);
	norm_v3(&ref);
	cos_r_c= dot_product_v3(ref, cam);
	if (cos_r_c >= -0.01)
		return (0);
	factor = pow(cos_r_c, 350);
	color = scale_color(((t_obj *)rt->scn.light->content)->color, factor);
	color = scale_color(color, ((t_obj *)rt->scn.light->content)->ratio);
	return (color);
}

static t_tuple	find_pos_inter(t_intersect *inter, t_rt *rt)
{
	t_tuple	tmp;

	tmp = inter->ray.d;
	scale_v3(&tmp, inter->t0);
	return (add_tupple(rt->scn.cam.o, tmp));
}

static int	set_diffuse(t_rt *rt, t_intersect *inter, int *specular)
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
	*specular = set_specular(&normal, &light, &position, rt);
	if (cos_n_l <= 0.01)
	{
		//*specular = 0;
		return (scale_color(((t_obj *)rt->scn.light->content)->color, 0));
	}
	return (scale_color(((t_obj *)rt->scn.light->content)->color, cos_n_l));
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
	if (diffuse == 0)
		return (ambiant);
	return (diffuse);
}
