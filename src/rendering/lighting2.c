/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:09:53 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 03:20:33 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "lighting.h"
#include "transformations.h"
#include "vector.h"
#include "color.h"
#include "checker.h"

void	define_uv(t_intersect *inter, t_tuple *pos)
{
	t_otype	type;

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

int	sub_synthese(int obj_color, int light_color, double ratio_light)
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

void	inc_color(int *color, int r, int g, int b)
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
	t_tuple	reflection;
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
