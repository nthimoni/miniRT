/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bek <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:09:36 by bek               #+#    #+#             */
/*   Updated: 2023/01/11 17:27:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H 

# include "data_struct.h"
# include "matrix.h"
# include "vector.h"
# include "transformations.h"
# include "mlx.h"
# include "image.h"
# include "test.h"

//		camera.c

void	get_matrix_align_v1_v2(t_u m[4][4], t_tuple v1, t_tuple v2);
void	world_to_camera(t_rt *rt);
t_bool	check_vector_opposite(t_tuple v1, t_tuple v2);
void	fill_matrix_obj(t_rt *rt);
void	pixel_raster_to_space(t_intersect *i, t_u x, t_u y, t_rt *rt);

//		rendering.c

void	print_axis(t_rt *rt);

//		obj.c

void	cylinder_matrix(t_obj_matrix m, t_obj *obj);
void	cone_matrix(t_obj_matrix m, t_obj *obj);
void	sphere_matrix(t_obj_matrix m, t_obj *obj);
void	plan_matrix(t_obj_matrix m, t_obj *obj);

#endif
