/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:49:48 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/20 17:55:36 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H 

# include "data_struct.h"
# include "matrix.h"
# include "transformations.h"
# include "test.h"
# include "vector.h"

void	world_to_camera(t_rt *rt);
void	get_matrix_align_v1_v2(t_u m[4][4], t_tuple v1, t_tuple v2);
t_bool	check_vector_opposite(t_tuple v1, t_tuple v2);
void	fill_obj(t_rt *rt);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);

#endif 
