/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bek <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:09:36 by bek               #+#    #+#             */
/*   Updated: 2022/10/26 12:59:52 by rmorel           ###   ########.fr       */
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
void	world_to_camera2(t_rt *rt);
t_bool	check_vector_opposite(t_tuple v1, t_tuple v2);
void	fill_obj(t_rt *rt);
void	fill_obj2(t_rt *rt);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);

//		rendering.c

void	print_axis(t_rt *rt);

//		obj.c

void	transform_obj_wtoo(t_rt *rt);

#endif
