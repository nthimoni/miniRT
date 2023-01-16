/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:39:45 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/16 14:45:43 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	cone_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x);
static void	sphere_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x);
static void	plan_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x);
static void	cylinder_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x);

void	get_normal(t_intersect *i, t_ray *ray, t_obj *obj)
{
	t_tuple	intersection;

	intersection = find_pos_inter(*ray, i->t0_tmp);
//	if (obj->type == SPHERE)
//		sphere_normal(i, ray, obj, &intersection);
//	else if (obj->type == PLAN)
//		plan_normal(i, ray, obj, &intersection);
//	else if (obj->type == CYLINDRE)
//		cylinder_normal(i, ray, obj, &intersection);
	if (obj->type == CONE)
		cone_normal(i, ray, obj, &intersection);
	norm_v3(&i->normal_w);
}

static void	cone_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x)
{
	t_u		angle_cone;
	t_tuple	obj_to_inter;
	t_tuple	scaled_direction;

	(void)ray;
	angle_cone = 0;
	if (obj->height)
		angle_cone = atan(obj->diam / 2 / obj->height);
	obj_to_inter = sub_tupple(obj->o, *x);
	scaled_direction = create_tuple_copy(obj->d);
	scale_v3(&scaled_direction, length_v3(obj_to_inter) / cos(angle_cone));
	i->normal_w = sub_tupple(scaled_direction, obj_to_inter);
}

static void	sphere_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x)
{
	(void)ray;
	i->normal_w = sub_tupple(obj->o, *x);
}

static void	plan_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x)
{
	(void)ray;
	(void)x;
	i->normal_w = create_tuple_copy(obj->d);
}

static void	cylinder_normal(t_intersect *i, t_ray *ray, t_obj *obj, t_tuple *x)
{
	t_tuple obj_to_ray;
	t_tuple	scaled_direction;
	t_u		m;
	t_tuple	y;

	obj_to_ray = sub_tupple(obj->o, ray->o);
	scaled_direction = create_tuple_copy(obj->d);
	scale_v3(&scaled_direction, i->t0);
	m = dot_product_v3(ray->d, scaled_direction) + dot_product_v3(obj_to_ray, obj->d); 
	scaled_direction = create_tuple_copy(obj->d);
	scale_v3(&scaled_direction, m);
	y = add_tupple(obj->o, scaled_direction);
	i->normal_w = sub_tupple(y, *x);
}

