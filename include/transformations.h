/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:48:18 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/14 14:00:26 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H 

# include <math.h>
# include "data_struct.h"
# include "matrix.h"

void	trans_matrix_4(t_u m[4][4], t_u x, t_u y, t_u z);
void	scale_matrix_4(t_u m[4][4], t_u x, t_u y, t_u z);
void	rot_x_matrix_4(t_u m[4][4], t_u angle);
void	rot_y_matrix_4(t_u m[4][4], t_u angle);
void	rot_z_matrix_4(t_u m[4][4], t_u angle);
void	shearing_matrix_4(t_u m[4][4], t_u shearing[6]);
void	mult_tuple_matrix_4(t_tuple *new, t_u m[4][4], t_tuple t);


#endif 
