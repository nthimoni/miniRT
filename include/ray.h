/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:31 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/13 22:03:03 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H 

# include "miniRT.h"

void	create_ray(t_ray *new, t_tuple p, t_tuple v);
void	position(t_tuple *new, t_ray r, t_tuple p);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);
void	init_inter(t_rt *rt);
void	world_to_camera(t_rt *rt);
void	init_pixel(t_rt *rt);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);
void	test_sphere_init(t_rt *rt);
t_bool	solve_quadratic(t_intersect *inter, t_quadra q);
int		ft_sign(t_u i);
void	intersect_obj(t_rt *rt, t_intersect *inter, int i, int j);
void	get_matrix_align_v1_v2(t_u m[4][4], t_tuple v1, t_tuple v2);
t_u		clamp(t_u nb);


#endif 
