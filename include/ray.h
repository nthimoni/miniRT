/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:31 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/20 15:16:10 by rmorel           ###   ########.fr       */
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
# include <float.h>

void	create_ray(t_ray *new, t_tuple p, t_tuple v);
void	position(t_tuple *new, t_ray r, t_tuple p);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);
void	init_inter(t_rt *rt);
void	world_to_camera(t_rt *rt);
void	init_pixel(t_rt *rt);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);
t_bool	solve_quadratic(t_intersect *inter, t_quadra q);
int		ft_sign(t_u i);
void	fill_obj(t_rt *rt);
void	intersect_obj(t_rt *rt, t_intersect *inter, int i, int j);
void	intersect_sph(t_obj	*sph, t_intersect *inter);
void	intersect_sph2(t_obj *sph, t_intersect *inter);
void	intersect_plane(t_obj *plane, t_intersect *inter);
void	get_matrix_align_v1_v2(t_u m[4][4], t_tuple v1, t_tuple v2);
t_bool	check_vector_opposite(t_tuple v1, t_tuple v2);


#endif 
