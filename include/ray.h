/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:31 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/09 13:24:48 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H 

# include "data_struct.h"
# include "matrix.h"
# include "transformations.h"
# include "print.h"
# include "test.h"
# include "vector.h"
# include "scene.h"
# include <float.h>

void	init_inter(t_rt *rt);
void	init_pixel(t_rt *rt);
void	init_pixel_aa(t_rt *rt);
void	draw_pixel_aa(int i_j[2], t_rt *rt);
void	intersect_obj(t_rt *rt, t_intersect *inter);
t_u		abs_u(t_u n);

//		sphere.c

void	intersect_sph(t_obj	*sph, t_intersect *inter, t_ray ray);
void	intersect_sph2(t_obj *sph, t_intersect *inter, t_ray ray);

//		plane.c

void	intersect_plane(t_obj *plane, t_intersect *inter, t_ray ray);

//		cylinder.h

void	intersect_cylinder(t_obj *cyl, t_intersect *inter, t_ray ray);
void	normal_endcap(t_tuple point, t_obj *cyl, t_tuple *normal);
void	normal_cylinder(t_tuple point, t_obj *cyl, t_tuple *normal);

//		cone.h

void	intersect_cone(t_obj *cyl, t_intersect *inter, t_ray ray);

//		debug.c

void	init_pixel_debug(t_rt *rt);
void	intersect_obj_debug(t_rt *rt, t_intersect *inter, int i, int j);
void	intersect_sph2_debug(t_obj *sph, t_intersect *inter, t_ray ray);

//		intersect.c

t_bool	solve_quadratic(t_intersect *inter, t_quadra q);
void	add_inter0(t_intersect *i, t_obj *o, t_u t);
void	add_inter1(t_intersect *i, t_obj *o, t_u t);
t_tuple	find_pos_inter(t_ray ray, t_u t);

#endif 
